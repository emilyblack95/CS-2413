/*
* Cell class
*
* 
*
* 
*
*/

/**
Cell.h
Purpose: Linked list of type T

@author Emily Black
@credit Pravallika Uppuganti
@version 4.0
@date 3/12/16
Notes:
- All cells are guaranteed to have a final element with null _value
- The final element is guaranteed to have null _right
- Whenever an element is added, it is added to the beginning of the list
- Therefore... all methods that required a copy, copy the list backward
- ( add(index) ) if index > length of list, it will be added to the end of the list
- ( remove(index) ) if index > length of list, nothing is removed from the list
*/

#pragma once
#include <iostream>
#include "CoolArray.h"
#include "CustomExceptions.h"
using namespace std;
template <class T>
class Cell 
{
	template<class V>
	friend ostream& operator<< (ostream& s, Cell<V>& in);
	template<class V>
	friend void insertionSort(Cell<V> * current);			// Sorts linkedList
	template<class V>
	friend CoolArray<V> andMethodCell(Cell<V> * ListOne, Cell<V> * ListTwo);	// andMethod
	template<class V>
	friend CoolArray<V> orMethodCell(Cell<V> * ListOne, Cell<V> * ListTwo);	// orMethod
	template<class V>
	friend CoolArray<V> xorMethodCell(Cell<V> * ListOne, Cell<V> * ListTwo);	// xorMethod

protected:
	T* _value;
	Cell<T>* _right;

public:
	Cell();									// Default constructor
	Cell(T val);							// Initializer
	Cell(Cell<T>& in);						// Copy constructor
	~Cell();								// Destructor
	Cell<T>& operator= (Cell<T>& in);		// Overloaded =
	int size();								// Finds size
	T getInfo();							// Accessor 
	T& getInfoAt(int position);				// Gets info at - Accessor
	void setInfoAt(int position, T value);	// Mutator
	void add(T val, int index = 0);			// Adds a value to the list
	void remove(int index = 0);				// Removes element at index
	void addToBeginning(Cell<T> ** x, int value);	// Adds to beginning of list
	bool isPresent(Cell<T> * x, int value);			// Looks for certain number in list
	bool isEmpty();
	void swap(int x, int y);
	
};

// Default constructor
template <class T>
Cell<T>::Cell() : _value(nullptr), _right(nullptr)
{ 

}

// Initializes this value and creates a default _right 
template<class T>
Cell<T>::Cell(T val) : _value(new T(val)), _right(new Cell<T>)
{

}

// Copies a different cell
template <class T>
Cell<T>::Cell(Cell<T>& in) : _value(nullptr), _right(nullptr)
{
	// Returns if "in" is empty
	if (!in._value) 
	{ 
		return; 
	}

	// Adds value
	this->add(*in._value);

	Cell<T>* temp = in._right;

	// Iterates through in and adds values
	while (temp->_value) 
	{
		this->add(*temp->_value);
		temp = temp->_right;
	}
}

// Destructor
template <class T>
Cell<T>::~Cell() 
{
	delete _value;
	if (_right) 
	{ 
		delete _right; 
	}
}

template <class T>
Cell<T>& Cell<T>::operator= (Cell<T>& in) 
{
	// Deleting old values
	delete _value;
	delete _right;
	_value = nullptr;
	_right = nullptr;

	// Returns empty if "in" is empty
	if (!in._value) 
	{ 
		return *this; 
	}

	// Adds first value
	this->add(*in._value);

	// Adds the rest of the values while _right has a non-null value
	Cell<T>* temp = in._right;
	while (temp->_value) 
	{
		this->add(*temp->_value);
		temp = temp->_right;
	}
	return *this;
}

// Overloaded output operator
template<class T>
ostream& operator<< (ostream& s, Cell<T>& in) 
{
	// If there is no value to print, returns
	if (!in._value) 
	{ 
		return s; 
	}

	// Outputs the node
	s << *in._value << " ";

	// If _right exists, recursive call
	if (in._right->_value) 
	{ 
		s << *in._right; 
	}
	return s;
}

