#include"Sequence.h"
#include"dynamic_array.h"
#include"queque.h"

int main()
{
	queque<int> * a;
	a = new queque<int>();
	a->Enqueue(0, 0);
	a->Enqueue(1, 1);
	a->Enqueue(2, 2);
	a->print();
	a->Peek(1);
	a->PeekFirst();
	a->PeekLast();
	a->Dequeue();
	a->print();
	return 0;
}
