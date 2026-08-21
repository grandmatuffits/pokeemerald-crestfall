#!/usr/bin/env python3
"""Enpale region-map builder. USAGE: python3 build_region_map.py map.png"""
import sys, os
from PIL import Image

DEST = "graphics/pokenav/region_map"
MAP_W, MAP_H = 28, 15
BUF_W, BUF_H = 64, 32
SHEET_W_TILES = 16
MAX_TILES = 192
WATER_INDEX = 133

def die(m): sys.exit("ERROR: " + m)
if len(sys.argv) != 2: die("usage: python3 build_region_map.py map.png")
src = sys.argv[1]
if not os.path.isdir(DEST): die(f"run from repo root (no {DEST})")

img = Image.open(src)
if img.mode != 'P': die(f"image must be INDEXED (mode P), got {img.mode}")
if img.size != (MAP_W*8, MAP_H*8): die(f"image must be {MAP_W*8}x{MAP_H*8}, got {img.size}")
palette = img.getpalette()
px = img.load()

def tile_key(cx, cy):
    return tuple(px[cx*8+x, cy*8+y] for y in range(8) for x in range(8))

unique = {}; tile_order = []; tilemap = []
for cy in range(MAP_H):
    for cx in range(MAP_W):
        k = tile_key(cx, cy)
        if k not in unique:
            unique[k] = len(tile_order); tile_order.append(k)
        tilemap.append(unique[k])

water_key = tuple([WATER_INDEX]*64)
if water_key not in unique:
    unique[water_key] = len(tile_order); tile_order.append(water_key)
pad_tile = unique[water_key]

if len(tile_order) > MAX_TILES:
    die(f"{len(tile_order)} unique tiles > {MAX_TILES}. Simplify art.")

sheet_h = max((len(tile_order)+SHEET_W_TILES-1)//SHEET_W_TILES, 12)
sheet = Image.new('P', (SHEET_W_TILES*8, sheet_h*8))
sheet.putpalette(palette)
sp = sheet.load()
for idx, key in enumerate(tile_order):
    tx, ty = idx % SHEET_W_TILES, idx // SHEET_W_TILES
    for i, v in enumerate(key):
        sp[tx*8 + i%8, ty*8 + i//8] = v
sheet.save(os.path.join(DEST, "map_kanto.png"))

buf = bytearray([pad_tile]) * (BUF_W*BUF_H)
for cy in range(MAP_H):
    for cx in range(MAP_W):
        buf[cy*BUF_W + cx] = tilemap[cy*MAP_W + cx]
open(os.path.join(DEST, "map_kanto.bin"), "wb").write(buf)

lines = ["JASC-PAL", "0100", "48"]
for i in range(112, 160):
    lines.append(f"{palette[i*3]} {palette[i*3+1]} {palette[i*3+2]}")
open(os.path.join(DEST, "map_kanto.pal"), "w").write("\r\n".join(lines) + "\r\n")

print(f"OK: {len(tile_order)} unique tiles (water pad tile = {pad_tile})")
print("Now run: make")
