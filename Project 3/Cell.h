/**
Cell.h
Purpose: This class creates individual Cell objects.

@author Emily Black
@version 3.0
@date 3/4/16
*/

#pragma once
#include <iostream>
#include "Exceptions.h"
using namespace std;

template <class DT>
class Cell
{
	friend ostream& operator<< <>(ostream & s, Cell<DT> & obj);  //overloaded ostream operator
protected:
	DT * _value;  //value of this cell
	Cell<DT> * _right; //value of the next cell (cell to the right)
	void Copy(const Cell<DT> & obj);  //Protected Copy Function
public:
	Cell();  //Default Constructor
	Cell(DT value); //initializer constructor
	Cell(DT value, Cell<DT> * right); //Initializer Constructor
	Cell(const Cell<DT> & obj);  //Copy Constructor
	Cell<DT>& operator= (Cell<DT> & obj); //Overloaded equals operator
	void add(DT & obj); //Mutator
	int size(); //finds size
	bool isEmpty();
	void setCell(Cell<DT> * listOfCells);
	void setValue(DT * obj); //Mutator
	void displayValue();
	void displayRight();
	~Cell(); //destructor
};

//Copy Function
template <class DT>
void Cell<DT>::Copy(const Cell<DT> & obj)
{
	if (obj._value == NULL)
	{
		_value = NULL;
	}
	else
	{
		_value = new DT(*(obj._value));

		if (_value == NULL)
		{
			throw Exception("ERROR: Can't create a cell node with a null value!");
		}
	}

	if (obj._right == NULL)
	{
		_right = NULL;
	}
	else
	{
		_right = new Cell<DT>(*(obj._right));
	
		if (_right == NULL)
		{
			throw Exception("ERROR: The cell its pointing to has a null value!");
		}
	}
}

//Default Constructor
template <class DT>
Cell<DT>::Cell()
{
	_value = NULL;
	_right = NULL;
}

//initializer constructor
template <class DT>
Cell<DT>::Cell(DT value)
{
	setValue(&value);
	_right = NULL;
}

//Initializer Constructor
template <class DT>
Cell<DT>::Cell(DT value, Cell<DT> * right)
{
	setValue(&value);
	setCell(right);
}

//Copy Constructor
template <class DT>
Cell<DT>::Cell(const Cell<DT> & obj)
{
	Copy(obj);
}

//Overloaded Equals Operator
template <class DT>
Cell<DT>& Cell<DT>::operator= (Cell<DT> & obj)
{
	Copy(obj);
	return (*this);
}

//Overloaded ostream operator
template <class DT>
ostream& operator<< <>(ostream & s, Cell<DT> & obj)
{
	if (obj._value == NULL)  //Nothing to display
	{
		s << "No cell values to display!" << endl;
	}
	else
	{
		obj.displayValue();
		obj.displayRight();
	}
	return s;
}

//Mutator
template <class DT>
void Cell<DT>::add(DT & obj)
{
	if (_value == NULL) //if no value, set it to objs value
	{
		_value = new DT(obj);
	}
	else  //if there is a value, look right
	{
		Cell<DT>* newList = new Cell<DT>(*_value, _right);
		if (newList == NULL)  //error
		{
			throw Exception("ERROR: Cannot add null cell!");
		}
		*_value = obj;
		_right = newList;
	}
}

//Finds size
template <class DT>
int Cell<DT>::size()
{
	if (_value == NULL)
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
		return 1 + _right->size(); //recursive call
	}
}

//Finds if its empty!
template <class DT>
bool Cell<DT>::isEmpty()
{
	return (_value == NULL);
}

template <class DT>
void Cell<DT>::setCell(Cell<DT> * listOfCells)
{
	_right = listOfCells;
}

template <class DT>
void Cell<DT>::setValue(DT * obj)
{
	if (obj == NULL)
	{
		throw Exception("ERROR: You cannot set the info of cellnode to null!");
	}
	else
	{
		_value = obj;
	}
}

template <class DT>
void Cell<DT>::displayValue()
{
	cout << *_value;
}

template <class DT>
void Cell<DT>::displayRight()
{
	cout << *_right;
}

//Destructor
template <class DT>
Cell<DT>::~Cell()
{
	if (_value != NULL && _right == NULL)
	{
		_value = NULL;
	}
	if (_value != NULL && _right != NULL)
	{
		_right = NULL;
	}
	else
	{
		_value = NULL;
		_right = NULL;
	}
}
