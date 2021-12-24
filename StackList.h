#ifndef STACKLIST_H_
#define STACKLIST_H_

#include <iostream>
using namespace std;

template <typename T>
struct NodeStack
{
  T item;
  NodeStack<T>* next;
};


template <typename T>
class StackList
{
private:
  NodeStack<T>* pTop;

public:

  	  StackList()
	  {
  		  pTop = NULL;
	  }


  	  StackList(const StackList& SL)
  	  {
		NodeStack<T>* p;
		NodeStack<T>* p2;
		NodeStack<T>* p3;


		pTop = NULL;
		p3 = NULL;

		p = SL.pTop;
		while (p != NULL)
		{

		  try
		  {
			p2 = new NodeStack<T>;
		  }
		  catch (bad_alloc e)
		  {
			cout << e.what() << endl;
			return;
		  }
		  p2->item = p->item;
		  p2->next = NULL;

		  if (pTop == NULL)
		  {
			pTop = p2;
			p3 = p2;
		  }
		  else
		  {
			p3->next = p2;
			p3 = p3->next;
		  }

		  p = p->next;
		}
  	  }

  void Push(T item)
  {
    NodeStack<T>* p;

    try {
      p = new NodeStack<T>;
    }
    catch(bad_alloc e)
    {
      cout << e.what() << endl;
      return;
    }
    p->item = item;
    p->next = pTop;

    pTop = p;
  }


  int Count()
  {
      int count = 0;
      if (pTop == NULL)
      return 0;
		else
		{
		  NodeStack<T>* p = pTop;

		  while (p != NULL)
		  {
			count++;
			p = p->next;
		  }
		}
		return count;
  }


  bool Empty()
  {
	  if(pTop == NULL) return true;
	  else return false;
  }


  StackList<T>& operator=(const StackList<T>& LS)
  {

    if (pTop != NULL) Empty();

    NodeStack<T>* p;
    NodeStack<T>* p2;
    NodeStack<T>* p3;


    pTop = NULL;
    p3 = NULL;

    p = LS.pTop;
    while (p != NULL)
    {

      try {
        p2 = new NodeStack<T>;
      }
      catch (bad_alloc e)
      {
        cout << e.what() << endl;
        return *this;
      }
      p2->item = p->item;
      p2->next = NULL;

      if (pTop == NULL)
      {
        pTop = p2;
        p3 = p2;
      }
      else
      {
        p3->next = p2;
        p3 = p3->next;
      }

      p = p->next;
    }
    return *this;
  }


  void Print(const char* objName)
  {
    cout << "Object: " << objName << endl;
    if (pTop == NULL)
      cout << "stack is empty." << endl;
    else
    {
      NodeStack<T>* p;
      p = pTop;
      while (p != NULL)
      {
        cout << p->item << "\t";
        p = p->next;
      }
      cout << endl;
    }
  }


  ~StackList()
  {
	    NodeStack<T>* p;
	    NodeStack<T>* p2;

	    p = pTop;

	    while (p != NULL)
	    {
	      p2 = p;
	      p = p->next;
	      delete p2;
	    }
	    pTop = NULL;
  }

  // метод, выт€гивающий элемент со стека
  T Top()
  {
    if (pTop == NULL)
      return 0;

    NodeStack<T>* p2;
    T item;
    item = pTop->item;

    p2 = pTop;
    pTop = pTop->next;

    delete p2;

    return item;
  }

  void Pop()
  {
	    NodeStack<T>* p;
		p = pTop->next;
		delete pTop;
		pTop = p;
  }
};


#endif /* STACKLIST_H_ */
