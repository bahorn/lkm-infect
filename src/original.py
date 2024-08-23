#!/usr/bin/env python3
import sys
import lief
binary = lief.parse(sys.argv[1])

init_module = None

for symbol in binary.symbols:
    if symbol.name != 'init_module':
        continue
    init_module = symbol
    break

for symbol in binary.symbols:
    if symbol.name == 'init_module':
        continue

    if symbol.value != init_module.value:
        continue

    print(symbol.name)
    break
