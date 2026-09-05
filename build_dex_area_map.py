import sys
from PIL import Image

SRC   = sys.argv[1] if len(sys.argv) > 1 else "test_map6_clean.png"
MAP_W, MAP_H = 29, 17
STRIDE = 32
BUF_H  = 32
SHEET_W = 16
MAX_TILES = 250

im = Image.open(SRC)
assert im.mode == "P", f"need indexed PNG, got {im.mode}"
assert im.size == (MAP_W*8, MAP_H*8), f"expected {MAP_W*8}x{MAP_H*8}, got {im.size}"
src_pal = im.getpalette()
px = im.load()

tiles, index_of, tilemap = [], {}, []
for ty in range(MAP_H):
    for tx in range(MAP_W):
        key = tuple(px[tx*8+x, ty*8+y] for y in range(8) for x in range(8))
        if key not in index_of:
            index_of[key] = len(tiles)
            tiles.append(key)
        tilemap.append(index_of[key])

if len(tiles) > MAX_TILES:
    sys.exit(f"ABORT: {len(tiles)} unique tiles, over {MAX_TILES}")

blank = tuple([0]*64)
if blank not in index_of:
    tiles.insert(0, blank)
    tilemap = [i+1 for i in tilemap]
elif index_of[blank] != 0:
    b = index_of[blank]
    tiles[0], tiles[b] = tiles[b], tiles[0]
    tilemap = [0 if i == b else (b if i == 0 else i) for i in tilemap]

rows = (len(tiles) + SHEET_W - 1) // SHEET_W
sheet = Image.new("P", (SHEET_W*8, rows*8), 0)
sheet.putpalette(src_pal)
sp = sheet.load()
for i, t in enumerate(tiles):
    ox, oy = (i % SHEET_W)*8, (i // SHEET_W)*8
    for y in range(8):
        for x in range(8):
            sp[ox+x, oy+y] = t[y*8+x]
sheet.save("graphics/pokedex/region_map_kanto.png")

buf = bytearray(STRIDE*BUF_H*2)
for ty in range(MAP_H):
    for tx in range(MAP_W):
        e = tilemap[ty*MAP_W + tx]
        o = (ty*STRIDE + tx)*2
        buf[o]   = e & 0xFF
        buf[o+1] = (e >> 8) & 0xFF
open("graphics/pokedex/region_map_kanto.bin","wb").write(buf)

with open("graphics/pokedex/region_map_kanto.pal","w") as f:
    f.write("JASC-PAL\n0100\n48\n")
    for i in range(112, 160):
        r,g,b = src_pal[i*3:i*3+3]
        f.write(f"{r} {g} {b}\n")

print(f"{len(tiles)} unique tiles, sheet {SHEET_W*8}x{rows*8}, map {MAP_W}x{MAP_H} in {STRIDE}x{BUF_H} buffer")
