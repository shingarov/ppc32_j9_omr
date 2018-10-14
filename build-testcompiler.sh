#!/bin/bash

#
# Taken from the version for linux_arm_linaro,
# manually tweaked for ppc32.
#

if [ -z "$GCCPREFIX" ] ; then
        echo "Please source ./env-arm or whatever"
        exit 1;
fi

export OMR_FEATURES="--enable-debug \
    --disable-auto-build-flag \
    OMRGLUE=./example/glue \
    --enable-OMR_JIT \
    --disable-OMR_GC \
    --disable-OMR_EXAMPLE \
    --enable-OMR_TEST_COMPILER \
    --enable-OMRTHREAD_LIB_UNIX"

bash ./configure \
    --build x86_64-unknown-linux-gnu \
    --host powerpc-linux-gnu \
    --target powerpc-linux-gnu \
    SPEC=linux_powerpc_gnu \
    --enable-OMR_ARCH_POWER \
    --disable-OMR_ENV_LITTLE_ENDIAN \
    --disable-OMR_ENV_DATA64 \
    $OMR_FEATURES \
    libprefix=lib \
    exeext= \
    solibext=.so \
    arlibext=.a \
    objext=.o \
    OMR_TOOLCHAIN=gcc \
    AS=$GCCPREFIX-as \
    CC=$GCCPREFIX-gcc \
    CXX=$GCCPREFIX-g++ \
    AR=$GCCPREFIX-ar \
    OBJCOPY=$GCCPREFIX-objcopy \
    'CCLINKEXE=$(CC)' \
    'CCLINKSHARED=$(CC)' \
    'CXXLINKEXE=$(CXX)' \
    'CXXLINKSHARED=$(CC)' \
    OMR_HOST_OS=linux \
    OMR_HOST_ARCH=ppc \
    OMR_HOST_DATASIZE=32 \
    OMR_TARGET_DATASIZE=32 \
    --disable-warnings-as-errors \
    OMR_TREAT_WARNINGS_AS_ERRORS=0

echo "Now do make."

