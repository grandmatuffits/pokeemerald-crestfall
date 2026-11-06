-- crestfall_net.lua
-- Bridge between Pokemon Crestfall's NetMailbox (EWRAM) and relay.js.
-- Load in mGBA: Tools > Scripting... > File > Load script...

local HOST = "100.87.131.115"   -- relay address
local PORT = 9000
local ROOM = ""          -- leave empty: the co-op NPC asks for a room code in-game

-- Must match include/net_link.h
local SIG          = "CRSTNET1"
local HOST_MAGIC   = 0x4E455431
local OFF_MAGIC    = 0x008
local OFF_OUTLEN   = 0x00C
local OFF_INLEN    = 0x00E
local OFF_OUTREADY = 0x010
local OFF_INREADY  = 0x011
local OFF_STATUS   = 0x012
local OFF_PID      = 0x013
local OFF_OUT      = 0x014
local OFF_IN       = 0x124
local OFF_HEARTBEAT = 0x234
local OFF_ROOMSERIAL = 0x235
local OFF_ROOMCODE = 0x236

local STATUS_NONE, STATUS_ALONE, STATUS_PARTNERED = 0, 1, 2

local EWRAM, EWRAM_SIZE = 0x02000000, 0x40000

local base = nil          -- mailbox address once found
local sock = nil
local rx = ""             -- unparsed bytes from the relay
local inbox = {}          -- payloads waiting for the game to take them
local status = STATUS_NONE
local playerId = 0
local scanTimer = 0
local retryTimer = 0
local heartbeat = 0
local refusedReason = nil
local currentRoom = (ROOM ~= "") and ROOM or nil
local lastRoomSerial = 0

local function log(s) console:log("[crestfall-net] " .. s) end

-- Build fingerprint: CRC32 of the loaded ROM, so the relay never pairs two different builds
local buildId = nil
local function getBuildId()
  if buildId then return buildId end
  local ok, v = pcall(function() return emu:checksum(C.CHECKSUM.CRC32) end)
  if ok and type(v) == "string" and #v > 0 then
    local h = {}
    for i = 1, #v do h[#h + 1] = string.format("%02x", v:byte(i)) end
    buildId = table.concat(h)
  elseif ok and type(v) == "number" then
    buildId = string.format("%08x", v)
  else
    buildId = ""   -- can't tell; relay treats it as unknown
  end
  log("game build " .. (buildId ~= "" and buildId or "unknown"))
  return buildId
end

local function u16be(n) return string.char((n >> 8) & 0xFF, n & 0xFF) end

local function sendFrame(payload)
  if sock then sock:send(u16be(#payload) .. payload) end
end

local function findMailbox()
  local mem = emu:readRange(EWRAM, EWRAM_SIZE)
  local pos = mem:find(SIG, 1, true)
  if pos then
    base = EWRAM + pos - 1
    log(string.format("mailbox found at 0x%08X", base))
    if not currentRoom then log("waiting for a room code (talk to the co-op NPC)") end
  end
end

local function onFrame(p)
  local t = p:sub(1, 1)
  if t == "I" then
    playerId = p:byte(2)
    log("joined room '" .. currentRoom .. "' as player " .. playerId)
  elseif t == "P" then
    status = (p:byte(2) == 1) and STATUS_PARTNERED or STATUS_ALONE
    log(status == STATUS_PARTNERED and "partner connected" or "waiting for partner...")
  elseif t == "D" then
    table.insert(inbox, p:sub(2))
  elseif t == "X" then
    refusedReason = p:sub(2)
    log("relay refused: " .. refusedReason)
  end
end

local function parse()
  while #rx >= 2 do
    local len = (rx:byte(1) << 8) | rx:byte(2)
    if #rx < 2 + len then break end
    onFrame(rx:sub(3, 2 + len))
    rx = rx:sub(3 + len)
  end
end

local function disconnect(reason)
  log(reason)
  sock = nil
  rx = ""
  inbox = {}
  status = STATUS_NONE
  retryTimer = refusedReason and 1800 or 300  -- wait 30s after a refusal, 5s otherwise
  refusedReason = nil
end

local function joinRoom()
  local b = getBuildId()
  sendFrame("J" .. currentRoom .. (b ~= "" and ("|" .. b) or ""))
end

local function connect()
  local s, err = socket.connect(HOST, PORT)
  if not s then
    log("can't reach relay at " .. HOST .. ":" .. PORT .. " (" .. tostring(err) .. "), retrying in 5s")
    retryTimer = 300
    return
  end
  sock = s
  status = STATUS_ALONE
  joinRoom()
  log("connected to relay")
end

callbacks:add("frame", function()
  -- 1. Find the mailbox (rescans after a ROM change / reset wipes it)
  if not base then
    scanTimer = scanTimer - 1
    if scanTimer <= 0 then
      scanTimer = 60
      findMailbox()
    end
    return
  end
  if emu:readRange(base, #SIG) ~= SIG then
    base = nil
    buildId = nil
    return
  end

  -- 2a. Room code entered at the co-op NPC
  local serial = emu:read8(base + OFF_ROOMSERIAL)
  if serial ~= lastRoomSerial then
    lastRoomSerial = serial
    if serial ~= 0 then
      local code = emu:readRange(base + OFF_ROOMCODE, 16):match("^[%w_-]+")
      if code and code ~= currentRoom then
        currentRoom = code
        log("room code: " .. code)
        if sock then
          status = STATUS_ALONE
          inbox = {}
          joinRoom()
        else
          retryTimer = 0
        end
      end
    end
  end

  -- 2. Relay connection (only once there's a room to join)
  if not sock and currentRoom then
    retryTimer = retryTimer - 1
    if retryTimer <= 0 then connect() end
  end

  -- 2b. Pull anything the relay sent (polled every frame, no callbacks)
  if sock then
    local closed = false
    local ok, err = pcall(function()
      while sock:hasdata() do
        local data = sock:receive(4096)
        if not data or #data == 0 then closed = true; break end  -- readable but empty = closed
        rx = rx .. data
      end
    end)
    if not ok then
      disconnect("relay read failed (" .. tostring(err) .. "), retrying")
    else
      parse()
      if closed then disconnect("relay closed the connection, retrying") end
    end
  end

  -- 3. Keep host state written (a soft reset re-runs NetLink_Init and clears it)
  emu:write32(base + OFF_MAGIC, HOST_MAGIC)
  emu:write8(base + OFF_STATUS, status)
  emu:write8(base + OFF_PID, playerId)
  heartbeat = (heartbeat + 1) & 0xFF
  emu:write8(base + OFF_HEARTBEAT, heartbeat)  -- lets the game notice if this script stops

  -- 4. Outgoing: game -> relay
  if emu:read8(base + OFF_OUTREADY) == 1 then
    local len = emu:read16(base + OFF_OUTLEN)
    if sock and len > 0 then
      sendFrame("D" .. emu:readRange(base + OFF_OUT, len))
    end
    emu:write8(base + OFF_OUTREADY, 0)
  end

  -- 5. Incoming: relay -> game, one message at a time
  if #inbox > 0 and emu:read8(base + OFF_INREADY) == 0 then
    local p = table.remove(inbox, 1)
    for i = 1, #p do
      emu:write8(base + OFF_IN + i - 1, p:byte(i))
    end
    emu:write16(base + OFF_INLEN, #p)
    emu:write8(base + OFF_INREADY, 1)
  end
end)

log("loaded, looking for Crestfall's mailbox...")
