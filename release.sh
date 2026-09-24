#!/bin/bash
set -e

VERSION=$1
NOTES=$2
BASEROM="/mnt/c/Users/Jared/Desktop/Pokemon - Emerald Version (USA, Europe).gba"

if [ -z "$VERSION" ] || [ -z "$NOTES" ]; then
  echo "Usage: ./release.sh v1.0.2 \"Fixed typo in Rosebank dialogue\""
  exit 1
fi

echo "Building..."
make -j$(nproc) pokeemerald-release.gba

echo "Creating patch..."
flips --create --bps "$BASEROM" pokeemerald-release.gba pokemon_crestfall.bps

echo "Verifying round-trip..."
flips --apply pokemon_crestfall.bps "$BASEROM" test_output.gba
if diff -q pokeemerald-release.gba test_output.gba > /dev/null; then
  echo "MATCH - patch verified"
  rm test_output.gba
else
  echo "MISMATCH - build is not reproducible, aborting release"
  exit 1
fi

echo "Publishing $VERSION to GitHub..."
gh release create "$VERSION" pokemon_crestfall.bps --title "Pokémon Crestfall $VERSION" --notes "$NOTES"
