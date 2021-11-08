#ifndef APPLICATE_H_
#define APPLICATE_H_

#include <iostream>
#include <fstream>
#include "container.h"


using namespace std;
#define MAX_BUF_LENGTH = 1080

template <typename T,typename T2>
class Applicate
{
	container<T,T2>* cur_container;
	int sort_type = 1;


public:

	Applicate()
	{
		this->cur_container = new container<T,T2>();
	}

	Applicate(const Applicate<T,T2> & a)
	{
		this->cur_container = new container<T,T2>(*(a.cur_container));
	}
	~Applicate()
	{
		delete  cur_container;
	}

	int run(int data_type, int realisation_type )
	{
		int choice;
		T* buf;
		while(1)
		{
			cout << "\nMain menu" << endl;
			cout << "Input data: ";
			if(cur_container != NULL && cur_container->if_sorted != 3) cur_container->print_items();
			cout << endl;
			cout << "Sorted data: ";
			if(cur_container != NULL && cur_container->if_sorted == 1) cur_container->print_sort_items();
			cout << endl;
			if (this->cur_container->if_sorted == 1) cout << "Lead time: " << this->cur_container->lead_time << "us";
			cout << endl;
			cout << "Data type: " << data_type << "         (1-int/2-float)" << endl;
			cout << "Realisation type: " << realisation_type << "  (1-dynamic array/2-linked list)";
			cout << endl;
			cout << endl;
			cout << "1. Sort type: " ;
			if (this->cur_container->if_sorted == 1)	cout << this->sort_type;
			cout << "        (1-quick/2-shaker)";
			cout << endl;
			cout << "2. New input data" << endl;
			cout << "3. Change sistem types" << endl;
			cout << "4. New input from file" << endl;
			cout << "5. Generate sequence" << endl;
			cout << "6. Test" << endl;
			cout << endl;
			cout << "7. Quite" << endl;

			switch(choice = menu(7))
			{
				case 1:
					cout << "Get sort type " << endl;
					cout << "Enter sort type-> " << endl;
					cin >> this->sort_type;
					this->cur_container->sort(sort_type, cmp1);
					break;
				case 2:
					cout << "Get container " << endl;
					this->get_container();
					break;
				case 3:
					return 1;
				case 4:
					cout << "Input data from file <input_data.txt>";
					get_cont_from_file();
					break;
				case 5:
					cout << "Enter number of elements->" << endl;
					cin >> choice;
					buf = generate_container(choice);
					create(buf, choice);
					break;
				case 6:
					cout << "Test" << endl;
					test();
					break;
				case 7:
					cout << "Quite" << endl;
					return 0;
			}

		}
		return 0;
	}

	int choose()
	{
		int choice = 0;
		do{
			cout << "Make your choice->";
			cin >> choice;
			cout << endl;
		}while(choice != 1 && choice != 2);
		return choice;
	}


	int menu(int n)
	{
		char choice;
		do {
			cout << "\nMake your choice> ";
			cin >> choice;
			if ((choice == 'Q') || (choice == 'T')) return choice;
			choice -= '0';
		} while (choice < 1 || choice > n);
	return choice;
	}

	void get_container()
	{
		int count;
		cout << "Enter the number of elements in the array->";
		cin >> count;
		if(count <= 0) return;
		T* buf = new T[count];
		cout << "Enter the value of the element: ";
		cout << endl;
		for(int i = 0; i < count; i++)
		{
			cout << "Enter a" << i << "->";
			cin >> buf[i];
			cout << endl;
		}
		create(buf, count);
		delete [] buf;
	}

	void get_cont_from_file()
	{
		int count = 0;
		ifstream fin("input_data.txt");
		if (!fin.is_open()) cout << "File can not be opened!\n";
		else
		{
		    fin >> count;
		   // cout << "the number of elements in the array: " << count << endl;
		    T* buf = new T[count];
			for(int i = 0; i < count; i++)
			{
				fin >> buf[i];
			}
			create(buf, count);
			delete [] buf;
			fin.close();
		}
	}

	T* generate_container(int count)
	{
		T* buf = new T[count];
		for(int i = 0; i < count; i++)
		{
			buf[i] = static_cast <T> (rand()) / (static_cast <float> (RAND_MAX/100));
		}
//		create(buf, count);
//		delete [] buf;
		return buf;
	}

	void test()
	{
		T* buf;
		cout << "amount / time(us)|quick(n,->,<-)|shaker(n,->,<-)|" << endl;
		for(int i = 1000; i <= 10000; i+=1000)
		{
			buf = generate_container(i);

			create(buf,i);
			this->cur_container->sort(1, cmp);// сортировка 1 на неотсортированном массиве
			cout  << i << " " << this->cur_container->lead_time;
			this->cur_container->sort(1, cmp);// сортировка на отсорт. в прямом порядке
			cout << " " << this->cur_container->lead_time;
			this->cur_container->sort(1, cmp2);// сортировка на отсорт. в обр. порядке
			cout << " " << this->cur_container->lead_time;

			create(buf,i);
			this->cur_container->sort(2, cmp);// сортировка 1 на неотсортированном массиве
			cout << " " << this->cur_container->lead_time;
			this->cur_container->sort(1, cmp);// сортировка на отсорт. в прямом порядке
			cout << " " << this->cur_container->lead_time;
			this->cur_container->sort(1, cmp2);// сортировка на отсорт. в обр. порядке
			cout << " " << this->cur_container->lead_time;
			cout << endl;
			delete [] buf;
		}
		this->cur_container->if_sorted = 3;
	}

	void create(T* buf, int count)
	{
		delete  this->cur_container;
		this->cur_container = new container<T,T2>(buf,count);
	}

	static int cmp(T a, T b)
	{
		return a > b;
	}

	static int cmp2(T a, T b)
	{
		return a < b;
	}


};







#endif /* APPLICATE_H_ */
