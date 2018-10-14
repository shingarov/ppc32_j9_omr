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

#include <limits.h>
#include <stdio.h>
#include "compile/Method.hpp"
#include "il/DataTypes.hpp"
#include "ilgen/IlGeneratorMethodDetails_inlines.hpp"
#include "ilgen/TypeDictionary.hpp"

void
compileTestMethods()
   {
   int32_t rc = 0;
   uint8_t *entry=0;

   TR::TypeDictionary types;

   IterativeFibonnaciMethod iterFibMethodBuilder(&types, this);
   rc = compileMethodBuilder(&iterFibMethodBuilder, &entry);
   _iterativeFibMethod = (IterativeFibFunctionType *) entry;
   }

int32_t
BuilderTest::iterativeFib(int32_t n)
   {
   if (n < 2)
      {
      return n;
      }

   int32_t last_sum = 1, lastlast_sum = 0;
   for (int32_t i=1; i < n;i++)
      {
      int32_t temp_sum = last_sum + lastlast_sum;
      lastlast_sum = last_sum;
      last_sum = temp_sum;
      }
   return last_sum;
   }

void
BuilderTest::invokeTests()
   {
   for(uint32_t i = 0; i <= 20 ; i++)
      {
	   int32_t actual, expected;
	   expected = iterativeFib(i);
	   actual   = _iterativeFibMethod(i);
	   if (actual != expected) {
		   printf("kaboom.\n");
	   } else {
		 printf("fib(%d) = %d\n", i, actual);
	   }
      }
   }



} // namespace TestCompiler

