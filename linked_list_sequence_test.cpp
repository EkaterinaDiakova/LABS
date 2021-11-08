#include <iostream>

#include "linked_list.h"
#include"Sequence.h"
#include"linked_list_sequence.h"

using namespace std;

int main()
{
	int buf[10] = {0,1,2,3,4,5,6,7,8,9};
	sequence<int>* test1 = new linked_list_sequence<int>(buf, 10);
	test1->print();

	int tmp;
	tmp = test1->get_first();
	cout << tmp << endl;

	tmp = test1->get_last();
	cout << tmp << endl;

	tmp = test1->operator [](5);
	cout << tmp << endl;

	sequence<int>* test2 = test1->get_sub_sequence(2, 5);
	test2->print();
	test1->print();

	tmp = test2->get_length();
	cout << tmp << endl;

	test2->prepend(7);
	test2->print();

	test1->prepend(7);
	test1->print();

	test2->append(11);
	test2->print();

	test2->insert_at(15, 3);
	test2->print();

	tmp = test2->get_length();
	cout << tmp << endl;

	sequence<int>* test3 = test2->concat(test1);
	test3->print();
	test2->print();
	test1->print();




    return 0;
}



