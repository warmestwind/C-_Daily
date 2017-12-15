#include<iostream>
#include<memory>
#include<windows.h>
#include<vector>
#include<string>
#include<limits>
#include<map>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <memory>
#include <Windows.h> //ssize_t
#include<time.h>
#include<iomanip>
#include <cmath>
using namespace std;


int autoptr() {
	std::auto_ptr<int> p(new int);
	std::auto_ptr<int> p2=std::auto_ptr<int>(0);
	*p.get() = 100;  //p.get() ->pointer to int,if false return 0/nullptr
  //reference:http://www.cplusplus.com/reference/memory/auto_ptr/get/

	std::cout << "p points to " << *p.get() << '\n';
	std::cout << "p points " << p.get() << '\n';
	std::cout << "p2 points " << (p2.get()==nullptr)<< '\n';
  }
  
  
