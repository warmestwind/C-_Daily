#define DLLEXPORT extern "C" __declspec(dllexport)
//extern "C" 以C语言的方式编译，
//工程选择X64，dll才能被python调用

DLLEXPORT  int sum(int a, int b) {
    return a + b;
}
