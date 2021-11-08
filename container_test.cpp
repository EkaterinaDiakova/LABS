#include<iostream>
#include<stdio.h>
#include<math.h>
#include"dynamic_array.h"
#include"linked_list.h"
#include"Sequence.h"
#include"array_sequence.h"
#include"linked_list_sequence.h"
#include"container.h"

using namespace std;

int cmp1(int a, int b)
{
	return a > b;
}

int cmp2(float a, float b)
{
	return a > b;
}

int main()
{
	int buf1[10] = {0,1,22,3,44,15,6,7,8,9};
	float buf2[10] = {0.33,1.44,22.55,3.0,44.1,15.0,6.0,7.0,8.0,9.0};

	container<int, array_sequence<int>> test1(buf1, 10);
	test1.print_items();

	test1.sort(1, cmp1);
	test1.print_items();
	cout << endl;
	test1.print_sort_items();
	cout << endl;
	cout << "lead time: " << test1.lead_time << " us" << endl;

	test1.sort(2, cmp1);
	test1.print_items();
	cout << endl;
	test1.print_sort_items();
	cout << endl;
	cout << "lead time: " << test1.lead_time << " us" << endl;

	container<int, linked_list_sequence<int>> test2(buf1, 10);
	test2.print_items();

	test2.sort(1, cmp1);
	test2.print_items();
	cout << endl;
	test2.print_sort_items();
	cout << endl;
	cout << "lead time: " << test2.lead_time << " us" << endl;

	test2.sort(2, cmp1);
	test2.print_items();
	cout << endl;
	test2.print_sort_items();
	cout << endl;
	cout << "lead time: " << test2.lead_time << " us" << endl;

	container<float, array_sequence<float>> test3(buf2, 10);
	test3.print_items();

	test3.sort(1, cmp2);
	test3.print_items();
	cout << endl;
	test3.print_sort_items();
	cout << endl;
	cout << "lead time: " << test3.lead_time << " us" << endl;

	test3.sort(2, cmp2);
	test3.print_items();
	cout << endl;
	test3.print_sort_items();
	cout << endl;
	cout << "lead time: " << test3.lead_time << " us" << endl;

	container<float, linked_list_sequence<float>> test4(buf2, 10);
	test4.print_items();

	test4.sort(1, cmp2);
	test4.print_items();
	cout << endl;
	test4.print_sort_items();
	cout << endl;
	cout << "lead time: " << test4.lead_time << " us" << endl;

	test4.sort(2, cmp2);
	test4.print_items();
	cout << endl;
	test4.print_sort_items();
	cout << endl;
	cout << "lead time: " << test4.lead_time << " us" << endl;

	return 0;
}




