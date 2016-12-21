/**
MasterCell.h
Purpose: This class creates the object that is associated with each list. (The 1st word @ the beginning of the input)
suppose to go VERTICALLY

@author Emily Black
@version 3.0
@date 3/4/16
*/

#pragma once
#include <iostream>
#include "Exceptions.h"
#include "CellNode.h"
#define TOTAL_CAPACITY 50  //how big the array of cellnodes can be
using namespace std;

template <class DT1, class DT2>
class MasterCell
{
	friend ostream& operator<< <>(ostream & s, const MasterCell<DT1, DT2> & obj);  //overloaded ostream operator

protected:
	CellNode<DT1, DT2> _myCellNodes[TOTAL_CAPACITY];
	int numberOfCellNodes;
	void Copy(MasterCell<DT1, DT2> & obj);  //Protected Copy Function
public:
	MasterCell();  //Default Constructor
	MasterCell(CellNode<DT1, DT2> myCellNodes[], int numCellNodes); //Initializer Constructor
	MasterCell(MasterCell<DT1, DT2> & obj);  //Copy Constructor
	MasterCell<DT1, DT2>& operator= (MasterCell<DT1, DT2> & obj); //Overloaded equals operator
	void addRow(CellNode<DT1, DT2> & nodeToAdd); //Mutator - ADDS VERTICALLY
	~MasterCell(); //destructor
};


//Copy Function
template <class DT1, class DT2>
void MasterCell<DT1, DT2>::Copy(MasterCell<DT1, DT2> & obj)
{
	if (obj.numberOfCellNodes == 0)  //if true that size = 0
	{
		numberOfCellNodes = 0;
	}
	else
	{
		for (int i = 0; i < obj.numberOfCellNodes; i++)
		{
			_myCellNodes[i] = obj._myCellNodes[i];   //PROVES THAT MASTERCELL GOES VERTICALLY
		}
		numberOfCellNodes = obj.numberOfCellNodes;
	}
}

//Default Constructor
template <class DT1, class DT2>
MasterCell<DT1, DT2>::MasterCell()
{
	numberOfCellNodes = 0;
}

//Initializer Constructor
template <class DT1, class DT2>
MasterCell<DT1, DT2>::MasterCell(CellNode<DT1, DT2> myCellNodes[], int numCellNodes)
{ 
	for (int i = 0; i < numCellNodes; i++)
	{
		_myCellNodes[i] = myCellNodes[i];   //PROVES THAT MASTERCELL GOES VERTICALLY
	}
	numberOfCellNodes = numCellNodes;
}

//Copy Constructor
template <class DT1, class DT2>
MasterCell<DT1, DT2>::MasterCell(MasterCell<DT1, DT2> & obj)
{
	Copy(obj);
}

//Overloaded Equals Operator
template <class DT1, class DT2>
MasterCell<DT1, DT2>& MasterCell<DT1, DT2>::operator= (MasterCell<DT1, DT2> & obj)
{
	Copy(obj);
	return (*this);
}

//Overloaded ostream operator
template <class DT1, class DT2>
ostream& operator<< <>(ostream & s, const MasterCell<DT1, DT2> & obj)
{
	if (obj.numberOfCellNodes == 0)  //if size = 0
	{
		s << "No mastercell values to display!" << endl;
	}
	for (int i = 0; i < obj.numberOfCellNodes; i++)
	{
		s << obj._myCellNodes[i] << ", ";
	}

	return s;
}

//Mutator -- THERES A PROBLEM WITH THIS METHOD
template<class DT1, class DT2>
void MasterCell<DT1, DT2>::addRow(CellNode<DT1, DT2> & nodeToAdd)
{
	_myCellNodes[numberOfCellNodes] = nodeToAdd;
	numberOfCellNodes++;
}

//Destructor
template <class DT1, class DT2>
MasterCell<DT1, DT2>::~MasterCell()
{
	for (int i = 0; i < TOTAL_CAPACITY-1; i++)
	{
		_myCellNodes[i].~CellNode();
	}
}