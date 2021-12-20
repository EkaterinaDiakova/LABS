#include <iostream>

#include "bar_graph.h"
#include "Idictionary.h"
#include "dictionary_tree.h"
#include "sparse_vector.h"
#include <fstream>

using namespace std;



int main()
{
	IDictionary<int, int>* input;
	input = new DictionaryTree<int, int>();
	for(int i = 0; i < 10; i++)
	{
		input->Add(i, (10*i));
	}
	input->Print();

	bar_graph<int, int>* graph;
	graph = new bar_graph<int, int>();
	graph->get_cont_from_file();
	graph->calc_bar_graph();
	graph->print_bar_graph();

	sparse_vector<int,int>* vector;
	vector = new sparse_vector<int,int>();
	vector->get_cont_from_file();
	vector->get_output();
	vector->print();
	getchar();
	return 0;
}

