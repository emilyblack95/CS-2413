/**
CellNode.h
Purpose: This class creates a CellNode object, which is a piece of the master cell.

@author Emily Black
@version 3.0
@date 3/4/16
*/

#pragma once
#include <iostream>
#include "Exceptions.h"
#include "Cell.h"
using namespace std;

template <class DT1, class DT2>
class CellNode : public Cell<DT1>  //cellnode extends cell
{
	friend ostream& operator<< <>(ostream & s, const CellNode<DT1, DT2> & obj);  //overloaded ostream operator
protected:
	DT1 * _info;  //value -- Comic book
	Cell<DT2> * _myCell;  //pointer to next cell  -- Next series
	void Copy(const CellNode<DT1, DT2> & obj);  //Protected Copy Function
public:
	CellNode();  //Default Constructor
	CellNode(DT1 info);   //initializer constructor
	CellNode(DT1 info, Cell<DT2> * myCell); //Initializer Constructor
	CellNode(const CellNode<DT1, DT2> & obj);  //Copy Constructor
	CellNode<DT1, DT2>& operator= (const CellNode<DT1, DT2> & obj); //Overloaded equals operator
	bool isEmpty();
	DT1 getInfo(); //Accessor
	Cell<DT2> * getMyCellNode(); //Accessor
	int size();
	DT1 & valueAt(int position);
	void add(DT2 & obj); //Mutator - adds int
	void setCellList(Cell<DT2> * listOfCells);
	void setInfo(DT1 * obj); //Mutator - sets string
	~CellNode(); //destructor

};

//Copy Function
template <class DT1, class DT2>
void CellNode<DT1, DT2>::Copy(const CellNode<DT1, DT2> & obj)
{
	if (obj._info == NULL)  //if info is null
	{
		_info = NULL;
	}
	else
	{
		_info = obj._info;
	}

	if (obj._myCell == NULL)  //if what it points to is null
	{
		_myCell = NULL;
	}
	else
	{
		_myCell = new Cell<DT2>(*(obj._myCell));

		if (_myCell == NULL)
		{
			throw Exception("ERROR: The cell its pointing to has a null value!");
		}
	}
}

//Default Constructor
template <class DT1, class DT2>
CellNode<DT1, DT2>::CellNode()
{
	_info = NULL;
	_myCell = NULL;
}

//initializer constructor
template <class DT1, class DT2>
CellNode<DT1, DT2>::CellNode(DT1 info)
{
	setInfo(&info);
	_myCell = NULL;
}

//Initializer Constructor
template <class DT1, class DT2>
CellNode<DT1, DT2>::CellNode(DT1 info, Cell<DT2> * myCell)
{
	setInfo(&info);
	setCellList(myCell);
}

//Copy Constructor
template <class DT1, class DT2>
CellNode<DT1, DT2>::CellNode(const CellNode<DT1, DT2> & obj)
{
	Copy(obj);
}

//Overloaded Equals Operator
template <class DT1, class DT2>
CellNode<DT1, DT2>& CellNode<DT1, DT2>::operator= (const CellNode<DT1, DT2> & obj)
{
	Copy(obj);
	return (*this);
}

//Overloaded ostream operator
template <class DT1, class DT2>
ostream& operator<< <>(ostream & s, const CellNode<DT1, DT2> & obj)
{
	if (obj._info == NULL)  //Nothing to display
	{
		s << "No cellnode values to display!" << endl;
	}
	else
	{
		s << *(obj._info) << ", ";
		s << *(obj._myCell);
	}
	return s;
}

template <class DT1, class DT2>
bool CellNode<DT1, DT2>::isEmpty()
{
	return (_info == NULL);
}

//Accessor
template <class DT1, class DT2>
DT1 CellNode<DT1, DT2>::getInfo()
{
	if (isEmpty())
	{
		throw Exception("ERROR: Current info is null!");
	}
	return *_value;
}

//Accessor
template <class DT1, class DT2>
Cell<DT2>* CellNode<DT1, DT2>::getMyCellNode()
{
	if (_myCell == NULL)
	{
		throw Exception("ERROR: Current cell it's pointing to is null!");
	}
	return _myCell;
}

template <class DT1, class DT2>
int CellNode<DT1, DT2>::size()
{
	if (_myCell == NULL)
	{
		if (isEmpty())
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
		return 1 + _myCell->size(); //recursive call
	}
}

template <class DT1, class DT2>
DT1& CellNode<DT1, DT2>::valueAt(int position)
{
	if (isEmpty())
	{
		throw Exception("ERROR: Cell not found!");
	}
	if (position == 0)
	{
		return *_info;
	}
	if (_myCell == NULL)
	{
		throw Exception("ERROR: Cell out of bounds!");
	}
	return _myCell->valueAt(position - 1);  //recursive call
}

//Mutator - adds int cell
template <class DT1, class DT2>
void CellNode<DT1, DT2>::add(DT2 & obj)
{
	if (_info == NULL)
	{
		_info = new DT2(obj);
	}
	else
	{
		Cell<DT2>* newCell = new Cell<DT2>(*_info, _myCell);
		if (newCell == NULL)
		{
			throw Exception("ERROR: Cannot add null cell!");
		}
		_info = obj;
		_myCell = newCell;
	}
}

//Mutator - sets string
template <class DT1, class DT2>
void CellNode<DT1, DT2>::setInfo(DT1 * infoOfObj)
{
	if (infoOfObj == NULL)
	{
		throw Exception("ERROR: You cannot set the info of cellnode to null!");
	}
	else
	{
		_info = infoOfObj;
	}
}

//Mutator - sets list of cells to certain value
template <class DT1, class DT2>
void CellNode<DT1, DT2>::setCellList(Cell<DT2> * listOfCells)
{
	_myCell = listOfCells;
}

//Destructor
template <class DT1, class DT2>
CellNode<DT1, DT2>::~CellNode()
{
	if (_info != NULL)
	{
		_info = NULL;
	}
	if (_myCell != NULL)
	{
		_myCell = NULL;
	}
	else
	{
		_info = NULL;
		_myCell = NULL;
	}
}