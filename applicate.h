#ifndef APPLICATE_H_
#define APPLICATE_H_

#include <iostream>
#include <string>
#include "Polinomial.h"

using namespace std;
#define MAX_BUF_LENGTH = 1080

template <typename T,typename T2>
class Applicate
{
	polinomial<T,T2>* polinomial_1;
	polinomial<T,T2>* polinomial_2;
	polinomial<T,T2>* result;

	T arg;


public:

	Applicate()
	{
		this->polinomial_1 = new polinomial<T, T2>();
		this->polinomial_2 = new polinomial<T, T2>();
		this->result = new polinomial<T, T2>();
		this->arg = arg - arg;
	}

	Applicate(const Applicate<T,T2> & a)
	{
		this->polinomial_1 = new polinomial<T,T2>(*(a.polinomial_1));
		this->polinomial_2 = new polinomial<T,T2>(*(a.polinomial_2));
		this->result = new polinomial<T,T2>(*a.result);
		this->arg = a.arg;
	}
	~Applicate()
	{
		delete  polinomial_1;
		delete  polinomial_2;
		delete  result;
	}

	int run(int data_type, int realisation_type )
	{
		int choice;
		int choice_1;
		T tmp;

		while(1)
		{
			cout << "\nMain menu" << endl;
			cout << "1. Polinomial 1: ";
			if(polinomial_1 != NULL) polinomial_1->print_string();
			cout << endl;
			cout << "2. Polinomial 2: ";
			if(polinomial_2 != NULL) polinomial_2->print_string();
			cout << endl;
			cout << "3. Change types" << endl;
			cout << "Data type: " << data_type << " (1-int/2-float)" << endl;
			cout << "Realisation type:" << realisation_type << " (1-dynamic array/2-linked list)";
			cout << endl;
			cout << "4.Argument: " << this->arg;
			cout << endl;
			cout << "Operations:" << endl;
			cout << "5. +" << endl;
			cout << "6. *" << endl;
			cout << "7. Composition" << endl;
			cout << "8. Computing by an argument" << endl;
			cout << "Current result: " << endl;
			if(result != NULL) result->print_string();
		//	cout << "T. Test" << endl;
			cout << "Q. Quite" << endl;

			switch(choice = menu(9))
			{
				case 1:
					cout << "Get polinomial 1" << endl;
					this->get_polinomial(1);
					break;
				case 2:
					cout << "Get polinomial 2" << endl;
					this->get_polinomial(2);
					break;
				case 3:
					return 1;

				case 4:
					cout << "Get argument" << endl;
					cout << "Enter argument->";
					cin >> this->arg;
					cout << endl;
					break;
				case 5:
					cout << "Sum" << endl;
					delete  this->result;
					result = *polinomial_1 + *polinomial_2;
					break;
				case 6:
					cout << "Multiplication" << endl;
					delete  this->result;
					result = *polinomial_1 * *polinomial_2;
					break;
				case 7:
					cout << "Composition" << endl;
					cout << "Choose: 1.(pol1)o(pol2)/2.(pol2)o(pol1)";
					choice_1 = choose();
					if(choice_1 == 1) result = polinomial_1->composition(polinomial_2, this->arg);
					if(choice_1 == 2) result = polinomial_2->composition(polinomial_1, this->arg);
					break;
				case 8:
					cout << "Computing by an argument" << endl;
					cout << "Choose: 1.(pol1)/2.(pol2)";
					choice_1 = choose();
					delete  result;
					if(choice_1 == 1)
						{
							tmp = polinomial_1->argument(this->arg);
							result = new polinomial<T,T2>(&(tmp),1);
						}
					if(choice_1 == 2)
					{
						{
							tmp = polinomial_1->argument(this->arg);
							result = new polinomial<T,T2>(&(tmp),1);
						}
					}
					break;
				case 36:
					cout << "Test" << endl;
					break;
				case 33:
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
	void get_polinomial(int number)
	{
		int count;
		cout << "Enter number of polynomial term->";
		cin >> count;
		if(count <= 0) return;
		T* buf = new T[count];
		cout << "Enter polynomial coefficients: ";
		cout << endl;
		for(int i = 0; i < count; i++)
		{
			cout << "Enter a" << i << "->";
			cin >> buf[i];
			cout << endl;
		}
		if(number == 1)
		{
			delete  this->polinomial_1;
			this->polinomial_1 = new polinomial<T,T2>(buf,count);
		}
		else if(number == 2)
		{
			delete  this->polinomial_2;
			this->polinomial_2 = new polinomial<T,T2>(buf,count);
		}

		delete [] buf;
	}

	int menu(int n)
	{
		int choice, j;
	//	char* error = "";

		j = 0;

		do {
//			cout << error << endl;
//			error = "\nYou're wrong. Try again!\n";
			cout << "\nMake your choice> ";
			choice = getchar() - '0';
			if (((choice == 33) || (choice == 36)) && (n > 2)) return choice;
			while (getchar() != '\n') j++;
			if(j != 0) continue;
		} while (choice < 1 || choice > n);
		return choice;
	}

};







#endif /* APPLICATE_H_ */
