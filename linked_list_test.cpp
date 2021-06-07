#include <iostream>

#include "linked_list.h"

using namespace std;

int main()
{
	int array[10] = {0,1,2,3,4,5,6,7,8,9};

	linked_list<int> test1(array,10);
	cout << test1 << endl;

	linked_list<int> test2(test1);
	cout << test2 << endl;

	int item;
	item = test2.get_first();
	cout << item << endl;

	item = test2.get_last();
	cout << item << endl;

	item = test2.get_length();
	cout << item << endl;

	test2.prepend(5);
	cout << test2 << endl;
	cout << test1 << endl;

	test2.append(10);
	cout << test2 << endl;

	linked_list<int>* test3 = test1.get_sub_list(0, 5);
	cout << *test3 << endl;

	test1.insert_at(11, 3);
	cout << test1 << endl;

	linked_list<int>* test4;
	test4 = test1.concat(test3);
	cout << *test4 << endl;

    return 0;
}
