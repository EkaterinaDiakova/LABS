#include <iostream>
#include <string>
#include <sstream>
#include"btree.h"

template<typename T>
void sqr(node<T>* curr){//map
    curr->value = curr->value * curr->value;
}

template<typename T>
T sum(node<T>* curr,T curr_sum){//reduce
    return curr_sum + curr->value;
}

template<typename T>
bool is_more_than_10(node<T>* curr){//where
    if(curr->value >= 10)
        return true;
    return false;
}

void test()
{
	int size;
	unsigned int start_time;
	unsigned int end_time;
	unsigned int search_time;

	size = 1000000;

	btree<int> first1;
	for (int i = 0; i < size; ++i)
	{
		first1.insert(i);
		if(i % 1000 == 0) cout << i << endl;
		//first1.insert(rand()%size);
	}
	start_time =  clock(); // начальное время
	first1.map(sqr<int>);
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	std::cout << "MAP --- Execution time for " << first1.get_size() << " elements is " << search_time << " mls" << std::endl;

	start_time =  clock(); // начальное время
	first1.reduce(sum);
	end_time = clock(); // конечное время
	search_time = end_time - start_time; // искомое время
	std::cout << "REDUCE --- Execution time for " << first1.get_size() << " elements is " << search_time << " mls" << std::endl;
}


