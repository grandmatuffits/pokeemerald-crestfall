#!/usr/bin/env python3
# Run this from your pokeemerald-expansion directory:
# python3 apply_dex.py

species = [
    'ROWLET', 'DARTRIX', 'DECIDUEYE',
    'FENNEKIN', 'BRAIXEN', 'DELPHOX',
    'PIPLUP', 'PRINPLUP', 'EMPOLEON',
    'SENTRET', 'FURRET',
    'STARLY', 'STARAVIA', 'STARAPTOR',
    'WEEDLE', 'KAKUNA', 'BEEDRILL',
    'PICHU', 'PIKACHU', 'RAICHU',
    'SANDSHREW', 'SANDSLASH',
    'NIDORAN_F', 'NIDORINA', 'NIDOQUEEN',
    'NIDORAN_M', 'NIDORINO', 'NIDOKING',
    'VENIPEDE', 'WHIRLIPEDE', 'SCOLIPEDE',
    'CLEFFA', 'CLEFAIRY', 'CLEFABLE',
    'VULPIX', 'NINETALES',
    'MAREEP', 'FLAAFFY', 'AMPHAROS',
    'YANMA', 'YANMEGA',
    'ODDISH', 'GLOOM', 'VILEPLUME', 'BELLOSSOM',
    'DUCKLETT', 'SWANNA',
    'DIGLETT', 'DUGTRIO',
    'GROWLITHE', 'ARCANINE',
    'WOOBAT', 'SWOOBAT',
    'ABRA', 'KADABRA', 'ALAKAZAM',
    'TENTACOOL', 'TENTACRUEL',
    'ROGGENROLA', 'BOLDORE', 'GIGALITH',
    'MAGNEMITE', 'MAGNETON', 'MAGNEZONE',
    'GRIMER', 'MUK',
    'SHELLDER', 'CLOYSTER',
    'GASTLY', 'HAUNTER', 'GENGAR',
    'VOLTORB', 'ELECTRODE',
    'EXEGGCUTE', 'EXEGGUTOR',
    'AZURILL', 'MARILL', 'AZUMARILL',
    'TANGELA', 'TANGROWTH',
    'ARON', 'LAIRON', 'AGGRON',
    'HORSEA', 'SEADRA', 'KINGDRA',
    'STARYU', 'STARMIE',
    'SCYTHER', 'SCIZOR',
    'PINSIR',
    'TAUROS', 'MILTANK',
    'MAGIKARP', 'GYARADOS',
    'TOGEPI', 'TOGETIC', 'TOGEKISS',
    'WOOPER', 'QUAGSIRE',
    'MURKROW', 'HONCHKROW',
    'MISDREAVUS', 'MISMAGIUS',
    'WYNAUT', 'WOBBUFFET',
    'SWIRLIX', 'SLURPUFF',
    'PINECO', 'FORRETRESS',
    'GLIGAR', 'GLISCOR',
    'HERACROSS',
    'SNEASEL', 'WEAVILE',
    'SWINUB', 'PILOSWINE', 'MAMOSWINE',
    'SKARMORY',
    'HOUNDOUR', 'HOUNDOOM',
    'RALTS', 'KIRLIA', 'GARDEVOIR', 'GALLADE',
    'SHROOMISH', 'BRELOOM',
    'NINCADA', 'NINJASK', 'SHEDINJA',
    'SABLEYE', 'MAWILE',
    'SANDYGAST', 'PALOSSAND',
    'MEDITITE', 'MEDICHAM',
    'BUDEW', 'ROSELIA', 'ROSERADE',
    'CARVANHA', 'SHARPEDO',
    'NUMEL', 'CAMERUPT',
    'TORKOAL',
    'TRAPINCH', 'VIBRAVA', 'FLYGON',
    'BALTOY', 'CLAYDOL',
    'FEEBAS', 'MILOTIC',
    'SHUPPET', 'BANETTE',
    'SNORUNT', 'GLALIE', 'FROSLASS',
    'RIOLU', 'LUCARIO',
    'CROAGUNK', 'TOXICROAK',
    'MUNNA', 'MUSHARNA',
    'DRILBUR', 'EXCADRILL',
    'COTTONEE', 'WHIMSICOTT',
    'DWEBBLE', 'CRUSTLE',
    'ZORUA', 'ZOROARK',
    'EMOLGA',
    'FOONGUS', 'AMOONGUSS',
    'FRILLISH', 'JELLICENT',
    'JOLTIK', 'GALVANTULA',
    'FERROSEED', 'FERROTHORN',
    'LITWICK', 'LAMPENT', 'CHANDELURE',
    'MIENFOO', 'MIENSHAO',
    'PAWNIARD', 'BISHARP',
    'VULLABY', 'MANDIBUZZ',
    'RHYHORN', 'RHYDON', 'RHYPERIOR',
    'DURANT',
    'ESPURR', 'MEOWSTIC',
    'HONEDGE', 'DOUBLADE', 'AEGISLASH',
    'HAPPINY', 'CHANSEY', 'BLISSEY',
    'SMOOCHUM', 'JYNX',
    'EEVEE', 'VAPOREON', 'JOLTEON', 'FLAREON',
    'ESPEON', 'UMBREON', 'LEAFEON', 'GLACEON', 'SYLVEON',
    'HAWLUCHA',
    'MUNCHLAX', 'SNORLAX',
    'MAREANIE', 'TOXAPEX',
    'SALANDIT', 'SALAZZLE',
    'WIMPOD', 'GOLISOPOD',
    'DITTO',
    'PORYGON', 'PORYGON2', 'PORYGON_Z',
    'MIMIKYU',
    'DRATINI', 'DRAGONAIR', 'DRAGONITE',
    'LARVITAR', 'PUPITAR', 'TYRANITAR',
    'BAGON', 'SHELGON', 'SALAMENCE',
    'BELDUM', 'METANG', 'METAGROSS',
    'GIBLE', 'GABITE', 'GARCHOMP',
    'AXEW', 'FRAXURE', 'HAXORUS',
    'DEINO', 'ZWEILOUS', 'HYDREIGON',
    'REGIROCK', 'REGICE', 'REGISTEEL',
    'REGIGIGAS',
]

# Build new macro
macro_lines = ['#define FOREACH_SPECIES_IN_HOENN_DEX_ORDER(F) \\']
for i, s in enumerate(species):
    if i < len(species) - 1:
        macro_lines.append(f'    F({s}) \\')
    else:
        macro_lines.append(f'    F({s})')
new_macro = '\n'.join(macro_lines)

# Read the file
with open('include/constants/pokedex.h', 'r') as f:
    content = f.read()

# Find start and end of old macro
start_marker = '#define FOREACH_SPECIES_IN_HOENN_DEX_ORDER(F) \\'
end_marker = '// Hoenn Pokédex order'

start_idx = content.index(start_marker)
end_idx = content.index(end_marker)

# Replace
new_content = content[:start_idx] + new_macro + '\n' + content[end_idx:]

# Update HOENN_DEX_COUNT to use REGIGIGAS as last entry
new_content = new_content.replace(
    '#define HOENN_DEX_COUNT (HOENN_DEX_DEOXYS + 1)',
    '#define HOENN_DEX_COUNT (HOENN_DEX_REGIGIGAS + 1)'
)

with open('include/constants/pokedex.h', 'w') as f:
    f.write(new_content)

print(f"Done! Regional dex set to {len(species)} Pokemon.")
print(f"Last entry: {species[-1]}")
