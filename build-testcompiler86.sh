#!/bin/bash

#
# I first originally copied build-testcompiler.sh,
# but modified it for AMD64.
#

export OMR_FEATURES="--enable-debug \
    --disable-auto-build-flag \
    OMRGLUE=./example/glue \
    --enable-OMR_JIT \
    --disable-OMR_GC \
    --disable-OMR_EXAMPLE \
    --enable-OMR_TEST_COMPILER \
    --enable-OMRTHREAD_LIB_UNIX"

bash ./configure \
    SPEC=linux_x86-64_gnu \
    --enable-OMR_ARCH_X86 \
    --enable-OMR_ENV_LITTLE_ENDIAN \
    --enable-OMR_ENV_DATA64 \
    $OMR_FEATURES \
    libprefix=lib \
    exeext= \
    solibext=.so \
    arlibext=.a \
    objext=.o \
    OMR_TOOLCHAIN=gcc \
    AS=as \
    CC=gcc \
    CXX=g++ \
    AR=ar \
    OBJCOPY=objcopy \
    'CCLINKEXE=$(CC)' \
    'CCLINKSHARED=$(CC)' \
    'CXXLINKEXE=$(CXX)' \
    'CXXLINKSHARED=$(CC)' \
    OMR_HOST_OS=linux \
    OMR_HOST_ARCH=x86 \
    OMR_HOST_DATASIZE=64 \
    OMR_TARGET_DATASIZE=64 \
    --disable-warnings-as-errors \
    OMR_TREAT_WARNINGS_AS_ERRORS=0

echo "Now do make."

