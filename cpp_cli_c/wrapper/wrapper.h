#pragma once
#include"../dll/dllHeader.h"  
// path to c++ .h


public ref class AlgClassWrapper
{
public:
    AlgClassWrapper() {};
    int run(int);
private:
    AlgClass* m_alg;
};
