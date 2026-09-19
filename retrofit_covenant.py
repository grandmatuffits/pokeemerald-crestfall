#!/usr/bin/env python3
"""
Retrofit Team Covenant Acolyte teams onto the approved 22-family list.

- Levels are NEVER changed.
- Only species on the approved list are used (all verified dex-legal vs the Enpale 300).
- Replacements are chosen per-slot for type/role similarity to the original mon.
- Ferrus (Covenant Elder) is deliberately left alone.
- Abban / Serai / Castor are restricted AND renamed to "Acolyte".
- Bell Tower (Lv72-77 postgame) uses fully-evolved picks only.

Usage:
    python3 retrofit_covenant.py            # dry run, prints the diff
    python3 retrofit_covenant.py --write    # applies changes in place
"""

import re
import sys
import shutil

PATH = 'src/data/trainers.party'

ALLOWED = set("""
Sentret Furret Starly Staravia Staraptor Pichu Pikachu Raichu Cleffa Clefairy Clefable
Vulpix Ninetales Mareep Flaaffy Ampharos Azurill Marill Azumarill Woobat Swoobat
Togepi Togetic Togekiss Swirlix Slurpuff Swinub Piloswine Mamoswine Ralts Kirlia
Gardevoir Gallade Mawile Carbink Budew Roselia Roserade Feebas Milotic Cubchoo Beartic
Cottonee Whimsicott Stufful Bewear Espurr Meowstic Baltoy Claydol Shuppet Banette
""".split())

# Trainers to rename to "Acolyte" (non-Elder named Covenant members)
RENAME_TO_ACOLYTE = {
    'TRAINER_COVENANT_ABBAN',
    'TRAINER_COVENANT_SERAI',
    'TRAINER_COVENANT_CASTOR',
}

