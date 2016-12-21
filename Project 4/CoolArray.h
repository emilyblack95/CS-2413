/**
CoolArray.h
Purpose: This is used to copy the old array to a new one

@author Pravallika Uppuganti
@project 4.0
@date 3/13/16
*/

#pragma once
#include <iostream>
using namespace std;
template <class V>
void copyValues(V* from, V* to, int size);

template <class V>
class CoolArray 
{
	template <class T>
	friend std::ostream& operator<< (std::ostream& s, CoolArray<T>& in);
	template <class V>
	friend void removeDups(CoolArray<V> & input);	// Removes duplicates of a coolarray
private:
	const int STD_SIZE = 10;						// Standard size of array
	int _size;										// Holds the size
	int _arraySize;									// Holds the current size of the array
	V* _array;										// Points to the array
public:
	CoolArray<V>(); 								// Default Constructor
	CoolArray<V>(int i);							// Initializer
	CoolArray<V>(CoolArray<V>& in);					// Copy constructor
	~CoolArray<V>();								// Destructor
	int size();										// Returns the size
	V getArray();									// Gets array
	void add(V in, int index = -1);					// Adds item to array
	void add(V* in, int index = -1);				// Adds item to array by reference
	void remove(int index); 						// Removes and returns the item at index
	V& operator[](int index);						// Returns item at index
	CoolArray<V>& operator= (CoolArray<V>& in);
	void swap(int from, int to);					// Swaps the values 
	bool isEmpty();									// Returns true if size is 0
	void clear();									// Clears the array
};

// Default Constructor
template <class V>
CoolArray<V>::CoolArray() : _size(0), _arraySize(STD_SIZE), _array(0)
{
	_array = new V[_arraySize];
}

// Initializes array to have i elements
template <class V>
CoolArray<V>::CoolArray(int i) : _size(0), _arraySize(i), _array(0)
{
	_array = new V[_arraySize];
}

//Copy constructor
template <class V>
CoolArray<V>::CoolArray(CoolArray<V>& in) : _size(in._size), _arraySize(in._arraySize), _array(new V[_arraySize])
{
	copyValues(in._array, _array, in._size);
}

// Destructor
template<class V>
CoolArray<V>::~CoolArray() 
{
	delete[] _array;
}

// Swaps two values by deep copy. (Inefficient, would rather just switch addresses)
template<class V>
void CoolArray<V>::swap(int from, int to) 
{
	V temp = _array[to];
	_array[to] = _array[from];
	_array[from] = temp;
}


// Output definition that really only looks good with char's
template<class V>
std::ostream& operator<< (std::ostream& s, CoolArray<V>& in) 
{
	for (int i = 0; i < in.size(); i++) 
	{
		s << in[i];
	}
	return s;
}

// Deep copy assignment overload
template<class V>
CoolArray<V>& CoolArray<V>::operator= (CoolArray<V>& in) 
{
	// Clearing old array
	delete[] _array;

	// Copying over variables and recreating array
	_size = in._size;
	_arraySize = in._arraySize;
	_array = new V[_arraySize];

	// Copies over all elements
	for (int i = 0; i < in._size; i++) 
	{
		_array[i] = in[i];
	}
	return *this;
}

// Returns element at index 
template <class V>
V& CoolArray<V>::operator[] (int index) 
{ 
	return _array[index]; 
}

// True if _size=0. False otherwise
template<class V>
bool CoolArray<V>::isEmpty() 
{ 
	return _size == 0; 
}

// Clears the array
template<class V>
void CoolArray<V>::clear() 
{
	// Deleting array and changing fields
	delete[] _array;
	_size = 0;
	_arraySize = STD_SIZE;

	// Recreating array
	_array = new V[_arraySize];
}

// Returns the amount of elements currently in _array
template <class V>
int CoolArray<V>::size() 
{ 
	return _size; 
}

// Accessor
template <class V>
V CoolArray<V>::getArray()
{
	return *_array;
}

// Removes dups
template <class V>
void removeDups(CoolArray<V> & input)
{
	int i = 1;
	int j = 0;
	if (input.size() < 2)  // if only has 1 element
	{
		return;
	}
	while (i < input.size())  // while we havent gone thru the whole list
	{
		if (input[i] == input[j])  //if index 0 == index 1
		{
			//remove(i); 
			i++;
		}
		else
		{
			input[++j] = input[i++];
		}
	}
	input._size = j+1;
}

// Adds an element by copy
template <class V>
void CoolArray<V>::add(V in, int index = -1) 
{
	// Sets the index to the last element if index is -1
	index = (index == -1) ? _size : index;

	// +1 to take into account the to-be added element
	if (_size + 1 >= _arraySize) 
	{
		// Stores old size for use in copyValues
		int oldSize = _arraySize;
		// Increases size by 10
		_arraySize += 10;
		// Creates new array with new size
		V* temp = new V[_arraySize];
		// Copies values
		copyValues(_array, temp, oldSize);
		delete[] _array;
		_array = temp;

	}

	if (index != _size) 
	{
		// Shifts all elements by deep copy. Eww inefficient
		for (int i = _size - 1; i > index - 1; i--) 
		{
			_array[i] = _array[i - 1];
		}
	}
	_array[index] = in;
	_size++;
}

// Adds an element by sending it an address that is deleted when
// it leaves the scope.
template <class V>
void CoolArray<V>::add(V* in, int index = -1) 
{

	// Sets the index to the last element if index is -1
	index = (index == -1) ? _size : index;

	// +1 to take into account the to-be added element
	if (_size + 1 >= _arraySize) 
	{
		// Stores old size for use in copyValues
		int oldSize = _arraySize;
		// Increases size by 10
		_arraySize += 10;
		// Creates new array with new size
		V* temp = new V[_arraySize];
		// Copies values
		copyValues(_array, temp, oldSize);
		delete[] _array;
		_array = temp;

	}
	if (index != _size) 
	{
		// Shifts all elements by deep copy. Eww inefficient
		for (int i = _size - 1; i > index - 1; i--) 
		{
			_array[i] = _array[i - 1];
		}
	}
	// Deep copy
	_array[index] = *in;
	_size++;
}

// Copies values from one array to another
template <class V>
void copyValues(V* from, V* to, int size) 
{
	for (int i = 0; i < size; i++) 
	{
		to[i] = from[i];
	}
}

// Removes the specific element
template <class V>
void CoolArray<V>::remove(int index = 0) 
{
	// Shifts all other elements
	for (int i = index; (i < _size - 1); i++) 
	{
		_array[i] = _array[i + 1];
	}

	// Decrements the total size
	_size--;
}
