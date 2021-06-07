#ifndef SEQUENCE_H_
#define SEQUENCE_H_
#include<iostream>

using namespace std;

template <typename T>
class sequence
{
public:
	sequence() {}
	virtual ~sequence() {}
	virtual T get_first() = 0;
	virtual T get_last() = 0;
	virtual T get(int index) = 0;
	virtual sequence<T>* get_sub_sequence(int start_index, int end_index) = 0;
	virtual int get_length() = 0;
	virtual void append(T item) = 0;
	virtual void prepend(T item) = 0;
	virtual void insert_at(T item, int index) = 0;
	virtual sequence<T>* concat(sequence<T>* sequence) = 0;
	virtual T & operator[] (int i) = 0;
	virtual void print() = 0;
};




#endif /* SEQUENCE_H_ */