# Explicit per-trainer species replacements: {trainer_id: {old_species: new_species}}
# Chosen for type / role / flavour similarity to what was there before.
REPLACEMENTS = {
    # ---- prologue grunts (Lv10-12) ----
    'TRAINER_COVENANT_GRUNT_1': {'Pineco': 'Mawile'},          # defensive Steel -> Steel/Fairy

    # ---- Lenox (Lv18-20) ----
    'TRAINER_LENOX_ACOLYTE_1': {'Happiny': 'Clefairy',         # baby Normal -> Fairy
                                'Exeggcute': 'Roselia'},       # Grass/Psychic -> Grass/Poison
    'TRAINER_LENOX_ACOLYTE_2': {'Horsea': 'Marill'},           # Water -> Water
    'TRAINER_LENOX_ACOLYTE_3': {'Tangela': 'Cottonee',         # Grass -> Grass/Fairy
                                'Grimer': 'Budew'},            # Poison -> Grass/Poison
    'TRAINER_LENOX_ACOLYTE_4': {'Misdreavus': 'Shuppet'},      # Ghost -> Ghost

    # ---- Wallar Marshlands (Lv25-30) ----
    'TRAINER_WALLAR_ACOLYTE_1': {'Beedrill': 'Roselia',        # Bug/Poison -> Grass/Poison
                                 'Grimer': 'Shuppet'},         # Poison -> Ghost
    'TRAINER_WALLAR_ACOLYTE_2': {'Aron': 'Mawile'},            # Steel/Rock -> Steel/Fairy
    'TRAINER_WALLAR_ACOLYTE_4': {'Snorunt': 'Swinub',          # Ice -> Ice/Ground
                                 'Smoochum': 'Kirlia'},        # Ice/Psychic -> Psychic/Fairy
    'TRAINER_WALLAR_ACOLYTE_5': {'Vileplume': 'Roserade'},     # Grass/Poison -> Grass/Poison
    'TRAINER_WALLAR_ACOLYTE_6': {'Jolteon': 'Ampharos'},       # Electric ace -> Electric ace
    'TRAINER_WALLAR_ACOLYTE_7': {'Sandygast': 'Baltoy',        # Ghost/Ground -> Ground/Psychic
                                 'Haunter': 'Shuppet'},        # Ghost -> Ghost
    'TRAINER_WALLAR_ACOLYTE_8': {'Arcanine': 'Ninetales'},     # Fire canine -> Fire canine
    'TRAINER_WALLAR_ACOLYTE_9': {'Gyarados': 'Milotic'},       # Magikarp payoff -> Feebas payoff

    # ---- named Covenant crew (Lv27-32) ----
    'TRAINER_COVENANT_PIA':    {'Ducklett': 'Marill',          # Water/Flying -> Water
                                'Beedrill': 'Roselia'},        # Bug/Poison -> Grass/Poison
    'TRAINER_COVENANT_CORVIN': {'Tentacool': 'Azumarill'},     # Water -> Water/Fairy
    'TRAINER_COVENANT_HOBB':   {'Magneton': 'Ampharos'},       # Electric/Steel -> Electric
    'TRAINER_COVENANT_VESNA':  {'Bellossom': 'Whimsicott'},    # dancer Grass -> Grass/Fairy
    'TRAINER_COVENANT_ODRIC':  {'Dratini': 'Feebas'},          # rare serpent -> rare serpent
    'TRAINER_COVENANT_THESSA': {'Murkrow': 'Staravia',         # Dark/Flying -> Normal/Flying
                                'Meditite': 'Stufful',         # Fighting -> Normal/Fighting
                                'Mareanie': 'Roselia'},        # Poison -> Grass/Poison
    'TRAINER_COVENANT_GRIEG':  {'Scyther': 'Swoobat'},         # fast Bug/Flying -> fast Psy/Flying
    'TRAINER_COVENANT_NOOR':   {'Trapinch': 'Baltoy'},         # Ground -> Ground/Psychic
    'TRAINER_COVENANT_ABBAN':  {'Dragonair': 'Milotic'},       # serpentine ace -> serpentine ace
    'TRAINER_COVENANT_SERAI':  {'Jynx': 'Meowstic'},           # Ice/Psychic -> Psychic
    'TRAINER_COVENANT_CASTOR': {'Lycanroc': 'Gallade'},        # physical ace -> physical ace

    # ---- Whitecaps (Lv31-36) ----
    'TRAINER_COVENANT_WC_1': {'Clobbopus': 'Bewear',           # Fighting -> Normal/Fighting
                              'Prinplup': 'Azumarill'},        # Water -> Water/Fairy
    'TRAINER_COVENANT_WC_2': {'Voltorb': 'Flaaffy'},           # Electric -> Electric
    'TRAINER_COVENANT_WC_4': {'Gligar': 'Swoobat'},            # Ground/Flying -> Psychic/Flying
    'TRAINER_COVENANT_WC_5': {'Munna': 'Meowstic'},            # Psychic -> Psychic
    'TRAINER_COVENANT_WC_6': {'Sableye': 'Mawile'},            # its literal counterpart
    'TRAINER_COVENANT_WC_7': {'Whirlipede': 'Roselia',         # Bug/Poison -> Grass/Poison
                              'Sandygast': 'Baltoy'},          # Ghost/Ground -> Ground/Psychic
    'TRAINER_COVENANT_WC_8': {'Gengar': 'Banette'},            # Ghost ace -> Ghost ace

    # ---- Bell Tower, postgame Lv72-77, fully evolved ----
    'TRAINER_ACOLYTE_BELL_TOWER_1': {'Houndoom': 'Ninetales'},   # Dark/Fire -> Fire
    'TRAINER_ACOLYTE_BELL_TOWER_4': {'Wigglytuff': 'Clefable'},  # Normal/Fairy -> Fairy
    'TRAINER_ACOLYTE_BELL_TOWER_5': {'Espeon': 'Gardevoir',      # paired duo -> paired duo
                                     'Umbreon': 'Gallade'},
}

