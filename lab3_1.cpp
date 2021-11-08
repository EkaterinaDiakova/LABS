#include<iostream>
#include<stdio.h>
#include"dynamic_array.h"
#include"linked_list.h"
#include"Sequence.h"
#include"array_sequence.h"
#include"linked_list.h"
#include"applicate.h"
#include"container.h"
#include"linked_list_sequence.h"

using namespace std;

void get_types(int& data_type, int& realisation_type)
{
	data_type = 0;
	realisation_type = 0;
	do{
		cout << "Enter data type(1-int/2-float)->";
		cin >> data_type;
		cout << endl;
	}while(data_type != 1 && data_type != 2);
	do{
		cout << "Enter realisation type(1-array/2-list)->";
		cin >> realisation_type;
		cout << endl;
	}while(realisation_type != 1 && realisation_type != 2);
}
int main()
{
	int flag = 1;
	int data_type = 1;
	int realisation_type = 1;

	while (flag == 1)
	{
		get_types(data_type, realisation_type);
		if(data_type == 1)
		{
			if(realisation_type == 1)
			{
				Applicate<int, array_sequence<int>> application;
				flag = application.run(data_type, realisation_type);
			}
			else if(realisation_type == 2)
			{
				Applicate<int, linked_list_sequence<int>> application;
				flag = application.run(data_type, realisation_type);
			}
		}
		else if(data_type == 2)
		{
			if(realisation_type == 1)
			{
				Applicate<float, array_sequence<float>> application;
				flag = application.run(data_type, realisation_type);
			}
			else if(realisation_type == 2)
			{
				Applicate<float, linked_list_sequence<float>> application;
				flag = application.run(data_type, realisation_type);
			}
		}
	}
	return 0;
}
