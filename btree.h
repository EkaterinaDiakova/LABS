
#ifndef BTREE_H_
#define BTREE_H_


#include <iostream>
#include <string>
#include <sstream>


using namespace std;

template<typename T>
class node
{
public:

	T value;
	node *left;
	node *right;

	node()
	{
		value = 0;
		left = NULL;
		right = NULL;
	}

	node(T key,node<T>* l,node<T>* r){
		value = key;
		left = l;
		right = r;
	    }
};

template<typename T>
class btree{
public:
	btree();
	~btree();

	void insert(T key);
	node<T> *search(T key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();
	void where(bool(*func)(node<T>*));
	T reduce(T(*func)(node<T>*,T));
	void map(void(*func)(node<T>*));
	void preorder_to_str(string* str);
	void postorder_to_str(string* str);
	void inorder_to_str(string* str);
	void delete_element(T key);
	bool is_subtr(btree<T>* first,btree<T>* second);
	int get_size();

private:
	void destroy_tree(node<T> *leaf);
	void insert(T key, node<T> *leaf);
	void delete_elem(T key);
	node<T> *search(T key, node<T> *leaf);
	void inorder_print(node<T> *leaf);
	void postorder_print(node<T> *leaf);
	void preorder_print(node<T> *leaf);
	void where(bool(*func)(node<T>*), node<T> *leaf);
	void reduce(T(*func)(node<T>*,T),node<T>* curr,T& curr_sum);
	void map(void(*func)(node<T>*),node<T>* curr);
	void preorder_to_str(node<T> *leaf, string* str);
	void postorder_to_str(node<T> *leaf, string* str);
	void inorder_to_str(node<T> *leaf, string* str);
	bool is_subtree(btree<T>* first,btree<T>* second);
	bool is_equals_nodes(node<T>* first,node<T>* second);
	int size;
	node<T> *root;



};

template<typename T>
btree<T>::btree(){
	root = NULL;
	size = 0;
}

template<typename T>
btree<T>::~btree(){
	destroy_tree();
}

template<typename T>
void btree<T>::destroy_tree(node<T> *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

template<typename T>
int btree<T>::get_size(){
	return this->size;
}

template<typename T>
void btree<T>::insert(T key, node<T> *leaf){
	if(key == leaf->value) return;
	if(key < leaf->value){
		if(leaf->left != NULL){
			insert(key, leaf->left);
		}else{
			leaf->left = new node<T>;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
			size++;
		}
	}else if(key >= leaf->value){
		if(leaf->right != NULL){
			insert(key, leaf->right);
		}else{
			leaf->right = new node<T>;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
			size++;
		}
	}

}


template<typename T>
void btree<T>::insert(T key){
	if(root != NULL){
		insert(key, root);
	}else{
		root = new node<T>;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
		size++;
	}
}

template<typename T>
node<T>* btree<T>::search(T key, node<T> *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return leaf;
		}
		if(key < leaf->value){
			return search(key, leaf->left);
		}else{
			return search(key, leaf->right);
		}
	}else{
		return NULL;
	}
}

template<typename T>
node<T>* btree<T>::search(T key){
	return search(key, root);
}

template<typename T>
void delete_element(T key)
{
	delete_elem(key);
}

template<typename T>
void btree<T>::destroy_tree(){
	destroy_tree(root);
}

template<typename T>
void btree<T>::inorder_print(){ // ЛКП
	inorder_print(root);
	cout << "\n";
}

template<typename T>
void btree<T>::inorder_print(node<T> *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}



template<typename T>
void btree<T>::postorder_print(){ // КПЛ
	postorder_print(root);
	cout << "\n";
}