HEADER_PREFIXES = (
    'Name:', 'Class:', 'Pic:', 'Gender:', 'Music:', 'Double', 'AI:', 'Level:',
    'Ability:', 'Nature:', 'IVs', 'EVs', 'Moves', 'Shiny', 'Friendship',
    'Ball', 'Happiness', 'Form', 'Tera', 'Item:',
)


def is_species_line(stripped):
    if not stripped or stripped.startswith('===') or stripped.startswith('-'):
        return False
    if stripped.startswith(HEADER_PREFIXES):
        return False
    species = stripped.split('@')[0].strip()
    return bool(re.match(r"^[A-Z][A-Za-z0-9'\-\.\u2640\u2642 ]*$", species))


def main():
    write = '--write' in sys.argv

    with open(PATH, encoding='utf-8') as f:
        text = f.read()

    blocks = re.split(r'(?m)^(?==== )', text)
    out_blocks = []
    diffs = []
    renames = []
    unmatched = []

    for block in blocks:
        if not block.startswith('==='):
            out_blocks.append(block)
            continue

        tid = block.split('===')[1].strip()
        repl = REPLACEMENTS.get(tid, {})
        needs_rename = tid in RENAME_TO_ACOLYTE

        if not repl and not needs_rename:
            out_blocks.append(block)
            continue

        used = set()
        new_lines = []
        for line in block.split('\n'):
            stripped = line.strip()

            if needs_rename and stripped.startswith('Name:'):
                old_name = stripped.split(':', 1)[1].strip()
                if old_name != 'Acolyte':
                    renames.append((tid, old_name, 'Acolyte'))
                new_lines.append('Name: Acolyte')
                continue

            if repl and is_species_line(stripped):
                species = stripped.split('@')[0].strip()
                if species in repl:
                    new_species = repl[species]
                    used.add(species)
                    diffs.append((tid, species, new_species))
                    new_lines.append(line.replace(species, new_species, 1))
                    continue

            new_lines.append(line)

        for old in repl:
            if old not in used:
                unmatched.append((tid, old))

        out_blocks.append('\n'.join(new_lines))

    print(f"=== SPECIES CHANGES ({len(diffs)}) ===")
    current = None
    for tid, old, new in diffs:
        if tid != current:
            print(f"\n{tid}")
            current = tid
        print(f"    {old:<12} -> {new}")

    print(f"\n=== RENAMES ({len(renames)}) ===")
    for tid, old, new in renames:
        print(f"    {tid}: {old} -> {new}")

    if unmatched:
        print(f"\n=== !! UNMATCHED RULES ({len(unmatched)}) - check these ===")
        for tid, old in unmatched:
            print(f"    {tid}: no '{old}' found in block")

    result = ''.join(out_blocks)

    # verify: no off-list species remain in any Acolyte-named block
    leftovers = []
    for block in re.split(r'(?m)^(?==== )', result):
        if not block.startswith('==='):
            continue
        tid = block.split('===')[1].strip()
        if not re.search(r'acolyte|covenant', tid, re.I):
            continue
        if 'ELDER' in tid.upper():
            continue
        for line in block.split('\n'):
            s = line.strip()
            if is_species_line(s):
                sp = s.split('@')[0].strip()
                if sp not in ALLOWED:
                    leftovers.append((tid, sp))

    print(f"\n=== REMAINING OFF-LIST (excluding Elder Ferrus): {len(leftovers)} ===")
    for tid, sp in leftovers:
        print(f"    {tid}: {sp}")

    if write:
        shutil.copy(PATH, PATH + '.bak_covenant')
        with open(PATH, 'w', encoding='utf-8') as f:
            f.write(result)
        print(f"\nWritten. Backup at {PATH}.bak_covenant")
    else:
        print("\n(dry run - rerun with --write to apply)")


if __name__ == '__main__':
    main()