// Finds size of linkedlist
template <class T>
int Cell<T>::size()
{
	if (_right == nullptr)
	{
		if (_value == nullptr)
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
		return 1 + _right->size();
	}
}

// Accessor
template <class T>
T Cell<T>::getInfo()
{
	return *_value;
}

// Accessor
template <class T>
T& Cell<T>::getInfoAt(int position)
{
	if (isEmpty())
	{
		throw Exception("LinkedList out of bounds!");
	}
	if (position == 0)
	{
		return *_value;
	}
	if (_right == nullptr)
	{
		throw Exception("LinkedList out of bounds!");
	}
	return _right->getInfoAt(position - 1);
}

// Mutator
template <class T>
void Cell<T>::setInfoAt(int position, T value)
{
	if (isEmpty())
	{
		throw Exception("Sorry but the list is empty!");
	}

	if (position == 0)
	{
		*_value = value;
	}

	else if (_right == nullptr)
	{
		throw Exception("Sorry but _right is null!");
	}
	else
	{
		_right->setInfoAt(position - 1, value);
	}
}

// Shifting current cell to next and adding new cell to beginning
template <class T>
void Cell<T>::add(T val, int index) 
{
	if (_right && (index != 0)) 
	{ 
		_right->add(val, (index - 1)); 
	}
	else 
	{
		Cell<T>* temp;
		temp = (_value) ? new Cell<T>(*_value) : new Cell<T>;
		temp->_right = _right;			// Changes all of this cell's content to new cell
		delete _value;
		_value = new T(val);			// Sets new value to val
		_right = temp;					// Makes this point to temp cell
	}
}

// Removes element at index
template <class T>
void Cell<T>::remove(int index) 
{
	// Loops until the element to delete
	if (_right && (index != 0)) 
	{ 
		_right->remove(index - 1); 
	}
	// Prevents indexes greater than length from giving an error
	else if (_right) 
	{
		// Stores the next item and replaces the current value with _next's value
		Cell<T>* temp = _right;
		delete _value;
		_value = _right->_value;

		// If there is another element at the end, make it next
		if (_right->_right) 
		{ 
			_right = _right->_right; 
		}
		else 
		{ 
			_right = nullptr; 
		}

		temp->_right = nullptr;	// Deleting values safely
		temp->_value = nullptr;
		delete temp;
	}
}

// AND METHOD!
// WORKS CORRECTLY
template <class T>
CoolArray<T> andMethodCell(Cell<T> * ListOne, Cell<T> * ListTwo)
{
	// HAVE TO SORT LISTONE AND LISTTWO
	insertionSort(ListOne);
	insertionSort(ListTwo);

	Cell<T> * one = ListOne;
	Cell<T> * two = ListTwo;
	CoolArray<T> itemsFound;
	int counter = 0;

	while (one || two)  // Loops us until we hit a return statement
	{
		if (*(one->_value) > *(two->_value))
		{
			if (two->_right == nullptr || two->_right->_value == nullptr)
			{
				return itemsFound;
			}
			else
			{
				two = two->_right;
			}	
		}		

		if (*(one->_value) < *(two->_value))
		{
			if (one->_right == nullptr || one->_right->_value == nullptr)
			{
				return itemsFound;
			}
			else
			{
				one = one->_right;
			}
		}	

		if (*(one->_value) == *(two->_value))
		{
			itemsFound.add(two->_value, counter);
			counter++;
			if (one->_right == nullptr || one->_right->_value == nullptr || two->_right == nullptr || two->_right->_value == nullptr)
			{
				return itemsFound;
			}
			else
			{
				two = two->_right;
				one = one->_right;
			}
		}
	}
	return itemsFound;
}

