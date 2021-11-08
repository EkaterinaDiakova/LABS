#ifndef CONTAINER_H_
#define CONTAINER_H_

#include<iostream>
#include<stdio.h>
#include<ctime>
#include"dynamic_array.h"
#include"linked_list.h"
#include"Sequence.h"
#include"array_sequence.h"
#include"linked_list_sequence.h"
#include"linked_list.h"

using namespace std;

template <typename T,typename T2>
class container
{
private:
	sequence<T>* items;
	sequence<T>* sorted_items;


public:
	int if_sorted = 0;
	float lead_time = 0;

	container()
	{
		items = new T2();
		sorted_items = new T2();
	}

	container(T* item, int count)
	{
		items = new T2(item, count);
		sorted_items = new T2(item, count);
	}

	container(const container<T,T2> & a)
	{
		int count = a.items->get_length();
		T* buf = new T[count];
		for(int i = 0; i < count; i++)
		{
			buf[i] = a.items->operator [](i);
		}
		this->items = new T2(buf, count);
		delete [] buf;
		count = a.sorted_items->get_length();
		buf = new T[count];
		for(int i = 0; i < count; i++)
		{
			buf[i] = a.sorted_items->operator [](i);
		}
		this->sorted_items = new T2(buf, count);
		delete [] buf;
		a.if_sorted = this->if_sorted;

	}

	~container()
	{
		delete items;
		delete sorted_items;
	}

	void sort(int sort_type, int (*cmp)(T,T))
	{
		float start, end;
		switch(sort_type){
		case 1:
			start = clock();
			quick_sort(0, this->sorted_items->get_length() - 1, cmp);
			end = clock();
			this->lead_time = ((end - start) / CLOCKS_PER_SEC) * 1000000;
			this->if_sorted = 1;
			break;
		case 2:
			start = clock();
			shaker_sort(cmp);
			end = clock();
			this->lead_time = ((end - start) / CLOCKS_PER_SEC) * 1000000;
			this->if_sorted = 1;
			break;
		case 3:
			break;
		}
	}

	void shaker_sort(int (*cmp)(T,T))
	{
		int left = 0;
		int right = this->sorted_items->get_length() - 1;
		int flag = 1;
		T tmp;

		while ((left < right) && flag > 0)
		{
			flag = 0;
			for (int i = left; i<right; i++)  //двигаемся слева направо
			{
			  if (cmp(this->sorted_items->get(i) , this->sorted_items->get(i + 1))) // если следующий элемент меньше текущего,
			  {             // меняем их местами
				tmp = this->sorted_items->get(i);
				this->sorted_items->set(this->sorted_items->get(i + 1), i);
				this->sorted_items->set(tmp, i + 1);
				flag = 1;      // перемещения в этом цикле были
			  }
			}
			right--; // сдвигаем правую границу на предыдущий элемент
			for (int i = right; i>left; i--)  //двигаемся справа налево
			{
			  if (cmp(this->sorted_items->get(i - 1) , this->sorted_items->get(i))) // если предыдущий элемент больше текущего,
			  {            // меняем их местами
				tmp = this->sorted_items->get(i);
				this->sorted_items->set(this->sorted_items->get(i - 1), i);
				this->sorted_items->set(tmp, i - 1);
				flag = 1;    // перемещения в этом цикле были
			  }
			}
			left++; // сдвигаем левую границу на следующий элемент
		}

	}


	void quick_sort(int left, int right, int (*cmp)(T,T))
	{
	  T pivot; // разрешающий элемент
	  int l_hold = left; //левая граница
	  int r_hold = right; // правая граница
	  pivot = this->sorted_items->get(left);
	  while (left < right) // пока границы не сомкнутся
	  {
	    while (cmp(this->sorted_items->get(right) , pivot) && (left < right))
	    {
	      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
	    }
	    if (left != right) // если границы не сомкнулись
	    {
	    	this->sorted_items->set(this->sorted_items->get(right), left); // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо
	    }
	    while (cmp(pivot , this->sorted_items->get(left)) && (left < right))
	    {
	    	left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
	    }

	    if (left != right) // если границы не сомкнулись
	    {
	    	this->sorted_items->set(this->sorted_items->get(left), right); // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо
	    }
	  }
	  this->sorted_items->set(pivot, left); // ставим разрешающий элемент на место
	  pivot = left;
	  left = l_hold;
	  right = r_hold;
	  if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
	    quick_sort(left, pivot - 1, cmp);
	  if (right > pivot)
		quick_sort(pivot + 1, right, cmp);
	}

//	void shaker_sort()
//	{
//
//	}

	T & operator[] (int i)
	{
	 return this->items->operator [](i);
	}

	void print_items()
	{
		this->items->print();
	}

	void print_sort_items()
	{
		this->sorted_items->print();
	}
};


#endif /* CONTAINER_H_ */
