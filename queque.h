#ifndef QUEQUE_H_
#define QUEQUE_H_


#include<iostream>
#include"dynamic_array.h"
#include"Sequence.h"

using namespace std;

template <typename T>
class queque : public sequence<T>
{
private:
	dynamic_array<T>* items;

	T get(int index)
	{
		return this->items->operator [](index);
	}

	T get_first()
	{
		return this->items->operator [](0);
	}

	T get_last()
	{
		return this->items->operator [](items->get_size() - 1);
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

	void Remove()
	{
		int i;
		T buf[this->items->get_size() - 1];
		for(i = 1; i < this->items->get_size(); i++)
		{
			buf[i] = this->items->operator [](i);
		}
		this->items->resize(this->items->get_size() - 1);
		for(i = 0; i < this->items->get_size() - 1; i++)
		{
			this->items->set(i, buf[i]);
		}
	}

public:
	queque()
	{
		this->items = new dynamic_array<T>();
		//this->items->dynamic_array();
	}

	queque(T* item, int count)
	{
		//items = new dynamic_array<T>(item, count);
		this->items = new dynamic_array<T>(item, count);
	}

	queque(const dynamic_array<T> & a)
	{
		this->items = new dynamic_array<T>(a);
	}

	~queque()
	{
		this->items->~dynamic_array();
	}

	sequence<T>* get_sub_sequence(int start_index, int end_index)
	{
		queque<T>* new_sequence;
		int count = (end_index - start_index) + 1;
		T tmp[count];
		for(int i = 0; i < count; i++)
		{
			tmp[i] = this->items->operator [](start_index + i);
		}
		return new_sequence = new queque<T>(tmp, count);
	}

	int get_length()
	{
		return this->items->get_size();
	}

	void set(T item, int index)
	{
		this->items->set(index, item);
	}

	sequence<T>* concat(sequence<T>* sequence_)
	{
		queque<T>* new_sequence;
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

		new_sequence = new queque<T>(buf, new_size);
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

	 T Peek(const int i)
	 {
		 return this->get(i);
	 }

	 T PeekFirst()
	 {
		 return this->get_first();
	 }

	 T PeekLast()
	 {
		 return this->get_last();
	 }

	 void Enqueue(T item, int priority)
	 {
		 if (priority == 0) this->prepend(item);
		 else if(priority >= (this->get_length()-1)) this->append(item);
		 else this->insert_at(item, priority);
	 }

	 T Dequeue()
	 {
		 T tmp;
		 tmp = this->get_first();
		 Remove();
		 return tmp;
	 }

};


#endif /* QUEQUE_H_ */
