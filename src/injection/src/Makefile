TARGET = injection-payload
ccflags-y := -std=gnu99 \
	-Wno-declaration-after-statement \
	-DSYMBOL_NAME=$(SYMBOL_NAME)

obj-m += $(TARGET).o

$(TARGET)-m += ./injection.o
