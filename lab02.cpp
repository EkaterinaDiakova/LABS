#include <iostream>
#include <string>
#include<iostream>
#include<stdio.h>
#include<math.h>
#include"dynamic_array.h"
#include"linked_list.h"
#include"Sequence.h"
#include"array_sequence.h"
#include"linked_list.h"
#include"applicate.h"
#include"Polinomial.h"
#include"linked_list_sequence.h"

using namespace std;

void get_types(int& data_type, int& realisation_type)
{
	data_type = 0;
	realisation_type = 0;
	do{
		cout << "Enter data type->";
		cin >> data_type;
		cout << endl;
	}while(data_type != 1 && data_type != 2);
	do{
		cout << "Enter realisation type->";
		cin >> realisation_type;
		cout << endl;
	}while(data_type != 1 && data_type != 2);
}
int main()
{
	int data_type = 1;
	int realisation_type = 1;

	get_types(data_type, realisation_type);
	if(data_type == 1)
	{
		if(realisation_type == 1)
		{
			Applicate<int, array_sequence<int>> application;
			application.run(data_type, realisation_type);
		}
		else if(realisation_type == 2)
		{
			Applicate<int, linked_list_sequence<int>> application;
			application.run(data_type, realisation_type);
		}
	}
	else if(data_type == 2)
	{
		if(realisation_type == 1)
		{
			Applicate<float, array_sequence<float>> application;
			application.run(data_type, realisation_type);
		}
		else if(realisation_type == 2)
		{
			Applicate<float, linked_list_sequence<float>> application;
			application.run(data_type, realisation_type);
		}
	}




	return 0;
}
