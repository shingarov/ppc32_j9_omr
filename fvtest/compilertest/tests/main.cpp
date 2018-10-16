#include <limits.h>
#include <stdio.h>
#include <stdint.h>
#include "compile/Method.hpp"
#include "control/CompileMethod.hpp"
#include "compile/CompilationTypes.hpp"
#include "il/DataTypes.hpp"
#include "ilgen/IlGeneratorMethodDetails_inlines.hpp"
#include "ilgen/TypeDictionary.hpp"
#include "ilgen/MethodBuilder.hpp"

class IterativeFibonnaciMethod : public TR::MethodBuilder
   {
   public:
   IterativeFibonnaciMethod(TR::TypeDictionary *types);
   virtual bool buildIL();
   };

IterativeFibonnaciMethod::IterativeFibonnaciMethod(TR::TypeDictionary *types)
   : TR::MethodBuilder(types)
   {
   DefineLine(LINETOSTR(__LINE__));
   DefineFile(__FILE__);

   DefineName("fib_iter");
   DefineParameter("N", Int32);
   DefineReturnType(Int32);
   }

bool
IterativeFibonnaciMethod::buildIL()
   {
   TR::IlBuilder *returnZero = NULL;
   IfThen(&returnZero,
      EqualTo(
         Load("N"),
         ConstInt32(0)));
   returnZero->Return(
   returnZero->   ConstInt32(0));

   TR::IlBuilder *returnOne = NULL;
   IfThen(&returnOne,
      EqualTo(
         Load("N"),
         ConstInt32(1)));
   returnOne->Return(
   returnOne->   ConstInt32(1));

   Store("LastSum",
      ConstInt32(0));

   Store("Sum",
      ConstInt32(1));

   TR::IlBuilder *body = NULL;
   ForLoopUp("I", &body,
           ConstInt32(1),
           Load("N"),
           ConstInt32(1));

   body->Store("tempSum",
   body->   Add(
   body->      Load("Sum"),
   body->      Load("LastSum")));
   body->Store("LastSum",
   body->   Load("Sum"));
   body->Store("Sum",
   body->   Load("tempSum"));

   Return(
      Load("Sum"));

   return true;
   }



typedef int32_t (IterativeFibFunctionType)(int32_t);
IterativeFibFunctionType *_iterativeFibMethod;

void compileTestMethods()
{
   int32_t rc = 0;
   uint8_t *entry=0;

   TR::TypeDictionary types;

   IterativeFibonnaciMethod iterFibMethodBuilder(&types);


   //rc = compileMethodBuilder(&iterFibMethodBuilder, &entry);
   TR::ResolvedMethod resolvedMethod(&iterFibMethodBuilder);
   TR::IlGeneratorMethodDetails details(&resolvedMethod);

   entry = compileMethodFromDetails(NULL, details, warm, rc);





   _iterativeFibMethod = (IterativeFibFunctionType *) entry;
}

int32_t iterativeFib(int32_t n)
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

void invokeTests()
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


extern "C" bool initializeTestJit(TR_RuntimeHelper *helperIDs, void **helperAddresses, int32_t numHelpers, char *options);
extern "C" void shutdownJit();

int main(int argc, char **argv)
   {
	   initializeTestJit(0, 0, 0, "-Xjit:enableRelocatableELFGeneration,{*}(traceFull,log=LogFile)");
	//   initializeTestJit(0, 0, 0, "-Xjit:enableRelocatableELFGeneration");
	   compileTestMethods();
	   invokeTests();
		shutdownJit();
   return 0;
   }