// OR METHOD!
// WORKS CORRECTLY
template <class T>
CoolArray<T> orMethodCell(Cell<T> * ListOne, Cell<T> * ListTwo)
{
	insertionSort(ListOne);
	insertionSort(ListTwo);

	Cell<T> * one = ListOne;
	Cell<T> * two = ListTwo;
	int x = one->size();
	int y = two->size();
	CoolArray<T> itemsFound(x + y);


	while (x != 0 && y != 0)
	{
		if (*(one->_value) < *(two->_value))  //if 2 is bigger than 1, add 1 first
		{
			itemsFound.add(one->_value);
			one = one->_right;
			x--;
			itemsFound.add(two->_value);
			two = two->_right;
			y--;
		}
		else if (*(one->_value) > *(two->_value))  //if 1 is bigger than 2, add 2 first
		{
			itemsFound.add(two->_value);
			two = two->_right;
			y--;
			itemsFound.add(one->_value);
			one = one->_right;
			x--;
		}
		else if (*(one->_value) == *(two->_value))  //if they are the same -- we don't technically need this case, but it shortens the length of time removedups takes
		{
			itemsFound.add(one->_value);  //only need to add one value
			one = one->_right;
			x--;
			two = two->_right;
			y--;
		}
	}
	removeDups(itemsFound);  // Removes duplicates
	return itemsFound;
}

// XOR METHOD!
// WORKS CORRECTLY
template <class T>
CoolArray<T> xorMethodCell(Cell<T> * ListOne, Cell<T> * ListTwo)
{
	insertionSort(ListOne);
	insertionSort(ListTwo);
	CoolArray<T> x = andMethodCell(ListOne, ListTwo);
	CoolArray<T> y = orMethodCell(ListOne, ListTwo);

	int sizeOfAnd = x.size();
	int sizeOfOr = y.size();
	CoolArray<T> itemsFound;
	int i = 0;
	int j = 0;

	// Emily's Fancy Sort
	while ((j + 1 != sizeOfAnd) || (i + 1 != sizeOfOr))
	{
		if (x[j] > y[i])  //if 1 is bigger than 2
		{
			itemsFound.add(y[i]);
			i++;
		}
		else if (x[j] < y[i])
		{
			itemsFound.add(x[j]);
			j++;
		}
		else if (x[j] == y[i])
		{
			if (j + 1 != sizeOfAnd)
			{
				j++;
			}
			if (i + 1 != sizeOfOr)
			{
				i++;
			}
		}
	}
	if (sizeOfOr > sizeOfAnd)
	{
		if (x[j] != y[i])
		{
			itemsFound.add(y[i]);  // exits while loop before adding end
		}
		
	}
	else if (sizeOfOr < sizeOfAnd)
	{
		if (y[i] != x[j])
		{
			itemsFound.add(x[j]);
		}
		
	}
	return itemsFound;
}

// Adds to beginning of linkedlist
template <class T>
void Cell<T>::addToBeginning(Cell<T> ** x, int value)  // Assuming int
{
	Cell<T> * newThis = new Cell<T>();
	newThis->_value = &value;
	newThis->_right = *x;
	*x = newThis;
}

// Looks for certain number in list
template <class T>
bool Cell<T>::isPresent(Cell<T> * x, int value)
{
	Cell<T> * temp = x;
	while (temp != nullptr)
	{
		if (*(temp->_value) == value)
		{
			return 1;  // true
		}
		temp = temp->_right;
	}
	return 0; // false
}

// Sorts linkedlist
template <class T>
void insertionSort(Cell<T> * head)
{
	for (int k = 1; k < head->size(); k++)
	{
		for (int m = k - 1; ((m >= 0) && (head->getInfoAt(m) > head->getInfoAt(m+1))); m--)
		{
			T left = head->getInfoAt(m);  // Bigger than right
			T right = head->getInfoAt(m + 1);   
			
			head->setInfoAt(m, right);
			head->setInfoAt(m + 1, left);
		}
	}
}

// Tests if empty
template <class T>
bool Cell<T>::isEmpty()
{
	return (_value == nullptr);
}

// Swaps 2 values
template <class T>
void Cell<T>::swap(int x, int y)
{
	if (x >= size() || y >= size())
	{
		throw Exception("Out of bounds!");
	}
	else
	{

	}
}
