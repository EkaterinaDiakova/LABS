#include <iostream>

#include "dynamic_array.h"

using namespace std;

int main()
{
       dynamic_array<int> test1(10);
       for(int i = 0; i < 10; i++)
       {
    	   test1[i] = i;
       }
       cout << test1 << endl;

       dynamic_array<int> test2(test1);
       cout << test2 << endl;

       int a[10] = {0,1,2,3,4,5,6,7,8,9};

       dynamic_array<int> test3(a, 5);

       cout << test3 << endl;

       test3.resize(3);

       cout << test3 << endl;

       test3.resize(6);

       cout << test3 << endl;

       cout << test3.get_size() << endl;

       test3.set(2, 10);

       cout << test3 << endl;


    return 0;
}
