#include <iostream>
#define DLL_EXPORT
#include "dllHeader.h"


//
//extern "C"
//{
DECLDIR int Add(int a, int b)
{
    return(a + b);
}

DECLDIR void Function(void)
{
    std::cout << "DLL Called!" << std::endl;
}
int AlgClass::run(int a) {
    return a * a;
}
//}
