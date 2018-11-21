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

   DefineReturnType(Int32);
   }

bool
IterativeFibonnaciMethod::buildIL()
   {
   Return(
      ConstInt32(42));

   return true;
   }



typedef int32_t (IterativeFibFunctionType)();
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

   uint32_t *e = (uint32_t*)entry;
   uint32_t i1 = *(e);
   uint32_t i2 = *(e+1);
   uint32_t i3 = *(e+2);
   printf("Instructions: %X %X %X\n", i1, i2, i3);



   _iterativeFibMethod = (IterativeFibFunctionType *) entry;
}


void invokeTests()
   {
	   printf("fib = %d\n", _iterativeFibMethod() );
   }


extern "C" bool initializeTestJit(TR_RuntimeHelper *helperIDs, void **helperAddresses, int32_t numHelpers, char *options);
extern "C" void shutdownJit();

void some() {
        printf("Hello\n");
}


int main(int argc, char **argv)
   {
	   some();
	   initializeTestJit(0, 0, 0, "-Xjit:enableRelocatableELFGeneration,{*}(traceFull,log=LogFile)");
	//   initializeTestJit(0, 0, 0, "-Xjit:enableRelocatableELFGeneration");
       printf("Initialized JIT\n");
	   compileTestMethods();
	   invokeTests();
		shutdownJit();
   return 0;
   }
