#include <iostream>

#include "bar_graph.h"
#include "Idictionary.h"
#include "dictionary_tree.h"
#include "sparse_vector.h"

using namespace std;

int main()
{
	int choice;
	bar_graph<int, int>* graph;
	sparse_vector<int,int>* input;

	while(1)
	{
		cout << endl;
		cout << "1. Bar graph" << endl;
		cout << "2. Sparse vector" << endl;
		cout << "3. Quite" << endl << endl;
		cout << "Make your choice->";
		cin >> choice;
		cout << endl;
		switch(choice)
		{
		case 1:
			graph = new bar_graph<int, int>();
			graph->get_bar_graph();
			graph->calc_bar_graph();
			graph->print_bar_graph();
			delete graph;
			break;
		case 2:
			input = new sparse_vector<int,int>();
			input->get_input();
			input->get_output();
			input->print();
			delete input;
			break;
		case 3:
			return 0;
		}
	}
	return 0;
}

