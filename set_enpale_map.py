#!/usr/bin/env python3
"""Set Enpale region-map positions + names on the KANTO MAPSEC ids. Run from repo root."""
import json, shutil, sys

PATH = "src/data/region_map/region_map_sections.json"

# Kanto MAPSEC id -> (Enpale name, x, y)   [x/y from the sketch, on the 28x15 grid]
ENPALE = {
    "MAPSEC_VERMILION_CITY":  ("Lenox Town",        4, 0),
    "MAPSEC_CERULEAN_CITY":   ("Veldtmoor City",    9, 0),
    "MAPSEC_INDIGO_PLATEAU":  ("Baynoe Town",      13, 2),
    "MAPSEC_SAFFRON_CITY":    ("Minsi City",       10, 2),
    "MAPSEC_CINNABAR_ISLAND": ("Miraveil Island",  23, 2),
    "MAPSEC_PEWTER_CITY":     ("Quarren Town",      4, 3),
    "MAPSEC_LAVENDER_TOWN":   ("Coppergate City",   6, 4),
    "MAPSEC_PALLET_TOWN":     ("Kinneret Town",    11, 4),
    "MAPSEC_CELADON_CITY":    ("Delmark City",     13, 5),
    "MAPSEC_FUCHSIA_CITY":    ("Rosebank Town",    17, 5),
    "MAPSEC_VIRIDIAN_CITY":   ("Valerytown",       15, 9),
}

d = json.load(open(PATH))
sections = {s["id"]: s for s in d["map_sections"]}

missing = [k for k in ENPALE if k not in sections]
if missing:
    sys.exit(f"ABORT - ids not found in JSON: {missing}")

shutil.copy(PATH, PATH + ".bak")

changes = []
for mid, (name, x, y) in ENPALE.items():
    s = sections[mid]
    before = (s.get("name"), s.get("x"), s.get("y"))
    s["name"], s["x"], s["y"] = name, x, y
    s.setdefault("width", 1)
    s.setdefault("height", 1)
    if before != (name, x, y):
        changes.append(f"  {mid:24} {str(before):34} -> {(name, x, y)}")

json.dump(d, open(PATH, "w"), indent=2)
open(PATH, "a").write("\n")

print(f"Updated {len(ENPALE)} Kanto sections (backup: {PATH}.bak)\n")
print("\n".join(changes))
