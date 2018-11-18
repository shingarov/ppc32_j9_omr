###############################################################################
# Copyright (c) 2016, 2017 IBM Corp. and others
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

JIT_PRODUCT_BACKEND_SOURCES+=\
    $(JIT_OMR_DIRTY_DIR)/r/codegen/BinaryEvaluator.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/ControlFlowEvaluator.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/FPTreeEvaluator.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/GenerateInstructions.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/OMRMemoryReference.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/OpBinary.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/OpProperties.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/PPCAOTRelocation.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/PPCBinaryEncoding.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/OMRCodeGenerator.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/OMRInstruction.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/PPCDebug.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/PPCHelperCallSnippet.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/PPCInstruction.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/OMRLinkage.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/PPCSystemLinkage.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/OMRMachine.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/PPCOutOfLineCodeSection.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/OMRRealRegister.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/OMRRegisterDependency.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/OMRSnippet.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/PPCTableOfConstants.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/OMRTreeEvaluator.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/TreeEvaluatorVMX.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/UnaryEvaluator.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/OMRConstantDataSnippet.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/codegen/OMRRegisterIterator.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/env/OMRCPU.cpp

JIT_PRODUCT_SOURCE_FILES+=\
    $(JIT_PRODUCT_DIR)/r/codegen/Evaluator.cpp \
    $(JIT_OMR_DIRTY_DIR)/r/env/OMRDebugEnv.cpp
