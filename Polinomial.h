#ifndef POLINOMIAL_H_
#define POLINOMIAL_H_

#include<iostream>
#include<stdio.h>
#include<math.h>
#include"dynamic_array.h"
#include"linked_list.h"
#include"Sequence.h"
#include"array_sequence.h"
#include"linked_list_sequence.h"
#include"linked_list.h"

using namespace std;

template <typename T,typename T2>
class polinomial
{
private:
	sequence<T>* items;
public:
	polinomial()
	{
		items = new T2();
	}

	polinomial(T* item, int count)
	{
		items = new T2(item, count);
	}

	polinomial(const polinomial<T,T2> & a)
	{
		int count = a.items->get_length();
		T* buf = new T[count];
		for(int i = 0; i < count; i++)
		{
			buf[i] = a.items->operator [](i);
		}
		this->items = new T2(buf, count);
		delete [] buf;
	}

	~polinomial()
	{
		delete items;
	}

	polinomial<T,T2>* operator+ (polinomial<T,T2>& pol_2)
	{
		int count = max(this->items->get_length(), pol_2.items->get_length());
		T buf[count];
		for(int i = 0; i < count; i++)
		{
			buf[i] = this->items->operator [](0) - this->items->operator [](0);
		}

		for(int i = 0; i < count; i++)
		{
			if(i < this->items->get_length()) buf[i] += this->items->operator [](i);
			if(i < pol_2.items->get_length()) buf[i] += pol_2.operator [](i);
//			{
//				if(i <= this->items->get_length())
//				buf[i]+= this->items->operator [](i);
//				else buf[i]= this->items->operator [](i);
//			}
		}
		polinomial<T,T2>* res = new polinomial<T,T2>(buf, count);
		return res;
	}

	polinomial<T,T2>* operator* (polinomial<T,T2>& pol_2)
	{
		int count = this->items->get_length() * pol_2.items->get_length();
		T buf[count];
		for(int i = 0; i < count; i++)
		{
			buf[i] = this->items->operator [](0) - this->items->operator [](0);
		}
		int len = 0;
		for(int i = 0; i < this->items->get_length(); i++)
		{
			for(int j = 0; j < pol_2.items->get_length(); j++)
			{
				len = max(len, (i + j + 1));
				buf[i + j] += this->items->operator [](i) * pol_2.items->operator [](j);
			}
		}
		polinomial<T,T2>* res = new polinomial<T,T2>(buf, len);
		return res;
	}

	T argument(T arg)
	{
		T tmp = this->items->operator [](0);
		for(int i = 1; i < this->items->get_length(); i++)
		{
			tmp += pow(arg, i) * this->items->operator [](i);
		}
		return tmp;
	}

	polinomial<T,T2>* composition(polinomial<T,T2>* pol_2, T arg)
	{
		polinomial<T,T2>* res;
		T tmp[1];
		tmp[0] = this->argument(arg);
		tmp[0] = pol_2->argument(tmp[0]);
		return res = new polinomial<T,T2>(tmp, 1);
	}

	int get_length()
	{
		int len = this->items->get_length();
		return len;
	}

	T get_first()
	{
		return this->items->get_first();
	}

	void print_string()
	{
	//	if(this == NULL) return;
		int count = this->get_length();
		T tmp;

		for(int i = 0; i < count; i++)
		{
			tmp = this->items->operator [](i);
			cout << '(' << tmp << ')';
			cout << "X^" << i;
			if(i != (count - 1)) cout << "+";
		}
		cout << endl;
	}

	T & operator[] (int i)
	{
	 return this->items->operator [](i);
	}
};

template<typename T, typename T2>
ostream & operator << (ostream & out, polinomial<T,T2> a)
{
    for (int i = 0; i < (a.get_length()); ++i)
    {
        out << a[i] << " ";
    }
    return out;
}




#endif /* POLINOMIAL_H_ */
