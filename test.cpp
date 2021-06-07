#include <iostream>
#include <string>
#include <sstream>
#include"btree.h"

/************************* функции обработчики *************************************/

template<typename T>
void sqr(node<T>* curr){//(для Map)
    curr->value = curr->value * curr->value;
}

template<typename T>
T sum(node<T>* curr,T curr_sum){//(для Reduce)
    return curr_sum + curr->value;
}

template<typename T>
bool is_more_than_25(node<T>* curr){//для удаления всех элементов больших 25 (для Where)
    if(curr->value >= 25)
        return true;
    return false;
}


using namespace std;
int main1()
{

	btree<int> *tree = new btree<int>();
	string str;

	tree->insert(11);
	tree->insert(5);
	tree->insert(14);
	tree->insert(26);
	tree->insert(8);
	tree->insert(11);
	tree->insert(26);

	tree->preorder_print(); //КЛП
	tree->preorder_to_str(&str);
	cout << str << endl;
	str.clear();

	tree->inorder_print(); //ЛКП
	tree->inorder_to_str(&str);
	cout << str << endl;
	str.clear();

	tree->postorder_print(); //КПЛ
	tree->postorder_to_str(&str);
	cout << str << endl;
	str.clear();

	cout << endl;

	tree->where(is_more_than_25);
	tree->preorder_print();

	cout << tree->search(5)->value << endl;


	cout << tree->reduce(sum<int>);
	cout << endl;

	tree->map(sqr<int>);
	tree->preorder_print();


	delete tree;

}
