#!/bin/sh
mkdir -p artifacts && \
    docker run \
        --rm \
        -v `pwd`/src:/build/src:ro \
        -v `pwd`/artifacts:/workdir/artifacts:rw \
        -e KVERSION=$1 \
        bahorn/lkm-patch-build:$1
