import json, re, shutil

LAYOUT = "src/data/region_map/region_map_layout_kanto.h"
JSON = "src/data/region_map/region_map_sections.json"
WANT = {
    "MAPSEC_DIGLETTS_CAVE":       (22, 3),  # Belmont Cave
    "MAPSEC_ROUTE_10_POKECENTER": (22, 4),  # Belmont Town
    "MAPSEC_ROCKET_HIDEOUT":      (22, 5),  # Belmont Park
}

shutil.copy(JSON, JSON + ".bak_belmont")
data = json.load(open(JSON))
secs = data["map_sections"] if isinstance(data, dict) else data
for s in secs:
    if s.get("id") in WANT:
        s["x"], s["y"] = WANT[s["id"]]
        s["width"], s["height"] = 1, 1
        print(f"JSON: {s['id']} -> {WANT[s['id']]}")
with open(JSON, "w") as f:
    json.dump(data, f, indent=2, ensure_ascii=False)
    f.write("\n")

shutil.copy(LAYOUT, LAYOUT + ".bak_belmont")
src = open(LAYOUT).read()
start = src.index("sRegionMapSections_Kanto")
rows = list(re.finditer(r"\{([^{}]*)\}", src[start:]))[:17]

edits = []
for tok, (x, y) in WANT.items():
    row = rows[y]
    toks = list(re.finditer(r"MAPSEC_\w+", row.group(1)))
    old = toks[x]
    abs_s = start + row.start(1) + old.start()
    abs_e = start + row.start(1) + old.end()
    if old.group() != tok:
        print(f"GRID: ({x},{y}) {old.group()} -> {tok}")
    else:
        print(f"GRID: ({x},{y}) already {tok}")
    edits.append((abs_s, abs_e, tok))

for s, e, tok in sorted(edits, reverse=True):
    src = src[:s] + tok + src[e:]
open(LAYOUT, "w").write(src)
