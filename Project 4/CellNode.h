/**
CellNode.h
Purpose: Holds an _info object and a Cell (linked list) with a possibly differnet type

@author Pravallika Uppuganti
@project 4.0
@date 3/13/16
Notes: _myCell is guaranteed to always have a default initialized value
*/

#pragma once
#include <iostream>
#include "Cell.h"
using namespace std;
template <class T1, class T2>
class CellNode 
{
	template<class V1, class V2>
	friend ostream& operator<< (ostream& s, CellNode<V1, V2>& in);

protected:
	T1* _info;
	Cell<T2>* _myCell;

public:
	CellNode();											// Default constructor
	CellNode(T1 val);									// Initializer
	CellNode(CellNode<T1, T2>& in);						// Copy constructor
	~CellNode();										// Destructor
	CellNode<T1, T2>& operator= (CellNode<T1, T2>& in);	// Overloaded =
	T1 getInfo();										// Accessor
	Cell<T2> getMyCell();								// Accessor
	Cell<T2>* getMyCellPointer();						// Accessor
	int size();											// Finds size of LinkedList
	bool isEmpty();										// Test for emptyiness
	void add(T2 val);									// Adds val to _myCell
	void setInfo(T1& in);								// Sets info
};

// Default constructor
template <class T1, class T2>
CellNode<T1, T2>::CellNode() : _info(nullptr), _myCell(new Cell<T2>)
{ 

}

// Constructor to initialize _info
template <class T1, class T2>
CellNode<T1, T2>::CellNode(T1 val) : _info(new T1(val)), _myCell(new Cell<T2>)
{ 

}

// Copy constructor
template <class T1, class T2>
CellNode<T1, T2>::CellNode(CellNode<T1, T2>& in) : _info(nullptr), _myCell(new Cell<T2>)
{
	if (in._info) 
	{ 
		_info = new T1(*in._info); 
	}
	*_myCell = *in._myCell;
}

// Destructor
template <class T1, class T2>
CellNode<T1, T2>::~CellNode() 
{
	delete _info;
	delete _myCell;
}

// Overloaded assignment operator
template <class T1, class T2>
CellNode<T1, T2>& CellNode<T1, T2>::operator= (CellNode<T1, T2>& in) 
{
	delete _info;
	delete _myCell;
	_info = nullptr;
	_myCell = new Cell<T2>;

	// Only copies if the values are non-null
	if (in._info)
	{ 
		_info = new T1(*in._info); 
	}
	if (in._myCell) 
	{ 
		*_myCell = *in._myCell; 
	}

	return *this;
}

// Overloaded output operator
template <class T1, class T2>
ostream& operator<< (ostream& s, CellNode<T1, T2>& in) 
{
	// Returns if there is no _info
	if (in._info) { s << *in._info; }

	// Prints info
	s << " : ";

	// Only prints _myCell if it isnt null
	s << *in._myCell;

	return s;
}

// Accessor
template <class T1, class T2>
T1 CellNode<T1, T2>::getInfo()
{
	if (isEmpty())  // If info is pointing to nullpointer
	{
		cout << "Info is currently empty!" << endl;
		return '\0';
	}
	else
	{
		return *_info;
	}
}

// Accessor
template <class T1, class T2>
Cell<T2> CellNode<T1, T2>::getMyCell()
{
	return *_myCell;
}

// Accessor
template <class T1, class T2>
Cell<T2>* CellNode<T1, T2>::getMyCellPointer()
{
	return _myCell;
}

// Finds size of linkedlist
template <class T1, class T2>
int CellNode<T1, T2>::size()
{
	if (_myCell == nullptr)
	{
		if (_info == nullptr)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1 + _myCell->size();
	}
}

// Finds if its empty
template <class T1, class T2>
bool CellNode<T1, T2>::isEmpty()
{
	return (_info == nullptr);
}

// Adds val to _myCell
template <class T1, class T2>
void CellNode<T1, T2>::add(T2 val) 
{
	_myCell->add(val);
}

// Sets _info to in
template <class T1, class T2>
void CellNode<T1, T2>::setInfo(T1& in) 
{
	// Deletes old info, adds new
	delete _info;
	_info = new T1(in);
}