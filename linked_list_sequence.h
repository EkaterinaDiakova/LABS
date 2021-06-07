#ifndef LINKED_LIST_SEQUENCE_H_
#define LINKED_LIST_SEQUENCE_H_

#include<iostream>
#include"linked_list.h"
#include"Sequence.h"

using namespace std;

template <typename T>
class linked_list_sequence : public sequence<T>
{
private:
	linked_list<T>* items;
public:
	linked_list_sequence()
	{
		this->items = new linked_list<T>();
	}

	linked_list_sequence(T* item, int count)
	{
		this->items = new linked_list<T>(item, count);
	}

	linked_list_sequence(linked_list<T> & list)
	{
		this->items = new linked_list<T>(list);
	}

	~linked_list_sequence()
	{
		this->items->~linked_list();
	}

	T get_first()
	{
		return this->items->get_first();
	}

	T get_last()
	{
		return this->items->get_last();
	}

	T get(int index)
	{
		return this->items->operator [](index);
	}

	sequence<T>* get_sub_sequence(int start_index, int end_index)
	{
		linked_list_sequence<T>* new_sequence;
		linked_list<T>* tmp = this->items->get_sub_list(start_index, end_index);
		linked_list_sequence<T>* tmp_sequence = new linked_list_sequence<T>(*tmp);
		return new_sequence = new linked_list_sequence<T>(*tmp_sequence);
	}

	int get_length()
	{
		return this->items->get_length();
	}

	void prepend(T item)
	{
		this->items->prepend(item);
	}

	void append(T item)
	{
		this->items->append(item);
	}

	void insert_at(T item, int index)
	{
		this->items->insert_at(item, index);
	}

	sequence<T>* concat(sequence<T>* list)
	{
		T buf[list->get_length()];
		for(int i = 0; i < list->get_length(); i++)
		{
			buf[i] = list->operator [](i);
		}
		linked_list_sequence<T>* tmp_list = new linked_list_sequence<T>(buf, list->get_length());
		linked_list_sequence<T>* new_sequence;
		linked_list<T>* tmp = this->items->concat(tmp_list->items);
		linked_list_sequence<T>* tmp_sequence = new linked_list_sequence<T>(*tmp);
		return new_sequence = new linked_list_sequence<T>(*tmp_sequence);
	}

	void print()
	{
	 T tmp;
	 for(int i = 0; i < this->items->get_length(); i++)
	 {
		 tmp = this->items->operator [](i);
		 cout << tmp << ' ';
	 }
	 cout << endl;
	}


	T & operator[] (int i)
	{
	 return this->items->operator [](i);
	}
};



#endif /* LINKED_LIST_SEQUENCE_H_ */
