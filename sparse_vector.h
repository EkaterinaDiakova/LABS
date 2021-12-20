#ifndef SPARSE_VECTOR_H_
#define SPARSE_VECTOR_H_

#include "Idictionary.h"
#include<iostream>
#include "dictionary_tree.h"

using namespace std;

template<typename TK, typename TV>
class sparse_vector
{
	IDictionary<TK, TV>* input;
	IDictionary<TK, TV>* output;
	TK MaxKey;
	int in_len;
	int out_len;
public:
	sparse_vector()
	{
		input = NULL;
		output = NULL;
		MaxKey = 0;
		in_len = 0;
		out_len = 0;
	}

	~sparse_vector()
	{
		delete(input);
		delete(output);
	}

	void get_input()
	{
		int size = 0;
		TK KeyTmp;
		TV ValueTmp;

		MaxKey = 0;

		input = new DictionaryTree<TK, TV>();
		cout << "Enter number of elements->";
		cin >> size;
		cout << endl;
		for(int i = 0; i < size; i++)
		{
			cout << "Enter the index->";
			cin >> KeyTmp;
			cout << endl;
			cout << "Enter the value->";
			cin >> ValueTmp;
			cout << endl;
			input->Add(KeyTmp, ValueTmp);
			if(KeyTmp > MaxKey) MaxKey = KeyTmp;
		}
		out_len = MaxKey + 1;
		in_len = size;
	}

	void get_output()
	{
		output = new DictionaryTree<TK, TV>();
		for(int i = 0; i <= MaxKey; i++)
		{
			if(input->ContainsKey(i)) output->Add(i, input->Get(i));
			else output->Add(i, 0);
		}
	}

	void print()
	{
		cout << "INPUT:" << endl;
		for(int i = 0; i < this->out_len; i++)
		{
			if(this->input->ContainsKey(i)) cout << this->input->Get(i) << " ";
		}
		cout << endl << endl;
		cout << "OUTPUT:" << endl;
		for(int i = 0; i < this->out_len; i++)
		{
			cout << this->output->Get(i) << " ";
		}
		cout << endl;
	}

	void get_cont_from_file()
		{
			TK KeyTmp;
			TV ValueTmp;
			ifstream fin("input_data2.txt");
			if (!fin.is_open()) cout << "File can not be opened!\n";
			else
			{
			    fin >> this->in_len;
				for(int i = 0; i < this->in_len; i++)
				{
					cin >> KeyTmp;
					cin >> ValueTmp;
					input->Add(KeyTmp, ValueTmp);
					if(KeyTmp > MaxKey) MaxKey = KeyTmp;
				}
				out_len = MaxKey + 1;
				fin.close();
			}
		}
};
#endif /* SPARSE_VECTOR_H_ */
