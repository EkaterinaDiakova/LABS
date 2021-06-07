#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include<iostream>

using namespace std;

template <typename T>
class linked_list
{
private:
	class Node
	{
	public:

		T value;
		Node* next;
		Node(const T & val, Node * nex) : value(val), next(nex) {}
		Node()
		{
			next = NULL;
		}
	};
	    Node* m_head;
	    Node* m_tail;
	    int m_count;
public:
	    linked_list()
	    {
	    	m_count = 0;
	    	m_head = NULL;
	    	m_tail = NULL;
	    }

	    linked_list(T* items, int count)
	    {
	    	Node* a;
	    	m_count = count;
	    	m_tail = NULL;

	    	if((count <= 0) && (items == NULL)) return;
	    	for(int i = 0; i < count; i++)
	    	{
	    		a = new Node;
	    		if(i == 0) m_head = a;
	    		a->value = items[i];
	    		if(m_tail != NULL) m_tail->next = a;
	    		m_tail = a;
	    	}
	    	a->next = NULL;
	    }

	    linked_list(linked_list<T>  &list)
	    {
	    	Node* a;

	    	m_count = list.m_count;
			m_tail = NULL;

			for(int i = 0; i < m_count; i++)
			{
				a = new Node;
				if(i == 0) m_head = a;
				a->value = list[i];
				if(m_tail != NULL) m_tail->next = a;
				m_tail = a;
			}
			a->next = NULL;
	    }

	    ~linked_list()
	    {
	    	Node* tmp = m_head;
	    	Node* a;

	    	for(int i = 0; i < m_count; i++)
	    	{
	    		if(tmp != NULL)
	    		{
	    			a = tmp;
	    			tmp = tmp->next;
	    			delete [] a;
	    		}
	    	}
	    }

	    T get_first()
	    {
	    	if(m_head == NULL) throw -1;
	    	return m_head->value;
	    }

	    T get_last()
		{
	    	if(m_tail == NULL) throw -1;
	    	return m_tail->value;
		}

	    int get_length()
	    {
	    	return m_count;
	    }

	    Node* get_pointer(int index)
	    {
	    	Node* tmp = m_head;
			Node* a;

			for(int i = 0; i <= index; i++)
			{
				if(tmp == NULL) throw -1;
				a = tmp;
				tmp = tmp->next;
			}
			return a;
	    }

	    void prepend(T item)
	    {
	    	Node* a = new Node;
	    	Node* tmp;
	    	tmp = m_head;
	    	m_head = a;
	    	a->next = tmp;
	    	a->value = item;
	    	m_count++;
	    }

	    void append(T item)
	    {
	    	Node* a = new Node;
			Node* tmp;
			tmp = m_tail;
			m_tail = a;
			tmp->next = a;
			a->value = item;
			m_count++;
	    }

	    linked_list<T>* get_sub_list(int start_index, int end_index)
	    {
	    	if(((start_index * end_index) < 0) || (start_index >= m_count) || (end_index >= m_count)) throw -1;
	    	int count = end_index - start_index + 1;
	    	T tmp[count];

	    	for(int i = 0; i < count; i++)
	    	{
	    		tmp[i] = get_pointer(i + start_index)->value;
	    	}
	    	linked_list<T>* new_list = new linked_list<T>(tmp, count);
	    	return new_list;
	    }

	    void insert_at(T item, int index)
	    {
	    	if((index < 0) || (index >= m_count)) throw -1;
	    	Node* tmp1 = get_pointer(index - 1);
	    	Node* tmp2 = get_pointer(index);
	    	Node* a = new Node;

	    	tmp1->next = a;
	    	a->next = tmp2;
	    	a->value = item;
	    	m_count++;
	    }

	    linked_list<T>* concat(linked_list<T>* list)
	    {
	    	T tmp[m_count];

			for(int i = 0; i < m_count; i++)
			{
				tmp[i] = get_pointer(i)->value;
			}
			linked_list<T>* new_list = new linked_list<T>(tmp, m_count);

			Node* tmp_1;
			tmp_1 = new_list->m_tail;
			new_list->m_tail = list->m_tail;
			tmp_1->next = list->m_head;
			new_list->m_count += list->m_count;
			return new_list;

	    }

	    T & operator[] (int index)
	        {
	    		Node* tmp = m_head;
				Node* a;
				for(int i = 0; i <= index; i++)
				{
					if(tmp == NULL) throw -1;
					a = tmp;
					tmp = tmp->next;
				}
				return a->value;
	        }
};

template<typename T>
ostream & operator << (ostream & out, linked_list<T> a)
{
    for (int i = 0; i < (a.get_length()); ++i)
    {
        out << a[i] << " ";
    }
    return out;
}



#endif /* LINKED_LIST_H_ */
