#!/usr/bin/env python3
import re, sys
APPLY = '--apply' in sys.argv
POLICY = {
    'include/battle.h':   ['theirs'],
    'src/battle_util.c':  ['theirs'],
    'src/main_menu.c':    ['theirs'],
    'src/strings.c':      ['ours'],
    'src/field_move.c':   ['theirs'],
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

HM_FUNC = '''static bool32 HasHMItemForFieldMove(enum FieldMove fieldMove)
{
    switch (fieldMove)
    {
    case FIELD_MOVE_ROCK_SMASH:
        return CheckBagHasItem(ITEM_HM_ROCK_SMASH, 1);
    case FIELD_MOVE_DIVE:
        return CheckBagHasItem(ITEM_HM_DIVE, 1);
    case FIELD_MOVE_WATERFALL:
        return CheckBagHasItem(ITEM_HM_WATERFALL, 1);
    default:
        return FALSE;
    }
}

'''
HM_ENTRY = '''    [HM_ITEM_UNLOCK] =
    {
        .isUnlockedFunc = HasHMItemForFieldMove,
        .lockedMessage = gText_CantUseUntilNewBadge,
    },
'''
def patch_field_move_c(t):
    notes = []
    if 'HM_ITEM_UNLOCK' in t: return t, ['field_move.c already patched']
    t, k = re.subn(r'(const struct FieldMoveUnlock gFieldMoveUnlocks)', HM_FUNC + r'\1', t, count=1); notes.append('func %d' % k)
    t, k = re.subn(r'(    \[BADGE_UNLOCK\] =\s*\{.*?\n    \},\n)', lambda m: m.group(1) + HM_ENTRY, t, count=1, flags=re.S); notes.append('table entry %d' % k)
    for mv in ('ROCK_SMASH', 'DIVE', 'WATERFALL'):
        pat = r'(\[FIELD_MOVE_%s\] =\s*\{.*?)\.unlockType = BADGE_UNLOCK,(.*?)        \.arg = [^\n]*\n(.*?\n    \},)' % mv
        t, k = re.subn(pat, r'\1.unlockType = HM_ITEM_UNLOCK,\2\3', t, count=1, flags=re.S); notes.append('%s %d' % (mv, k))
    if '#include "item.h"' not in t:
        t = t.replace('#include "global.h"\n', '#include "global.h"\n#include "item.h"\n', 1); notes.append('added item.h include')
    return t, notes
def patch_field_move_h(t):
    if 'HM_ITEM_UNLOCK' in t: return t, ['field_move.h already patched']
    t, k = re.subn(r'(    BADGE_UNLOCK,\n)', r'\1    HM_ITEM_UNLOCK,\n', t, count=1)
    return t, ['enum entry %d' % k]
def patch_battle_h(t):
    if 'SAFARI_ZONE_USE_FRLG_MECHANIC' in t: return t, ['define already present']
    t, k = re.subn(r'(    B_ACTION_NONE = 0xFF\n\};\n)', r'\1\n#define SAFARI_ZONE_USE_FRLG_MECHANIC   TRUE\n', t, count=1)
    return t, ['SAFARI define re-added %d' % k]

def run(f, pols):
    try: t = open(f, encoding='utf-8').read()
    except Exception as e: print('SKIP (cannot read)', f, e); return
    n = len(re.findall(r'^<<<<<<< ', t, re.M))
    if n != len(pols): print('SKIP %s: found %d hunks, expected %d' % (f, n, len(pols))); return
    new, _ = resolve(t, pols); notes = []
    if f == 'src/field_move.c': new, notes = patch_field_move_c(new)
    if f == 'include/battle.h': new, notes = patch_battle_h(new)
    print(('APPLY ' if APPLY else 'DRY   ') + f, pols, notes)
    if APPLY: open(f, 'w', encoding='utf-8').write(new)
for f, p in POLICY.items(): run(f, p)
try:
    h = open('include/field_move.h', encoding='utf-8').read()
    new, notes = patch_field_move_h(h)
    print(('APPLY ' if APPLY else 'DRY   ') + 'include/field_move.h', notes)
    if APPLY: open('include/field_move.h', 'w', encoding='utf-8').write(new)
except Exception as e: print('SKIP include/field_move.h', e)
print('\nDone.' if APPLY else '\nDry run only. Re-run with --apply to write.')
