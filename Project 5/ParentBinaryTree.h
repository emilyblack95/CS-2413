/**
ParentBinaryTree.h
Purpose: This class holds a BinaryTree (implemented as an array) object.

@author Emily Black
@version 5.0
@date 4/7/16
*/

#pragma once
#include <iostream>
#include "Exceptions.h"
#include "Array.h"
using namespace std;

template <class DT>
class ParentBinaryTree
{
	template<class T>
	friend ostream& operator << (ostream& s, ParentBinaryTree<T>& in);	// Overloaded ostream operator

protected: 
	Array<DT> parentArray;												// Array of value of nodes - already initialized. TA SAID I COULD USE THIS.
	Array<DT> childOrder;												// Array of the children order - already initialized. TA SAID I COULD USE THIS.
	int numNodes;														// Number of nodes in tree - already initialized.

public:
	ParentBinaryTree();													// Default Constructor
	ParentBinaryTree(int numNodes);										// Initializer Constructor
	ParentBinaryTree(int numNodes, Array<DT> parentArray, Array<DT> childOrder); // Initializer Constructor
	ParentBinaryTree(ParentBinaryTree<DT>& in);							// Copy Constructor
	ParentBinaryTree<DT>& operator= (ParentBinaryTree<DT>& in);			// Overloaded equals operator
	int size();															// Finds size of binary tree
	int height(int root);												// Finds height of binary tree
	DT getLeft(int index);												// Accessor
	DT getRight(int index);												// Accessor
	DT getRoot();														// Accessor
	Array<DT> getParentArray();											// Accessor
	Array<DT> getChildOrder();											// Accessor
	int getNumNodes();													// Accessor
	void preorder(ostream& s, int index);								// Preorder traversal sorting
	void inorder(int index);											// Inorder traversal sorting
	void postorder(int index);											// Postorder traversal sorting
	~ParentBinaryTree();												// Destructor
};

// Default Constructor
template <class DT>
ParentBinaryTree<DT>::ParentBinaryTree()
{
	numNodes = 0;		// Initializes number of nodes to 0
}

// Initializer Constructor
template <class DT>
ParentBinaryTree<DT>::ParentBinaryTree(int numNodes)
{
	this->numNodes = numNodes;		// Initializes number of nodes to parameter
}

// Initializer Constructor
template <class DT>
ParentBinaryTree<DT>::ParentBinaryTree(int numNodes, Array<DT> parentArray, Array<DT> childOrder)
{
	this->numNodes = numNodes;

	for (int i = 0; i < numNodes; i++)  // Deep copy
	{
		this->parentArray[i] = parentArray[i];
		this->childOrder[i] = childOrder[i];
	}
}

// Copy Constructor
template <class DT>
ParentBinaryTree<DT>::ParentBinaryTree(ParentBinaryTree<DT>& in)
{
	operator=(in);
}

// Overloaded equals operator
template <class DT>
ParentBinaryTree<DT>& ParentBinaryTree<DT>::operator=(ParentBinaryTree<DT>& in)
{
	if (in.getNumNodes() == 0)
	{
		throw Exception("Sorry you cannot copy a NULL value!");
	}
	else
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
	}
}

// Overloaded ostream operator
template <class DT>
ostream& operator << (ostream& s, ParentBinaryTree<DT>& in)
{
	in.preorder(s, in.getRoot());
	return s;
}

// Finds size of binary tree
template <class DT>
int ParentBinaryTree<DT>::size()
{
	return numNodes;
}

// Finds height of binary tree
template <class DT>
int ParentBinaryTree<DT>::height(int root)
{
	if (root == -1)		// Base case
	{
		return 0;
	}

	int left = getLeft(root);
	int right = getRight(root);
	
	if (height(left) > height(right))
	{
		return 1 + height(left);
	}
	else
	{
		return 1 + height(right);
	}
}

// Accessor
template <class DT>
DT ParentBinaryTree<DT>::getLeft(int index)
{
	if (index < 0 || index >= numNodes)
	{
		throw Exception("Sorry the index exceeds the size of the array!");
	}

	for (int i = 0; i < numNodes; i++)  // Go through parent array
	{
		if (parentArray[i] == index)  // If a certain element = root
		{
			if (childOrder[i] == 0)  // If childorder says its left child
			{
				return i;
			}
		}
	}
	return -1;   // Assuming there's no children
}

// Accessor
template <class DT>
DT ParentBinaryTree<DT>::getRight(int index)
{
	if (index < 0 || index >= numNodes)
	{
		throw Exception("Sorry the index exceeds the size of the array!");
	}

	for (int i = 0; i < numNodes; i++)  // Go through parent array
	{
		if (parentArray[i] == index)  // If a certain element = root
		{
			if (childOrder[i] == 1)  // If childorder says its left child
			{
				return i;
			}
		}
	}
	return -1;   // Assuming there's no children
}

// Accessor
template <class DT>
DT ParentBinaryTree<DT>::getRoot()
{
	for (int i = 0; i < numNodes; i++)
	{
		if (parentArray[i] == -1)
		{
			return i;
		}
	}
}

// Accessor
template <class DT>
Array<DT> ParentBinaryTree<DT>::getParentArray()
{
	return parentArray;
}

// Accessor
template <class DT>
Array<DT> ParentBinaryTree<DT>::getChildOrder()
{
	return childOrder;
}

// Accessor
template <class DT>
int ParentBinaryTree<DT>::getNumNodes()
{
	return numNodes;
}

// Preorder traversal sorting
template <class DT>
void ParentBinaryTree<DT>::preorder(ostream& s, int index)
{
	s << index << ", ";

	int left = getLeft(index);
	if (left != -1)
	{
		preorder(s, left);
	}

	int right = getRight(index);
	if (right != -1)
	{
		preorder(s, right);
	}
}

// Inorder traversal sorting
template <class DT>
void ParentBinaryTree<DT>::inorder(int index)
{
	int left = getLeft(index);
	if (left != -1)
	{
		inorder(left);
	}

	cout << index << ", ";

	int right = getRight(index);
	if (right != -1)
	{
		inorder(right);
	}
}

// Postorder traversal sorting
template <class DT>
void ParentBinaryTree<DT>::postorder(int index)
{
	int left = getLeft(index);
	if (left != -1)
	{
		postorder(left);
	}

	int right = getRight(index);
	if (right != -1)
	{
		postorder(right);
	}

	cout << index << ", ";
}

// Destructor
template <class DT>
ParentBinaryTree<DT>::~ParentBinaryTree()
{
	//Nothing to delete.
}