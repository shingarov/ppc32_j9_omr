/*******************************************************************************
 * Copyright (c) 2000, 2016 IBM Corp. and others
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at http://eclipse.org/legal/epl-2.0
 * or the Apache License, Version 2.0 which accompanies this distribution
 * and is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following Secondary
 * Licenses when the conditions for such availability set forth in the
 * Eclipse Public License, v. 2.0 are satisfied: GNU General Public License,
 * version 2 with the GNU Classpath Exception [1] and GNU General Public
 * License, version 2 with the OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] http://openjdk.java.net/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/

#include "codegen/OMRLinkage.hpp"

#include <stddef.h>                            // for NULL
#include <stdint.h>                            // for int32_t, uint32_t
#include "codegen/CodeGenerator.hpp"           // for CodeGenerator, etc
#include "codegen/FrontEnd.hpp"                // for TR_FrontEnd
#include "codegen/InstOpCode.hpp"              // for InstOpCode, etc
#include "codegen/Instruction.hpp"             // for Instruction
#include "codegen/Linkage.hpp"                 // for LinkageBase, etc
#include "codegen/Machine.hpp"                 // for Machine
#include "codegen/MemoryReference.hpp"         // for MemoryReference
#include "codegen/RealRegister.hpp"            // for RealRegister, etc
#include "codegen/RegisterPair.hpp"            // for RegisterPair
#include "compile/Compilation.hpp"             // for Compilation
#include "env/CompilerEnv.hpp"
#include "env/ObjectModel.hpp"                 // for ObjectModel
#include "env/TRMemory.hpp"
#include "il/DataTypes.hpp"                    // for DataTypes::Address, etc
#include "il/ILOps.hpp"                        // for ILOpCode
#include "il/Node.hpp"                         // for Node
#include "il/Node_inlines.hpp"                 // for Node::getAddress, etc
#include "il/TreeTop.hpp"                      // for TreeTop
#include "il/TreeTop_inlines.hpp"              // for TreeTop::getNode
#include "il/symbol/ParameterSymbol.hpp"       // for ParameterSymbol
#include "il/symbol/ResolvedMethodSymbol.hpp"  // for ResolvedMethodSymbol
#include "infra/Assert.hpp"                    // for TR_ASSERT
#include "infra/BitVector.hpp"                 // for TR_BitVector
#include "infra/List.hpp"                      // for ListIterator, List
#include "r/codegen/GenerateInstructions.hpp"
#include "r/codegen/PPCOpsDefines.hpp"         // for Op_st, Op_load
#include "runtime/Runtime.hpp"

class TR_OpaqueClassBlock;
namespace TR { class AutomaticSymbol; }
namespace TR { class Register; }

void OMR::Power::Linkage::mapStack(TR::ResolvedMethodSymbol *method)
   {
   }

void OMR::Power::Linkage::mapSingleAutomatic(TR::AutomaticSymbol *p, uint32_t &stackIndex)
   {
   }

void OMR::Power::Linkage::initPPCRealRegisterLinkage()
   {
   }

void OMR::Power::Linkage::setParameterLinkageRegisterIndex(TR::ResolvedMethodSymbol *method)
   {
   }

bool OMR::Power::Linkage::hasToBeOnStack(TR::ParameterSymbol *parm)
   {
   return(false);
   }

TR::MemoryReference *OMR::Power::Linkage::getOutgoingArgumentMemRef(int32_t argSize, TR::Register *argReg, TR::InstOpCode::Mnemonic opCode, TR::PPCMemoryArgument &memArg, uint32_t length)
   {
   TR::Machine *machine = self()->cg()->machine();
   const TR::PPCLinkageProperties& properties = self()->getProperties();

   TR::MemoryReference *result = new (self()->trHeapMemory()) TR::MemoryReference(machine->getPPCRealRegister(properties.getNormalStackPointerRegister()),
                                                                              argSize+properties.getOffsetToFirstParm(), length, self()->cg());
   memArg.argRegister = argReg;
   memArg.argMemory = result;
   memArg.opCode = opCode;
   return(result);
   }


// Default values:
// fsd=false
// saveOnly=false
TR::Instruction *OMR::Power::Linkage::saveArguments(TR::Instruction *cursor, bool fsd, bool saveOnly)
   {
   return self()->saveArguments(cursor, fsd, saveOnly, self()->comp()->getJittedMethodSymbol()->getParameterList());
   }

TR::Instruction *OMR::Power::Linkage::saveArguments(TR::Instruction *cursor, bool fsd, bool saveOnly,
                                             List<TR::ParameterSymbol> &parmList)
   {
   #define  REAL_REGISTER(ri)  machine->getPPCRealRegister(ri)
   #define  REGNUM(ri)         ((TR::RealRegister::RegNum)(ri))
   const TR::PPCLinkageProperties& properties = self()->getProperties();
   TR::Machine *machine = self()->cg()->machine();
   TR::RealRegister      *stackPtr   = self()->cg()->getStackPointerRegister();
   TR::ResolvedMethodSymbol    *bodySymbol = self()->comp()->getJittedMethodSymbol();
   ListIterator<TR::ParameterSymbol>   paramIterator(&parmList);
   TR::ParameterSymbol      *paramCursor;
   TR::Node                 *firstNode = self()->comp()->getStartTree()->getNode();
   TR_BitVector             freeScratchable;
   int32_t                  busyMoves[3][64];
   int32_t                  busyIndex = 0, i1;

   for (paramCursor=paramIterator.getFirst(); paramCursor!=NULL; paramCursor=paramIterator.getNext())
      {
      int32_t lri = paramCursor->getLinkageRegisterIndex();
      TR::RealRegister::RegNum regNum;
      int offset;
      switch (lri) {
        // BOGUS.
        // This is smoke and mirrors until we implement a real SystemLinkage.
        case 0:
                regNum = OMR::RealRegister::gr10;
                offset = 64;
                break;
        case 1:
                regNum = OMR::RealRegister::gr11;
                offset = 72;
                break;
        default:
                TR_ASSERT(false, "I don't know which register this arg is in");
        }
      cursor = generateMemSrc1Instruction(self()->cg(), TR::InstOpCode::stw, firstNode,
                           new (self()->trHeapMemory()) TR::MemoryReference(REAL_REGISTER(regNum), offset, 4, self()->cg()),
                           stackPtr, cursor);
      }
   return(cursor);
   }

TR::Instruction *OMR::Power::Linkage::loadUpArguments(TR::Instruction *cursor)
   {
   if (!self()->cg()->buildInterpreterEntryPoint())
      // would be better to use a different linkage for this purpose
      return cursor;

   TR::Machine *machine = self()->cg()->machine();
   TR::RealRegister      *stackPtr   = self()->cg()->getStackPointerRegister();
   TR::ResolvedMethodSymbol      *bodySymbol = self()->comp()->getJittedMethodSymbol();
   ListIterator<TR::ParameterSymbol>   paramIterator(&(bodySymbol->getParameterList()));
   TR::ParameterSymbol      *paramCursor = paramIterator.getFirst();
   TR::Node                 *firstNode = self()->comp()->getStartTree()->getNode();
   int32_t                  numIntArgs = 0, numFloatArgs = 0;
   const TR::PPCLinkageProperties& properties = self()->getProperties();

   while ( (paramCursor!=NULL) &&
           ( (numIntArgs < properties.getNumIntArgRegs()) ||
             (numFloatArgs < properties.getNumFloatArgRegs()) ) )
      {
      TR::RealRegister     *argRegister;
      int32_t                 offset = paramCursor->getParameterOffset();

      bool hasToLoadFromStack = paramCursor->isReferencedParameter() || paramCursor->isParmHasToBeOnStack();

      switch (paramCursor->getDataType())
         {
         case TR::Int8:
         case TR::Int16:
         case TR::Int32:
            if (hasToLoadFromStack &&
                  numIntArgs<properties.getNumIntArgRegs())
               {
               argRegister = machine->getPPCRealRegister(properties.getIntegerArgumentRegister(numIntArgs));
               cursor = generateTrg1MemInstruction(self()->cg(), TR::InstOpCode::lwz, firstNode, argRegister,
                     new (self()->trHeapMemory()) TR::MemoryReference(stackPtr, offset, 4, self()->cg()), cursor);
               }
            numIntArgs++;
            break;
         case TR::Address:
            if (numIntArgs<properties.getNumIntArgRegs())
               {
               argRegister = machine->getPPCRealRegister(properties.getIntegerArgumentRegister(numIntArgs));
               cursor = generateTrg1MemInstruction(self()->cg(),TR::InstOpCode::Op_load, firstNode, argRegister,
                     new (self()->trHeapMemory()) TR::MemoryReference(stackPtr, offset, TR::Compiler->om.sizeofReferenceAddress(), self()->cg()), cursor);
               }
            numIntArgs++;
            break;
         case TR::Int64:
            if (hasToLoadFromStack &&
                  numIntArgs<properties.getNumIntArgRegs())
               {
               argRegister = machine->getPPCRealRegister(properties.getIntegerArgumentRegister(numIntArgs));
               if (TR::Compiler->target.is64Bit())
                  cursor = generateTrg1MemInstruction(self()->cg(), TR::InstOpCode::ld, firstNode, argRegister,
                        new (self()->trHeapMemory()) TR::MemoryReference(stackPtr, offset, 8, self()->cg()), cursor);
               else
                  {
                  cursor = generateTrg1MemInstruction(self()->cg(), TR::InstOpCode::lwz, firstNode, argRegister,
                        new (self()->trHeapMemory()) TR::MemoryReference(stackPtr, offset, 4, self()->cg()), cursor);
                  if (numIntArgs < properties.getNumIntArgRegs()-1)
                     {
                     argRegister = machine->getPPCRealRegister(properties.getIntegerArgumentRegister(numIntArgs+1));
                     cursor = generateTrg1MemInstruction(self()->cg(), TR::InstOpCode::lwz, firstNode, argRegister,
                           new (self()->trHeapMemory()) TR::MemoryReference(stackPtr, offset+4, 4, self()->cg()), cursor);
                     }
                  }
               }
            if (TR::Compiler->target.is64Bit())
               numIntArgs++;
            else
               numIntArgs+=2;
            break;
         case TR::Float:
            if (hasToLoadFromStack &&
                  numFloatArgs<properties.getNumFloatArgRegs())
               {
               argRegister = machine->getPPCRealRegister(properties.getFloatArgumentRegister(numFloatArgs));
               cursor = generateTrg1MemInstruction(self()->cg(), TR::InstOpCode::lfs, firstNode, argRegister,
                     new (self()->trHeapMemory()) TR::MemoryReference(stackPtr, offset, 4, self()->cg()), cursor);
               }
            numFloatArgs++;
            break;
         case TR::Double:
            if (hasToLoadFromStack &&
                  numFloatArgs<properties.getNumFloatArgRegs())
               {
               argRegister = machine->getPPCRealRegister(properties.getFloatArgumentRegister(numFloatArgs));
               cursor = generateTrg1MemInstruction(self()->cg(), TR::InstOpCode::lfd, firstNode, argRegister,
                     new (self()->trHeapMemory()) TR::MemoryReference(stackPtr, offset, 8, self()->cg()), cursor);
               }
            numFloatArgs++;
            break;
         }
      paramCursor = paramIterator.getNext();
      }
   return(cursor);
   }

TR::Instruction *OMR::Power::Linkage::flushArguments(TR::Instruction *cursor)
   {
   TR::Machine *machine = self()->cg()->machine();
   TR::RealRegister      *stackPtr   = self()->cg()->getStackPointerRegister();
   TR::ResolvedMethodSymbol      *bodySymbol = self()->comp()->getJittedMethodSymbol();
   ListIterator<TR::ParameterSymbol>   paramIterator(&(bodySymbol->getParameterList()));
   TR::ParameterSymbol      *paramCursor = paramIterator.getFirst();
   TR::Node                 *firstNode = self()->comp()->getStartTree()->getNode();
   int32_t                  numIntArgs = 0, numFloatArgs = 0;
   const TR::PPCLinkageProperties& properties = self()->getProperties();

   while ( (paramCursor!=NULL) &&
           ( (numIntArgs < properties.getNumIntArgRegs()) ||
             (numFloatArgs < properties.getNumFloatArgRegs()) ) )
      {
      TR::RealRegister     *argRegister;
      int32_t                 offset = paramCursor->getParameterOffset();

      // If parm is referenced or required to be on stack (i.e. FSD), we have to flush.
      bool hasToStoreToStack = paramCursor->isReferencedParameter() || paramCursor->isParmHasToBeOnStack();

      switch (paramCursor->getDataType())
         {
         case TR::Int8:
         case TR::Int16:
         case TR::Int32:
            if (hasToStoreToStack &&
                  numIntArgs<properties.getNumIntArgRegs())
               {
               argRegister = machine->getPPCRealRegister(properties.getIntegerArgumentRegister(numIntArgs));
               cursor = generateMemSrc1Instruction(self()->cg(), TR::InstOpCode::stw, firstNode,
                     new (self()->trHeapMemory()) TR::MemoryReference(stackPtr, offset, 4, self()->cg()),
                     argRegister, cursor);
               }
            numIntArgs++;
            break;
         case TR::Address:
            if (numIntArgs<properties.getNumIntArgRegs())
               {
               argRegister = machine->getPPCRealRegister(properties.getIntegerArgumentRegister(numIntArgs));
               cursor = generateMemSrc1Instruction(self()->cg(),TR::InstOpCode::Op_st, firstNode,
                     new (self()->trHeapMemory()) TR::MemoryReference(stackPtr, offset, TR::Compiler->om.sizeofReferenceAddress(), self()->cg()),
                     argRegister, cursor);
               }
            numIntArgs++;
            break;
         case TR::Int64:
            if (hasToStoreToStack &&
                  numIntArgs<properties.getNumIntArgRegs())
               {
               argRegister = machine->getPPCRealRegister(properties.getIntegerArgumentRegister(numIntArgs));
               if (TR::Compiler->target.is64Bit())
                  cursor = generateMemSrc1Instruction(self()->cg(),TR::InstOpCode::Op_st, firstNode,
                        new (self()->trHeapMemory()) TR::MemoryReference(stackPtr, offset, 8, self()->cg()),
                        argRegister, cursor);
               else
                  {
                  cursor = generateMemSrc1Instruction(self()->cg(), TR::InstOpCode::stw, firstNode,
                        new (self()->trHeapMemory()) TR::MemoryReference(stackPtr, offset, 4, self()->cg()),
                        argRegister, cursor);
                  if (numIntArgs < properties.getNumIntArgRegs()-1)
                     {
                     argRegister = machine->getPPCRealRegister(properties.getIntegerArgumentRegister(numIntArgs+1));
                     cursor = generateMemSrc1Instruction(self()->cg(), TR::InstOpCode::stw, firstNode,
                           new (self()->trHeapMemory()) TR::MemoryReference(stackPtr, offset+4, 4, self()->cg()),
                           argRegister, cursor);
                     }
                  }
               }
            if (TR::Compiler->target.is64Bit())
               numIntArgs++;
            else
               numIntArgs+=2;
            break;
         case TR::Float:
            if (hasToStoreToStack &&
                  numFloatArgs<properties.getNumFloatArgRegs())
               {
               argRegister = machine->getPPCRealRegister(properties.getFloatArgumentRegister(numFloatArgs));
               cursor = generateMemSrc1Instruction(self()->cg(), TR::InstOpCode::stfs, firstNode,
                     new (self()->trHeapMemory()) TR::MemoryReference(stackPtr, offset, 4, self()->cg()),
                     argRegister, cursor);
               }
            numFloatArgs++;
            break;
         case TR::Double:
            if (hasToStoreToStack &&
                  numFloatArgs<properties.getNumFloatArgRegs())
               {
               argRegister = machine->getPPCRealRegister(properties.getFloatArgumentRegister(numFloatArgs));
               cursor = generateMemSrc1Instruction(self()->cg(), TR::InstOpCode::stfd, firstNode,
                     new (self()->trHeapMemory()) TR::MemoryReference(stackPtr, offset, 8, self()->cg()),
                     argRegister, cursor);
               }
            numFloatArgs++;
            break;
         }
      paramCursor = paramIterator.getNext();
      }
   return(cursor);
   }

TR::Register *OMR::Power::Linkage::pushIntegerWordArg(TR::Node *child)
   {
   TR::Register *pushRegister = NULL;
   TR_ASSERT(child->getDataType() != TR::Address, "assumption violated");
   if (child->getRegister() == NULL && child->getOpCode().isLoadConst())
      {
      pushRegister = self()->cg()->allocateRegister();
      loadConstant(self()->cg(), child, (int32_t)child->get64bitIntegralValue(), pushRegister);
      child->setRegister(pushRegister);
      }
   else
      {
      pushRegister = self()->cg()->evaluate(child);
      }
   self()->cg()->decReferenceCount(child);
   return pushRegister;
   }

TR::Register *OMR::Power::Linkage::pushAddressArg(TR::Node *child)
   {
   TR::Register *pushRegister = NULL;
   TR_ASSERT(child->getDataType() == TR::Address, "assumption violated");
   if (child->getRegister() == NULL && child->getOpCode().isLoadConst())
      {
      bool isClass = child->isClassPointerConstant();
      pushRegister = self()->cg()->allocateRegister();
      if (isClass && self()->cg()->wantToPatchClassPointer((TR_OpaqueClassBlock*)child->getAddress(), child))
         loadAddressConstantInSnippet(self()->cg(), child, child->getAddress(), pushRegister, NULL,TR::InstOpCode::Op_load, NULL, NULL);
      else
         {
         if (child->isMethodPointerConstant())
            loadAddressConstant(self()->cg(), child, child->getAddress(), pushRegister, NULL, false, TR_RamMethodSequence);
         else
            loadAddressConstant(self()->cg(), child, child->getAddress(), pushRegister);
         }
      child->setRegister(pushRegister);
      }
   else
      {
      pushRegister = self()->cg()->evaluate(child);
      }
   self()->cg()->decReferenceCount(child);
   return pushRegister;
   }

TR::Register *OMR::Power::Linkage::pushThis(TR::Node *child)
   {
   TR::Register *tempRegister = self()->cg()->evaluate(child);
   self()->cg()->decReferenceCount(child);
   return tempRegister;
   }

TR::Register *OMR::Power::Linkage::pushLongArg(TR::Node *child)
   {
   TR::Register *pushRegister = NULL;
   if (child->getRegister() == NULL && child->getOpCode().isLoadConst())
      {
      if (TR::Compiler->target.is64Bit())
         {
         pushRegister = self()->cg()->allocateRegister();
         loadConstant(self()->cg(), child, child->getLongInt(), pushRegister);
         }
      else
         {
         TR::Register   *lowRegister = self()->cg()->allocateRegister();
         TR::Register   *highRegister = self()->cg()->allocateRegister();
         pushRegister = self()->cg()->allocateRegisterPair(lowRegister, highRegister);
         loadConstant(self()->cg(), child, child->getLongIntLow(), lowRegister);
         loadConstant(self()->cg(), child, child->getLongIntHigh(), highRegister);
         }
      child->setRegister(pushRegister);
      }
   else
      {
      pushRegister = self()->cg()->evaluate(child);
      }
   self()->cg()->decReferenceCount(child);
   return pushRegister;
   }

TR::Register *OMR::Power::Linkage::pushFloatArg(TR::Node *child)
   {
   TR::Register *pushRegister = self()->cg()->evaluate(child);
   self()->cg()->decReferenceCount(child);
   return(pushRegister);
   }

TR::Register *OMR::Power::Linkage::pushDoubleArg(TR::Node *child)
   {
   TR::Register *pushRegister = self()->cg()->evaluate(child);
   self()->cg()->decReferenceCount(child);
   return(pushRegister);
   }

int32_t
OMR::Power::Linkage::numArgumentRegisters(TR_RegisterKinds kind)
   {
   switch (kind)
      {
      case TR_GPR:
         return self()->getProperties().getNumIntArgRegs();
      case TR_FPR:
         return self()->getProperties().getNumFloatArgRegs();
      default:
         return 0;
      }
   }

TR_ReturnInfo OMR::Power::Linkage::getReturnInfoFromReturnType(TR::DataType returnType)
   {
   switch (returnType)
      {
      case TR::NoType:
         return TR_VoidReturn;
      case TR::Int8:
      case TR::Int16:
      case TR::Int32:
         return TR_IntReturn;
      case TR::Int64:
         return TR_LongReturn;
      case TR::Address:
         return TR::Compiler->target.is64Bit() ? TR_ObjectReturn : TR_IntReturn;
      case TR::Float:
         return TR_FloatReturn;
      case TR::Double:
         return TR_DoubleReturn;
      }

   TR_ASSERT(false, "Unhandled return type");

   return TR_VoidReturn;
   }

TR_HeapMemory
OMR::Power::Linkage::trHeapMemory()
   {
   return self()->trMemory();
   }


TR_StackMemory
OMR::Power::Linkage::trStackMemory()
   {
   return self()->trMemory();
   }
