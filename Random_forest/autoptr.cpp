#include<iostream>
using namespace std;


int autoptr()
{
    std::auto_ptr<int> p(new int);
    std::auto_ptr<int> p2=std::auto_ptr<int>(nullptr);
    std::cout << "p2 points is null " << std::boolalpha <<(p2.get() == nullptr) << '\n';

    *p.get() = 100;

    std::cout << "p points to " << *p.get() << '\n';
    std::cout << "p points " << p.get() << '\n';

    int* p3;
    p3 = p.release();
    std::cout << "p3 points to " << *p3 << '\n';
    std::cout << "p points is null " << std::boolalpha <<(p.get() == NULL) << '\n';
}
  
  
