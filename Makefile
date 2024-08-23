KVERSION=6.8.0-41-generic
TESTHOST=a@192.168.122.201


build:
	./build-system/build.sh $(KVERSION)
	scp ./artifacts/infected.ko $(TESTHOST):~/


setup:
	docker build \
		--build-arg="KVERSION=$(KVERSION)" \
		-t bahorn/lkm-patch-build:$(KVERSION) \
		./build-system/
