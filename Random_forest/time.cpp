#include<iostream>
#include<time.h>
using namespace std;
  
int  time()
{
	//http://blog.csdn.net/luoweifu/article/details/20288549
	cout<< "dec:" <<dec<<time(NULL)<<endl;
	time_t timep;
	time(&timep);
	cout << gmtime(&timep)->tm_year;
	srand((unsigned int)time(&timep));
	cout << rand()<<" "<<rand()<<endl;
    return 0;
 }
