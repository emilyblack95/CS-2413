/**
GraphAdjList.h
Purpose: This class holds the graph object.

@author Emily Black
@version 7.0
@date 4/27/16
*/

#pragma once
#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <class DT>
class GraphAdjList
{
	template <class T>
	friend ostream& operator<< (ostream& s, const GraphAdjList<T>& in);	//Overloaded ostream operator

protected:
	vector<list<DT>> adjList;	//Matrix AKA graph. Basically same thing as list<DT> *
	int numNodes;   //int n
	int numEdges;	//int m

private:
	void _DFS(int start, vector<DT> parent, vector<bool> visited);	//Depth First Search

public:
	GraphAdjList();	//Default Constructor
	GraphAdjList(int numNodes, int numEdges);	//Initializer Constructor
	GraphAdjList(int numNodes, int numEdges, vector<list<DT>> in);	//Initializer Constructor
	GraphAdjList(const GraphAdjList<DT>& in);	//Copy Constructor
	GraphAdjList<DT>& operator= (const GraphAdjList<DT>& in);	//Overloaded equals operator
	int getNumNodes() const;	//Accessor
	int getNumEdges() const;	//Accessor
	vector<list<DT>> getList() const;	//Accessor
	void setNumNodes(int in);	//Mutator
	void setNumEdges(int in);	//Mutator
	void setList(vector<list<DT>> in);	//Mutator
	void addEdge(int vertex1, int vertex2);	//Mutator
	vector<DT> orderOfDFS(int start);	//Order of Depth First Search
	~GraphAdjList();	//Destructor
};

//Depth First Search
template <class DT>
void GraphAdjList<DT>::_DFS(int start, vector<DT> parent, vector<bool> visited)
{
	list<DT> row = adjList[start];
	visited[start] = true;

	for (list<DT>::const_iterator iterator = row.begin(), end = row.end(); iterator != end; ++iterator)
	{
		if (!visited[*iterator])
		{
			parent[*iterator] = start;
			_DFS(*iterator, parent, visited);
		}
	}
}

//Default Constructor
template <class DT>
GraphAdjList<DT>::GraphAdjList()
{
	numNodes = 0;
	numEdges = 0;
}

//Initializer Constructor
template <class DT>
GraphAdjList<DT>::GraphAdjList(int numNodes, int numEdges) : adjList(numNodes)
{
	this->numNodes = numNodes;
	this->numEdges = numEdges;
}

//Initializer Constructor
template <class DT>
GraphAdjList<DT>::GraphAdjList(int numNodes, int numEdges, vector<list<DT>> in)
{
	this->numNodes = numNodes;
	this->numEdges = numEdges;
	adjList = in;
}

//Copy Constructor
template <class DT>
GraphAdjList<DT>::GraphAdjList(const GraphAdjList<DT>& in)
{
	numNodes = in.getNumNodes();
	numEdges = in.getNumEdges();
	adjList = in.getList();
}

//Overloaded equals operator
template <class DT>
GraphAdjList<DT>& GraphAdjList<DT>::operator= (const GraphAdjList<DT>& in)
{
	numNodes = in.getNumNodes();
	numEdges = in.getNumEdges();
	adjList = in.getList();
}

//Accessor
template <class DT>
int GraphAdjList<DT>::getNumNodes() const
{
	return numNodes;
}

//Accessor
template <class DT>
int GraphAdjList<DT>::getNumEdges() const
{
	return numEdges;
}

//Accessor
template <class DT>
vector<list<DT>> GraphAdjList<DT>::getList() const
{
	return adjList;
}

//Mutator
template <class DT>
void GraphAdjList<DT>::setNumNodes(int in)
{
	numNodes = in;
}

//Mutator
template <class DT>
void GraphAdjList<DT>::setNumEdges(int in)
{
	numEdges = in;
}

//Mutator
template <class DT>
void GraphAdjList<DT>::setList(vector<list<DT>> in)
{
	adjList = in;
}

//Mutator
template <class DT>
void GraphAdjList<DT>::addEdge(int vertex1, int vertex2)
{
	adjList[vertex1].push_back(vertex2);
}

//Order of Depth First Search
//The point in this method is to find the shortest path from point A to the end.
//returns parent array, which could then be structured into a tree.
template <class DT>
vector<DT> GraphAdjList<DT>::orderOfDFS(int start)
{
	vector<DT> parent(numNodes);
	vector<bool> visited(numNodes);
	for (int i = 0; i < numNodes; i++)
	{
		visited[i] = false;
		parent[i] = -1;
	}
	_DFS(start, parent, visited);
	return parent;
}

//Overloaded ostream operator
template <class DT>
ostream& operator<< (ostream& s, const GraphAdjList<DT>& in)
{
	int numNodes = in.getNumNodes();
	vector<list<DT>> myList = in.getList();
	for (int i = 0; i < numNodes; i++)
	{
		list<DT> row = myList[i];

		for (list<DT>::const_iterator iterator = row.begin(), end = row.end(); iterator != end;)
		{
			s << *iterator;
			if (++iterator != end)
			{
				s << ", ";
			}
		}
		s << "." << endl;
	}
	return s;
}

//Destructor
template <class DT>
GraphAdjList<DT>::~GraphAdjList()
{
	//Dont need anything here!
}