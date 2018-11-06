// https://manski.net/2011/11/creating-a-dll-project/
// example for create a dll 

#ifndef _DLL_TUTORIAL_H_
#define _DLL_TUTORIAL_H_
#include <iostream>

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

//extern "C"
//{
DECLDIR int Add(int a, int b);
DECLDIR void Function(void);
class DECLDIR AlgClass {
   public:
       int run(int a);
   };
//}

#endif
