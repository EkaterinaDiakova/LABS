#include<iostream>
#include<stdio.h>
#include<math.h>
#include"dynamic_array.h"
#include"linked_list.h"
#include"Sequence.h"
#include"array_sequence.h"
#include"linked_list.h"
#include"Polinomial.h"

using namespace std;

int main()
{
	int tmp;
	//int buf[10] = {0,1,2,3,4,5,6,7,8,9};
	int buf[3] = {0,1,2};
	polinomial<int, array_sequence<int>> test1(buf, 3);
	test1.print_string();
	cout << test1 << endl;

	tmp = test1.get_first();
	cout << tmp << endl;

	tmp = test1.get_length();
	cout << tmp << endl;

	polinomial<int, array_sequence<int>> test2(test1);
	test2.print_string();
	cout << test2 << endl;

	polinomial<int, array_sequence<int>>* test3 = test1 + test2;
	test3->print_string();
	cout << *test3 << endl;

	test3 = test1 * test2;
	test3->print_string();
	cout << *test3 << endl;

	tmp = test3->argument(2);
	cout << tmp << endl;

	tmp = test3->composition(&test1, 1);
	cout << tmp << endl;










	return 0;
}




