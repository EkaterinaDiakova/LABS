#ifndef APPLICATE_H_
#define APPLICATE_H_

#include <iostream>
#include <string>
#include"btree.h"

using namespace std;
#define MAX_BUF_LENGTH

void test();

template <typename T>
class Applicate
{
	btree<T>*tree;
	btree<T>*tmp_tree;
	string str;

public:

	Applicate()
	{
		this->tree = new btree<T>();
		this->tmp_tree = new btree<T>();
	}


	~Applicate()
	{
		delete  tree;
		delete  &str;

	}

	int run(int data_type)
	{
		int choice;
		T tmp;

		while(1)
		{
			cout << "\nMain menu" << endl;
			cout << "1.Tree(preoder): ";
			if(tree != NULL) tree->preorder_print();
			cout << "2.Change types --- ";
			cout << "current data type: " << data_type << " (1-int/2-float)" << endl;
			cout << "3.Postoder print" << endl;
			cout << "4.Inoder print" << endl << endl;
			cout << "Operations:" << endl;
			cout << "5.Insert node" << endl;
			cout << "6.Find node" << endl;
			cout << "7.Delete node" << endl;
			cout << "8.Find subtree" << endl;
			cout << "T. Test" << endl;
			cout << "Q.Quite" << endl;

			switch(choice = menu(9))
			{
				case 1:
					cout << "Get tree" << endl;
					this->get_tree(1);
					break;
				case 2:
					return 1;
				case 3:
					tree->postorder_print();
					break;
				case 4:
					tree->inorder_print();
					break;
				case 5:
					cout << "Enter node->" << endl;
					cin >> tmp;
					tree->insert(tmp);
					break;
				case 6:
					cout << "Enter node->" << endl;
					cin >> tmp;
					if(tree->search(tmp) != NULL)
					{
						cout << "is found" << endl;
					}else cout << "is not found" << endl;
					getchar();
					getchar();
					//cin >> tmp;
					break;
				case 7:
					cout << "Enter node->" << endl;
					cin >> tmp;
					tree->delete_element(tmp);
					break;
				case 8:
					cout << "Get subtree" << endl;
					this->get_tree(2);
					if(tree->is_subtr(tree, tmp_tree))
					{
						cout << "is subtree" << endl;
					}else cout << "is not subtree" << endl;
					getchar();
					getchar();
					//cin >> tmp;
					break;
				case 'T':
					cout << "Test" << endl;
					test();
					break;
				case 'Q':
					cout << "Quite" << endl;
					return 0;
			}

		}
		return 0;
	}

//	int choose()
//	{
//		int choice = 0;
//		do{
//			cout << "Make your choice->";
//			cin >> choice;
//			cout << endl;
//		}while(choice != 1 && choice != 2);
//		return choice;
//	}

	void get_tree(int number)
	{
		int count;
		cout << "Enter number of tree term->";
		cin >> count;
		if(count <= 0) return;
		T* buf = new T[count];
		cout << "Enter tree terms: ";
		cout << endl;
		for(int i = 0; i < count; i++)
		{
			cout << "Enter a" << i << "->";
			cin >> buf[i];
			cout << endl;
		}
		if(number == 1)
		{
			delete  this->tree;
			this->tree = new btree<T>();
			for(int i = 0; i < count; i++)
			{
				tree->insert(buf[i]);
			}
		}
		else if(number == 2)
		{
			delete  this->tmp_tree;
			this->tmp_tree = new btree<T>();
			for(int i = 0; i < count; i++)
			{
				tmp_tree->insert(buf[i]);
			}
		}


		delete [] buf;
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

};







#endif /* APPLICATE_H_ */
