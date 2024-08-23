build:
	make -C ./base/
	make -C ./injection/
	objcopy --globalize-symbol=init ./base/src/test-mod.ko /workdir/artifacts/test-mod.ko
	cp ./injection/src/injection.o /workdir/artifacts/injection.o
	ld -r /workdir/artifacts/test-mod.ko \
		/workdir/artifacts/injection.o \
		-o /workdir/artifacts/together.ko
	python3 ./patcher.py /workdir/artifacts/together.ko /workdir/artifacts/infected.ko
