/**
MasterCell.h
Purpose: This class holds a list of CellNodes

@author Emily Black
@credit Pravallika Uppuganti
@version 4.0
@date 3/12/16
Notes: _myCellNodes is managed with my CoolArray class. So, most of the manipulation will be done with that structure
*/

#pragma once
#include <iostream>
#include "CellNode.h"
#include "CoolArray.h"
#include "Cell.h"
using namespace std;
template <class T1, class T2>
class MasterCell 
{
	template<class V1, class V2>
	friend ostream& operator<< (ostream& s, MasterCell<V1, V2>& in);

protected:
	CoolArray<CellNode<T1, T2>>* _myCellNodes;

public:
	MasterCell();											// Default constructor
	MasterCell(T1 val);										// Initializer
	MasterCell(MasterCell<T1, T2>& in);						// Copy constructor
	~MasterCell();											// Destructor
	MasterCell<T1, T2>& operator= (MasterCell<T1, T2>& in);	// Overloaded =
	void addNode(T1 val);									// Adds a new CellNode with info val
	CellNode<T1, T2>& operator[] (int index);				// Access operator

	CoolArray<T1> findKeywords(int sizeToLookFor);	// Find keywords
	CoolArray<T2> andMethod(CoolArray<char> x, CoolArray<char> y); // and 
	CoolArray<T2> orMethod(CoolArray<char> x, CoolArray<char> y);  // or 
	CoolArray<T2>  exclusiveOrMethod(CoolArray<char> x, CoolArray<char> y);  // exclusive or
};

// Default Constructor
template <class T1, class T2>
MasterCell<T1, T2>::MasterCell() : _myCellNodes(new CoolArray<CellNode<T1, T2>>)
{ 

}

// Initializes the cell
template <class T1, class T2>
MasterCell<T1, T2>::MasterCell(T1 val) : _myCellNodes(new CoolArray<CellNode<T1, T2>>)
{
	_myCellNodes->add(new CellNode<T1, T2>(val));
}

// Copy constructor
template <class T1, class T2>
MasterCell<T1, T2>::MasterCell(MasterCell<T1, T2>& in) : _myCellNodes(new CoolArray<CellNode<T1, T2>>(*in._myCellNodes))
{ 

}

// Destructor
template <class T1, class T2>
MasterCell<T1, T2>::~MasterCell() 
{
	delete _myCellNodes;
}

// Overloaded assignment operator
template <class T1, class T2>
MasterCell<T1, T2>& MasterCell<T1, T2>::operator= (MasterCell<T1, T2>& in) 
{
	delete _myCellNodes;
	_myCellNodes = new CoolArray<CellNode<T1, T2>>;

	if (in._myCellNodes) 
	{ 
		*_myCellNodes = *in._myCellNodes; 
	}
	return *this;
}

// Overloaded access operator
template <class T1, class T2>
CellNode<T1, T2>& MasterCell<T1, T2>::operator[] (int index) 
{
	return (*_myCellNodes)[index];
}

// Overloaded output operator
template <class T1, class T2>
ostream& operator<< (ostream& s, MasterCell<T1, T2>& in) 
{
	int index = (*in._myCellNodes).size();

	// Iterating through and printing all CellNodes
	for (int i = 0; i < index; i++) 
	{
		s << (*in._myCellNodes)[i] << endl;
	}

	return s;
}

// Adds a new CellNode with _info = val
template <class T1, class T2>
void MasterCell<T1, T2>::addNode(T1 val) 
{
	_myCellNodes->add(new CellNode<T1, T2>(val));
}

// Find keywords function
// WORKS CORRECTLY
template <class T1, class T2>
CoolArray<T1> MasterCell<T1, T2>::findKeywords(int sizeToLookFor)
{
	CoolArray<T1> keywordsFound;		// Default size of 10
	int size;
	int counter = 0;

	if (sizeToLookFor < 0)  // Base case
	{
		cout << "Sorry that is not a valid input!" << endl;
		return keywordsFound;
	}
	else
	{
		for (int i = 0; i < 26; i++) // 26 is size of input
		{
			size = _myCellNodes[i].getArray().getMyCell().size();
			if (size == sizeToLookFor)
			{
				keywordsFound.add(_myCellNodes[i].getInfo(), counter);
				counter++;
			}
		}
	}
	return keywordsFound;
}

// And function
// WORKS CORRECTLY
template <class T1, class T2>
CoolArray<T2> MasterCell<T1, T2>::andMethod(CoolArray<char> x, CoolArray<char> y)
{
	Cell<T2> * foundX;  // Stores values found for keyword X
	Cell<T2> * foundY;  // Stores values found for keyword Y
	CoolArray<T2> foundElements;
	
	for (int i = 0; i < 26; i++) // 26 is size of input
	{
		if (_myCellNodes[i].getInfo() == x)
		{
			foundX = &(_myCellNodes[i].getArray().getMyCell());
		}
		if (_myCellNodes[i].getInfo() == y)
		{
			foundY = &(_myCellNodes[i].getArray().getMyCell());
		}
	}
	if (foundX != nullptr && foundY != nullptr)
	{
		foundElements = andMethodCell(foundX, foundY);
	}
	return foundElements;
}

// Or function
// WORKS CORRECTLY
template <class T1, class T2>
CoolArray<T2> MasterCell<T1, T2>::orMethod(CoolArray<char> x, CoolArray<char> y)
{
	Cell<T2> * foundX;  // Stores values found for keyword X
	Cell<T2> * foundY;  // Stores values found for keyword Y
	CoolArray<T2> foundElements;

	for (int i = 0; i < 26; i++) // 26 is size of input
	{
		if (_myCellNodes[i].getInfo() == x)
		{
			foundX = &(_myCellNodes[i].getArray().getMyCell());
		}
		if (_myCellNodes[i].getInfo() == y)
		{
			foundY = &(_myCellNodes[i].getArray().getMyCell());
		}
	}
	if (foundX != nullptr && foundY != nullptr)
	{
		foundElements = orMethodCell(foundX, foundY);
	}
	return foundElements;
}

// Exclusive or function
// WORKS CORRECTLY
template <class T1, class T2>
CoolArray<T2> MasterCell<T1, T2>::exclusiveOrMethod(CoolArray<char> x, CoolArray<char> y)
{
	Cell<T2> * foundX;  // Stores values found for keyword X
	Cell<T2> * foundY;  // Stores values found for keyword Y
	CoolArray<T2> foundElements;

	for (int i = 0; i < 26; i++) // 26 is size of input
	{
		if (_myCellNodes[i].getInfo() == x)
		{
			foundX = &(_myCellNodes[i].getArray().getMyCell());
		}
		if (_myCellNodes[i].getInfo() == y)
		{
			foundY = &(_myCellNodes[i].getArray().getMyCell());
		}
	}
	if (foundX != nullptr && foundY != nullptr)
	{
		foundElements = xorMethodCell(foundX, foundY);
	}
	return foundElements;
}