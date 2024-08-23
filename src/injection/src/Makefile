TARGET = injection-payload
ccflags-y := -std=gnu99 \
	-Wno-declaration-after-statement \
	-DSYMBOL_NAME=$(SYMBOL_NAME) \
	-DOUR_MAIN=$(OUR_MAIN)

obj-m += $(TARGET).o

$(TARGET)-m += ./injection.o