template<typename T>
void btree<T>::postorder_print(node<T> *leaf){
	if(leaf != NULL){
		postorder_print(leaf->left);
		postorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}



template<typename T>
void btree<T>::preorder_print(){ // КЛП
	preorder_print(root);
	cout << "\n";
}

template<typename T>
void btree<T>::preorder_print(node<T> *leaf){
	if(leaf != NULL){
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}

template<typename T>
void btree<T>::preorder_to_str(string* str){ // КЛП
	preorder_to_str(root, str);

}

template<typename T>
void btree<T>::preorder_to_str(node<T> *leaf, string* str){
	std::ostringstream  ss;
	if(leaf != NULL){
		ss << leaf->value << ",";
		(*str) += ss.str();
		preorder_to_str(leaf->left, str);
		preorder_to_str(leaf->right, str);
	}
}

template<typename T>
void btree<T>::postorder_to_str(string* str){ // КПЛ
	postorder_to_str(root, str);

}

template<typename T>
void btree<T>::postorder_to_str(node<T> *leaf, string* str){
	std::ostringstream  ss;
	if(leaf != NULL){
		postorder_to_str(leaf->left, str);
		postorder_to_str(leaf->right, str);
		ss << leaf->value << ",";
		(*str) += ss.str();
	}
}

template<typename T>
void btree<T>::inorder_to_str(string* str){ // ЛКП
	inorder_to_str(root, str);

}

template<typename T>
void btree<T>::inorder_to_str(node<T> *leaf, string* str){
	std::ostringstream  ss;
	if(leaf != NULL){
		inorder_to_str(leaf->left, str);
		ss << leaf->value << ",";
		(*str) += ss.str();
		inorder_to_str(leaf->right, str);
	}
}

template<typename T>
bool btree<T>::is_equals_nodes(node<T>* first,node<T>* second){

       if(second->right == NULL && second->left == NULL && first->value == second->value){

           return true;
       }

       if(second->left != NULL && first->left == NULL){
           return false;
       }

       if(second->right != NULL && first->right == NULL)
           return false;

       if(first->value != second->value)
           return false;

       if(first->right != NULL && second->right!= NULL && second->left == NULL)
           return is_equals_nodes(first->right,second->right);

       if(first->left != NULL && second->left!= NULL && second->right == NULL)
           return is_equals_nodes(first->left,second->left);

       return false;
   }

template<typename T>
bool btree<T>::is_subtree(btree<T>* first,btree<T>* second)
{

	node<T>* curr = first->root;
	while(curr && curr->value != second->root->value){
		if(curr->value > second->root->value)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if(curr == NULL) return false;
	return is_equals_nodes(curr,second->root);
}

template<typename T>
bool btree<T>::is_subtr(btree<T>* first,btree<T>* second)
{
	return is_subtree(first, second);
}

template<typename T>
void btree<T>::delete_element(T key)
{
	delete_elem(key);
}

template<typename T>
void btree<T>::delete_elem(T key){
		node<T>* curr = root;
		node<T>* prev = NULL;

        while(curr && curr->value != key){
            prev = curr;
            if(curr->value > key){
                curr = curr->left;
            }
            else
                curr = curr->right;
        }
        if(!curr)
            return;

        if(prev == NULL)
        {
        	return;
        }

        if(prev->right == curr){
            if(curr->right == NULL && curr->left == NULL){
                prev->right = NULL;
                delete[] curr;
                size--;
                return;
            }
            if(curr->left == NULL){
                prev->right = curr->right;
                delete[] curr;
                size--;
                return;
            }
            if(curr->right == NULL){
                prev->right = curr->left;
                delete[] curr;
                size--;
                return;
            }
        }

        if(prev->left == curr){
            if(curr->right == NULL && curr->left == NULL){
                prev->left = NULL;
                delete[] curr;
                size--;
                return;
            }
            if(curr->left == NULL){
                prev->left = curr->right;
                delete[] curr;
                size--;
                return;
            }
            if(curr->right == NULL){
                prev->left = curr->left;
                delete[] curr;
                size--;
                return;
            }
        }

        node<T>* tmp = curr->right;
        while(tmp->left)
            tmp = tmp->left;

        T minimum = tmp->value;



        if(prev->left == curr){
            delete_elem(tmp->value);
            prev->left = new node<T>(minimum,curr->left,curr->right);
            delete[] curr;
            size--;
            return;
        }
        if(prev->right == curr){
            delete_elem(tmp->value);
            prev->right = new node<T>(minimum,curr->left,curr->right);
            delete[] curr;
            size--;
            return;
        }
    }

template<typename T>
void btree<T>::where(bool(*func)(node<T>*)){
		node<T>* curr = root;
        where(func,curr);
    }

template<typename T>
void btree<T>::where(bool(*func)(node<T>*),node<T>* curr){
        if(curr){
            where(func,curr->left);

            if(func(curr)){
                delete_elem(curr->value);
            }

            where(func,curr->right);
        }
    }


template<typename T>
T btree<T>::reduce(T(*func)(node<T>*,T)){
	node<T>* curr = root;
        T curr_sum = 0;
        reduce(func,curr,curr_sum);
        return curr_sum;
    }

template<typename T>
void btree<T>::reduce(T(*func)(node<T>*,T),node<T>* curr,T& curr_sum){
        if(curr){
            reduce(func,curr->left,curr_sum);
            curr_sum = func(curr,curr_sum);
            reduce(func,curr->right,curr_sum);
        }
    }

template<typename T>
void btree<T>::map(void(*func)(node<T>*)){
		node<T>* curr = root;
        map(func,curr);
    }

template<typename T>
void btree<T>::map(void(*func)(node<T>*),node<T>* curr){
    if(curr){
        map(func ,curr->left);
        func(curr);
        map(func,curr->right);
    }
}


#endif /* BTREE_H_ */
