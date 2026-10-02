#!/usr/bin/env python3
"""Resolve specific merge-conflict hunks by policy. Dry run unless --apply.
ours = your side (HEAD), theirs = upstream, both = ours then theirs.
Each file's hunk count must match, or the file is skipped untouched."""
import re, sys
APPLY = '--apply' in sys.argv
POLICY = {
    'README.md':                                   ['ours'],
    'data/maps/MauvilleCity_GameCorner/scripts.inc': ['ours'] * 4,
    'include/config/battle.h':                     ['ours'],
    'include/config/item.h':                       ['ours'] * 3,
    'include/script_pokemon_util.h':               ['both'],
    'src/data/script_menu.h':                      ['ours'],
    'src/trainer_hill.c':                          ['theirs'],
}
def resolve(text, pols):
    out, hunks, i = [], 0, 0
    lines = text.split('\n')
    while i < len(lines):
        if lines[i].startswith('<<<<<<< '):
            ours, theirs, j, side = [], [], i + 1, 0
            while not lines[j].startswith('>>>>>>> '):
                if lines[j] == '=======': side = 1
                else: (ours, theirs)[side].append(lines[j])
                j += 1
            p = pols[hunks]; hunks += 1
            out += ours if p == 'ours' else theirs if p == 'theirs' else ours + theirs
            i = j + 1
        else:
            out.append(lines[i]); i += 1
    return '\n'.join(out), hunks
for f, pols in POLICY.items():
    try: t = open(f, encoding='utf-8').read()
    except Exception as e: print('SKIP (cannot read)', f, e); continue
    n = len(re.findall(r'^<<<<<<< ', t, re.M))
    if n != len(pols): print('SKIP %s: found %d hunks, expected %d' % (f, n, len(pols))); continue
    new, _ = resolve(t, pols)
    if f == 'src/trainer_hill.c':
        new, k = re.subn(r'(sPrizeListAttract\[\]\s*=\s*\{)ITEM_TM_ATTRACT,', r'\1ITEM_TM_DAZZLING_GLEAM,', new)
        print('  trainer_hill Attract->Dazzling Gleam replacements:', k)
    print(('APPLY ' if APPLY else 'DRY   ') + f, pols)
    if APPLY: open(f, 'w', encoding='utf-8').write(new)
print('\nDone.' if APPLY else '\nDry run only. Re-run with --apply to write.')
