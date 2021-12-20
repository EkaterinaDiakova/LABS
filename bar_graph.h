#ifndef BAR_GRAPH_H_
#define BAR_GRAPH_H_

#include "Idictionary.h"
#include<iostream>
#include "dictionary_tree.h"

using namespace std;

template<typename TK, typename TV>
class bar_graph
{
	TV* input;
	IDictionary<TK, TV>* output;
	int input_count;
	int	bottom_bound;
	int upper_bound;
	int fragmentation;
	float columns_amount;

public:

	bar_graph()
	{
		input = NULL;
		output = NULL;
		bottom_bound = 0;
		upper_bound = 0;
		fragmentation = 0;
		input_count = 0;
		columns_amount = 0;
	}

	bar_graph(TV* input)
	{
		this->input = input;
		output = NULL;
		bottom_bound = 0;
		upper_bound = 0;
		fragmentation = 0;
		input_count = 0;
		columns_amount = 0;
	}

//	bar_graph(bar_graph<TK,TV>& a)
//	{
//
//	}
	~bar_graph()
	{
		delete input;
		delete output;
	}

	void calc_bar_graph()
	{
		output = new DictionaryTree<int,int>();
		this->columns_amount = ((float)(upper_bound - bottom_bound)/fragmentation) + 1;
		if((columns_amount - (int)columns_amount) != 0) columns_amount = (int)columns_amount + 1;
//		int* columns = calloc((int)columns_amount, sizeof(int));
		int* columns = new int[(int)columns_amount]();
		int tmpl = bottom_bound;
		int tmpr = tmpl + fragmentation;
		for(int j = 0; j < columns_amount; j++)
		{
			for(int i = 0; i < input_count; i++)
			{
				if(input[i] >= bottom_bound &&
				   input[i] <= upper_bound &&
				   input[i] >= tmpl &&
				   input[i] < tmpr)
				{
					columns[j]++;
				}
			}
			output->Add(j, columns[j]);
			tmpl = tmpr;
			tmpr += fragmentation;
		}
	}

	void get_bar_graph()
	{
		int count;
		cout << "Enter the number of elements->";
		cin >> count;
		if(count <= 0) return;
		TV* buf = new TV[count];
		cout << "Enter the value of the element:";
		cout << endl;
		for(int i = 0; i < count; i++)
		{
			cout << "Enter a" << i << "->";
			cin >> buf[i];
			cout << endl;
		}
		this->input = buf;
		this->input_count = count;
		cout << "Enter the lower limit of the range->";
		cin >> this->bottom_bound;
		cout << endl;
		cout << "Enter the upper limit of the range->";
		cin >> this->upper_bound;
		cout << endl;
		cout << "Enter the fragmentation->";
		cin >> this->fragmentation;
		cout << endl;
	}

	void print_bar_graph()
	{
		cout << "BAR_GRAPH" << endl;
		for(int j = 0; j < this->columns_amount; j++)
		{
			cout << "column #" << j << "->";
			cout << this->output->Get(j);
			cout << endl;
		}
	}

	void get_cont_from_file()
		{
			ifstream fin("input_data.txt");
			if (!fin.is_open()) cout << "File can not be opened!\n";
			else
			{
			    fin >> this->input_count;
			    fin >> this->bottom_bound;
			    fin >> this->upper_bound;
			    fin >> this->fragmentation;

			    TV* buf = new TV[this->input_count];
				for(int i = 0; i < this->input_count; i++)
				{
					fin >> buf[i];
				}
				create(buf, this->input_count);
				this->input = buf;
				fin.close();
			}
		}
};

#endif /* BAR_GRAPH_H_ */
