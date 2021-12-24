#include<iostream>
#include "StackList.h"
#include "linked_list.h"
#include "Graph.h"
using namespace std;

void getGraph(Graph<int>* g)
{
	int V, edge;
	int num1, num2;
	cout << "Enter vertex amount->";
	cin >> V;
	cout << endl;
	cout << "Enter edge amount->";
	cin >> edge;
	cout << endl;
	g = new Graph<int>(V);
	for(int i = 0; i < edge; i++)
	{
		cout << "Enter vertex (a) number->";
		cin >> num1;
		cout << endl;
		cout << "Enter vertex (b) number->";
		cin >> num2;
		cout << endl;
		g->addEdge(num1, num2);
	}

}

int main()
{
	Graph<int>* g;
	getGraph(g);
    cout << "Topological Sort of the given graph \n";
    g->topologicalSort();
	return 0;
}

// Программа для тестирования
int test()
{
    // Создаем граф, приведенный на диаграмме выше
	int a = 6;
	Graph<int>* g = new Graph<int>(a);

    g->addEdge(5, 2);
    g->addEdge(5, 0);
    g->addEdge(4, 0);
    g->addEdge(4, 1);
    g->addEdge(2, 3);
    g->addEdge(3, 1);

    cout << "Topological Sort of the given graph \n";
    g->topologicalSort();

    return 0;
}

