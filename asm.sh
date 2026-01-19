#!/usr/bin/env bash

set -e

FILE="$1"

if [ -z "$FILE" ]; then
  echo "usage: asm <name>"
  exit 1
fi

nasm -f elf64 "$FILE.asm" -o "$FILE.o"
ld "$FILE.o" -o "$FILE"
./"$FILE"
