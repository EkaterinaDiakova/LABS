#ifndef GRAPH_H_
#define GRAPH_H_

#include<iostream>
#include "StackList.h"
#include "linked_list.h"
using namespace std;

template <typename T>
class Graph
{
    int V;	// Количество вершин

    linked_list<T> *adj;

    void topologicalSortUtil(int v, bool visited[], StackList<T> &Stack);
public:

    Graph(int V)
    {
        this->V = V;
        adj = new linked_list<T>[V]();
    }

    void addEdge(T v, T w)
    {
        adj[v].append(w);
    }

    void topologicalSortUtil(int v, bool visited[],
    		StackList<T> &Stack)
    {
        visited[v] = true;

        // Рекурсивно вызываем функцию для всех смежных вершин

        linked_list<int>::Iterator i(adj[v].GetHead());
        for (i = adj[v].begin(); i != NULL && i != adj[v].end(); ++i)
            if (!visited[*i])
                topologicalSortUtil(*i, visited, Stack);

        Stack.Push(v);
    }

    void topologicalSort()
    {
    	StackList<T> Stack;

        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        for (int i = 0; i < V; i++)
          if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

        while (Stack.Empty() == false)
        {
            cout << Stack.Top() << " ";
        }
    }
};

#endif /* GRAPH_H_ */
