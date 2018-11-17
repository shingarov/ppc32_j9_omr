###############################################################################
# Copyright (c) 2018, 2018 IBM Corp. and others
#
# This program and the accompanying materials are made available under
# the terms of the Eclipse Public License 2.0 which accompanies this
# distribution and is available at http://eclipse.org/legal/epl-2.0
# or the Apache License, Version 2.0 which accompanies this distribution
# and is available at https://www.apache.org/licenses/LICENSE-2.0.
#
# This Source Code may also be made available under the following Secondary
# Licenses when the conditions for such availability set forth in the
# Eclipse Public License, v. 2.0 are satisfied: GNU General Public License,
# version 2 with the GNU Classpath Exception [1] and GNU General Public
# License, version 2 with the OpenJDK Assembly Exception [2].
#
# [1] https://www.gnu.org/software/classpath/license.html
# [2] http://openjdk.java.net/legal/assembly-exception.html
#
# SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
###############################################################################
include $(CONFIG_INCL_DIR)/configure_common.mk

# target
TARGET=riscv64
OS=linux
TOOLCHAIN=gcc
CHOST=riscv64-linux-gnu

OMR_FEATURES = \
	--enable-debug   \
	--disable-auto-build-flag \
	--disable-OMR_GC \
	--enable-OMR_JIT \
	--disable-OMR_EXAMPLE \
	--enable-OMR_TEST_COMPILER  \
	--enable-OMRTHREAD_LIB_UNIX \
	--disable-DDR

TARGET_DEFINITIONS = \
	--build=riscv64-linux-gnu   \
	--host=riscv64-linux-gnu    \
	--target=riscv64-linux-gnu  \
	--enable-OMR_ARCH_RISCV64 \
	--enable-OMR_ENV_LITTLE_ENDIAN \
	--enable-OMR_ENV_DATA64 \
	--disable-warnings-as-errors \
	'CC=gcc' \
	'CXX=g++' \
	'AR=ar' \
	'AS=as' \
	'LD=ld' \
	'OBJCOPY=objcopy' \
	'CCLINKEXE=$$(CC)' \
	'CCLINKSHARED=$$(CC)' \
	'CXXLINKEXE=$$(CXX)' \
	'CXXLINKSHARED=$$(CC)' \
	'OMR_HOST_OS=$(OS)' \
	'OMR_HOST_ARCH=$(TARGET)' \
	'OMR_TARGET_DATASIZE=64' \
	'OMR_TOOLCHAIN=$(TOOLCHAIN)' \
	'PLATFORM=$(TARGET)-$(OS)-$(TOOLCHAIN)' \
	'OMR_TREAT_WARNINGS_AS_ERRORS=0' \
	libprefix=lib exeext= solibext=.so arlibext=.a objext=.o


CONFIGURE_ARGS = $(OMR_FEATURES) $(TARGET_DEFINITIONS)
