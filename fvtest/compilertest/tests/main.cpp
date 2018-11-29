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

extern "C" bool initializeTestJit(TR_RuntimeHelper *helperIDs, void **helperAddresses, int32_t numHelpers, char *options);
extern "C" void shutdownJit();

/*** Test Template ***/

#define TestDefinition(testName,functionType,takesIntArg)     \
class testName##Method : public TR::MethodBuilder \
{                                                 \
   public:                                        \
   testName##Method(TR::TypeDictionary *types);   \
   virtual bool buildIL();                        \
};                                                \
testName##Method::testName##Method(TR::TypeDictionary *types) \
   : TR::MethodBuilder(types)                                 \
{                                                             \
   DefineLine(LINETOSTR(__LINE__));                           \
   DefineFile(__FILE__);                                      \
   if (takesIntArg) DefineParameter("x", Int32);              \
   DefineReturnType(Int32);                                   \
}                                                             \
functionType *method##testName;                               \
void compile##testName()                                      \
{                                                             \
   TR::TypeDictionary types;                                  \
   testName##Method methodBuilder(&types);                    \
   TR::ResolvedMethod resolvedMethod(&methodBuilder);         \
   TR::IlGeneratorMethodDetails details(&resolvedMethod);     \
   int32_t rc = 0;                                            \
   method##testName = (functionType *)                        \
        compileMethodFromDetails(NULL, details, warm, rc);    \
}


/*** Function pointer types ***/
typedef int32_t (FType)();
typedef int32_t (FxType)(int32_t);
typedef int32_t (FxyType)(int32_t,int32_t);



/*** Small int const ***/
TestDefinition(SmallInt, FType, false)
bool SmallIntMethod::buildIL()
{
   Return(
      ConstInt32(42)
   );
   return true;
}


/*** Large int const ***/
TestDefinition(LargeInt, FType, false)
bool LargeIntMethod::buildIL()
{
   Return(
      ConstInt32(420000)
   );
   return true;
}


/*** x + 1 ***/
TestDefinition(Xplus1, FxType, true)
bool Xplus1Method::buildIL()
{
   Return(
       Add(
         Load("x"),
         ConstInt32(1)
       )
   );
   return true;
}

/*** Store var ***/
TestDefinition(StoreLoad, FType, false)
bool StoreLoadMethod::buildIL()
{
   Store( "x", ConstInt32(123) );
   Return( Load("x") );
   return true;
}



/*** Simple Branching: x < const ***/
TestDefinition(LessThanConst, FxType, true)
bool LessThanConstMethod::buildIL()
{
   TR::IlBuilder *left=NULL, *right=NULL;
   IfThenElse(&left, &right,
      LessThan(
         Load("x"),
         ConstInt32(10)));

   left -> Return(left->ConstInt32(1));
   right-> Return(right->ConstInt32(2));
   return true;
}

/*** Simple Branching: x < y ***/
// -- TestDefinition(LessThan, FxyType, NotABool)
// -- FROM HERE
class LessThanMethod : public TR::MethodBuilder
{
   public:
   LessThanMethod(TR::TypeDictionary *types);
   virtual bool buildIL();
};
LessThanMethod::LessThanMethod(TR::TypeDictionary *types)
   : TR::MethodBuilder(types)
{
   DefineLine(LINETOSTR(__LINE__));
   DefineFile(__FILE__);
   DefineParameter("x", Int32);
   DefineParameter("y", Int32); // culprit
   DefineReturnType(Int32);
}
FxyType *methodLessThan;
void compileLessThan()
{
   TR::TypeDictionary types;
   LessThanMethod methodBuilder(&types);
   TR::ResolvedMethod resolvedMethod(&methodBuilder);
   TR::IlGeneratorMethodDetails details(&resolvedMethod);
   int32_t rc = 0;
   methodLessThan = (FxyType *)
        compileMethodFromDetails(NULL, details, warm, rc);
}
// -- TO HERE
bool LessThanMethod::buildIL()
{
   TR::IlBuilder *left=NULL, *right=NULL;
   IfThenElse(&left, &right,
      LessThan(
         Load("x"),
         Load("y")));

   left -> Return(left->ConstInt32(1));
   right-> Return(right->ConstInt32(2));
   return true;
}



/*** Recursive Fibonacci ***/
TestDefinition(RecursiveFibonacci, FxType, true)
bool RecursiveFibonacciMethod::buildIL()
{
   TR::IlBuilder *baseCase=NULL, *recursiveCase=NULL;
   IfThenElse(&baseCase, &recursiveCase,
      LessThan(
         Load("x"),
         ConstInt32(2)));

   DefineLocal("result", Int32);

   baseCase->Store("result",
   baseCase->   Load("x"));
   recursiveCase->Store("result",
   recursiveCase->   Add(
   recursiveCase->      Call("fib_recur", 1,
   recursiveCase->         Sub(
   recursiveCase->            Load("x"),
   recursiveCase->            ConstInt32(1))),
   recursiveCase->      Call("fib_recur", 1,
   recursiveCase->         Sub(
   recursiveCase->            Load("x"),
   recursiveCase->            ConstInt32(2)))));

   Return(
      Load("result"));
   return true;
}



/*** Iterative Fibonacci ***/
TestDefinition(IterativeFibonacci, FxType, true)
bool IterativeFibonacciMethod::buildIL()
{
   TR::IlBuilder *returnZero = NULL;
   IfThen(&returnZero,
      EqualTo(
         Load("x"),
         ConstInt32(0)));
   returnZero->Return(
   returnZero->   ConstInt32(0));

   TR::IlBuilder *returnOne = NULL;
   IfThen(&returnOne,
      EqualTo(
         Load("x"),
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
           Load("x"),
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




int main(int argc, char **argv)
{
     initializeTestJit(0, 0, 0, "-Xjit:enableRelocatableELFGeneration,{*}(traceFull,log=LogFile)");
//	 initializeTestJit(0, 0, 0, "-Xjit:enableRelocatableELFGeneration");
//	 initializeTestJit(0, 0, 0, "-Xjit");
     printf("Initialized JIT\n");
/*
	 compileSmallInt();
     printf( "42    -> %d\n", methodSmallInt() );

	 compileLargeInt();
     printf( "420000     -> %d\n", methodLargeInt() );

	 compileXplus1();
     printf( "10+1    -> %d\n", methodXplus1(10) );
*/
     compileStoreLoad();
     printf("123  -> %d\n", methodStoreLoad());


/*   compileLessThan();
     printf( "5<10? 1:2    -> %d\n", methodLessThan(5) );
     printf( "15<10? 1:2    -> %d\n", methodLessThan(15) );
     printf( "10<10? 1:2    -> %d\n", methodLessThan(10) );
     printf( "1000000<10? 1:2    -> %d\n", methodLessThan(1000000) );
     printf( "-1000000<10? 1:2    -> %d\n", methodLessThan(-1000000) );
     printf( "-1<10? 1:2    -> %d\n", methodLessThan(-1) );
*/

/*
	 compileFib();
     printf( "func ptr = %p\n", &methodFib );
     int answer = methodFib(1);
     printf( "fib(1) = %d\n", answer );
     
     printf( "fib(3) = %d\n", methodFib(3) );
     printf( "fib(4) = %d\n", methodFib(4) );
     printf( "fib(5) = %d\n", methodFib(5) );
*/

//   compileIterativeFibonacci();
//     for (int k=0; k<=31; k++)
//       printf( "fib(%d)   -> %d\n", k, methodIterativeFibonacci(k) );


     printf("Shutting down JIT...\n");
     shutdownJit();
     return 0;
}

