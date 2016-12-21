/**
ParentMultiTree.h
Purpose: This class holds a BinaryTree (implemented as an array) object.

@author Emily Black
@version 6.0
@date 4/20/16
*/

#pragma once
#include <iostream>
#include "Exceptions.h"
#include "Array.h"
using namespace std;

template <class DT>
class ParentMultiTree
{
	template <class T>
	friend ostream& operator << (ostream& s, ParentMultiTree<T>& in);	// Overloaded ostream operator

protected:
	Array<DT> parentArray;												// Array of value of nodes - already initialized. TA SAID I COULD USE THIS.
	Array<DT> childOrder;												// Array of the children order - already initialized. TA SAID I COULD USE THIS.
	int numNodes;														// Number of nodes in tree - already initialized.

public:
	ParentMultiTree();													// Default Constructor
	ParentMultiTree(int numNodesInput);									// Initializer Constructor
	ParentMultiTree(int numNodesInput, Array<DT> parentArrayInput, Array<DT> childOrderInput); // Initializer Constructor
	ParentMultiTree(ParentMultiTree<DT>& in);							// Copy Constructor
	ParentMultiTree<DT>& operator= (ParentMultiTree<DT>& in);			// Overloaded equals operator
	int size();															// Finds size of binary tree
	int height(int index);												// Finds height of binary tree
	DT getRoot();														// Accessor
	Array<DT> getParentArray();											// Accessor
	Array<DT> getChildOrder();											// Accessor
	int getNumNodes();													// Accessor
	Array<DT> getChildren(int parentIndex);								// Accessor
	void preorder(ostream& s, int index);								// Preorder traversal sorting
	~ParentMultiTree();													// Destructor
};

// Default Constructor
template <class DT>
ParentMultiTree<DT>::ParentMultiTree()
{
	numNodes = 0;		// Initializes number of nodes to 0
}

// Initializer Constructor
template <class DT>
ParentMultiTree<DT>::ParentMultiTree(int numNodesInput)
{
	numNodes = numNodesInput;		// Initializes number of nodes to parameter
}

// Initializer Constructor
template <class DT>
ParentMultiTree<DT>::ParentMultiTree(int numNodesInput, Array<DT> parentArrayInput, Array<DT> childOrderInput)
{
	numNodes = numNodesInput;

	parentArray = Array<DT>(numNodes);
	childOrder = Array<DT>(numNodes);

	for (int i = 0; i < numNodes; i++)  // Deep copy
	{
		parentArray.add(parentArrayInput[i], i);
		childOrder.add(childOrderInput[i], i);
	}
}

// Copy Constructor
template <class DT>
ParentMultiTree<DT>::ParentMultiTree(ParentMultiTree<DT>& in)
{
	operator=(in);
}

// Overloaded equals operator
template <class DT>
ParentMultiTree<DT>& ParentMultiTree<DT>::operator=(ParentMultiTree<DT>& in)
{
	numNodes = in.getNumNodes();
	parentArray = Array<DT>(numNodes);
	childOrder = Array<DT>(numNodes);

	Array<DT> x = in.getParentArray();
	Array<DT> y = in.getChildOrder();

	// Goes through list and transfers parentArray over.
	for (int i = 0; i < numNodes; i++)
	{
		parentArray.add(x[i], i);
	}

	// Goes through list and transfers childOrder over.
	for (int k = 0; k < numNodes; k++)
	{
		childOrder.add(y[k], k);
	}
	return (*this);
}

// Overloaded ostream operator
template <class DT>
ostream& operator << (ostream& s, ParentMultiTree<DT>& in)
{
	in.preorder(s, in.getRoot());
	return s;
}

// Finds size of binary tree
template <class DT>
int ParentMultiTree<DT>::size()
{
	return numNodes;
}

// Finds height of binary tree
template <class DT>
int ParentMultiTree<DT>::height(int index)
{
	int answer = 0;
	if (numNodes == 0)
	{
		return 0;
	}
	if (index < 0)
	{
		throw Exception("Sorry you cannot have a negative index!");
	}
	else
	{
		for (int i = 0; i < numNodes; i++)
		{
			if ((parentArray[i] == index) && (answer < height(i)))
			{
				answer = height(i);
			}
		}
	}
	answer = answer + 1;
	return answer;
}

// Accessor
template <class DT>
DT ParentMultiTree<DT>::getRoot()
{
	for (int i = 0; i < numNodes; i++)
	{
		if (parentArray[i] == -1)
		{
			return i;
		}
	}
	return -1;   // Meaning it found no root
}

// Accessor
template <class DT>
Array<DT> ParentMultiTree<DT>::getParentArray()
{
	return parentArray;
}

// Accessor
template <class DT>
Array<DT> ParentMultiTree<DT>::getChildOrder()
{
	return childOrder;
}

// Accessor
template <class DT>
int ParentMultiTree<DT>::getNumNodes()
{
	return numNodes;
}

// Accessor
template <class DT>
Array<DT> ParentMultiTree<DT>::getChildren(int parentIndex)
{
	Array<DT> myAnswers;		// Default size of 10
	int counter = 0;
	for (int i = 0; i < numNodes; i++)
	{
		if (parentArray[i] == parentIndex)
		{
			myAnswers.add(i, counter);
			counter++;
		}
	}
	return myAnswers;
}

// Preorder traversal sorting
template <class DT>
void ParentMultiTree<DT>::preorder(ostream& s, int index)
{
	s << index << ", ";

	for (int i = 0; i < numNodes; i++)  // Goes through parent array and prints values
	{
		if (parentArray[i] == index)
		{
			preorder(s, i);
		}
	}
}

// Destructor
template <class DT>
ParentMultiTree<DT>::~ParentMultiTree()
{
	//Nothing to delete.
}