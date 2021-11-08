#ifndef ARRAY_SEQUENCE_H_
#define ARRAY_SEQUENCE_H_

#include<iostream>
#include"dynamic_array.h"
#include"Sequence.h"

using namespace std;

template <typename T>
class array_sequence : public sequence<T>
{
private:
	dynamic_array<T>* items;
public:
	array_sequence()
	{
		this->items = new dynamic_array<T>();
		//this->items->dynamic_array();
	}

	array_sequence(T* item, int count)
	{
		//items = new dynamic_array<T>(item, count);
		this->items = new dynamic_array<T>(item, count);
	}

	array_sequence(const dynamic_array<T> & a)
	{
		this->items = new dynamic_array<T>(a);
	}

	~array_sequence()
	{
		this->items->~dynamic_array();
	}

	T get_first()
	{
		return this->items->operator [](0);
	}

	T get_last()
	{
		return this->items->operator [](items->get_size() - 1);
	}

	T get(int index)
	{
		return this->items->operator [](index);
	}

	sequence<T>* get_sub_sequence(int start_index, int end_index)
	{
		array_sequence<T>* new_sequence;
		int count = (end_index - start_index) + 1;
		T tmp[count];
		for(int i = 0; i < count; i++)
		{
			tmp[i] = this->items->operator [](start_index + i);
		}
		return new_sequence = new array_sequence<T>(tmp, count);
	}

	int get_length()
	{
		return this->items->get_size();
	}

	void prepend(T item)
	{
		int i;
		int pr_size = this->items->get_size();
		T buf[pr_size];
		for(i = 0; i < pr_size; i++)
		{
			buf[i] = this->items->operator [](i);
		}
		this->items->resize(this->items->get_size() + 1);
		this->items->set(0, item);
		for(i = 1; i <= pr_size; i++)
		{
			this->items->operator [](i) = buf[i-1];
		}
	}

	void append(T item)
	{
		int count = this->items->get_size() + 1;
		this->items->resize(count);
		this->items->set(count - 1, item);
	}

	void insert_at(T item, int index)
	{
		int i;
		int pr_size = this->items->get_size();
		T buf[pr_size - index + 1];
		for(i = index; i < pr_size; i++)
		{
			buf[i - index] = this->items->operator [](i);
		}
		this->items->set(index, item);
		this->items->resize(pr_size + 1);
		index++;
		for(i = index; i <= pr_size; i++)
		{
			this->items->operator [](i) = buf[i - index];
		}
	}

	void set(T item, int index)
	{
		this->items->set(index, item);
	}

	sequence<T>* concat(sequence<T>* sequence_)
	{
		array_sequence<T>* new_sequence;
		int i;
		int this_size = this->items->get_size();
		int new_size = this_size + sequence_->get_length();
		T buf[new_size];

		for(i = 0; i < this_size; i++)
		{
			buf[i] = this->items->operator [](i);
		}
		for(i = this_size; i < new_size; i++)
		{
			buf[i] = sequence_->operator [](i - this_size);
		}

		new_sequence = new array_sequence<T>(buf, new_size);
		return new_sequence;
	}

	 T & operator[] (int i)
	 {
		 return this->items->operator [](i);
	 }

	 void print()
	 {
		 T tmp;
		 for(int i = 0; i < this->items->get_size(); i++)
		 {
			 tmp = this->items->operator [](i);
			 cout << tmp << ' ';
		 }
		 cout << endl;
	 }


//	 ostream & operator << (ostream & out)
//	 {
//	     for (int i = 0; i < (this->items->get_length()); ++i)
//	     {
//	         out << this->items->operator [](i) << " ";
//	     }
//	     return out;
//	 }
};

//template<typename T>
//ostream & operator << (ostream & out, sequence<T> a)
//{
//    for (int i = 0; i < (a.get_length()); ++i)
//    {
//        out << a[i] << " ";
//    }
//    return out;
//}


#endif /* ARRAY_SEQUENCE_H_ */
