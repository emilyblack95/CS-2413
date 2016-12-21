/**
Source.cpp
Purpose: This class runs the main program

@author Emily Black
@credit Pravallika Uppuganti
@project 4.0
@date 3/13/16
*/

#pragma once
#include <iostream>
#include "MasterCell.h"
#include "CoolArray.h"
#include "Cell.h"
using namespace std;
int main()
{
	/////////////////////////////////START TESTING/////////////////////////////////
	// Testing from cell class even though I implemented it in MasterCell. findkeyword already works.


	Cell<int> * listOne = new Cell<int>();
	listOne->add(1, 0);
	listOne->add(2, 1);
	listOne->add(7, 1);
	listOne->add(9, 1);
	listOne->add(3, 1);

	Cell<int> * listTwo = new Cell<int>();
	listTwo->add(1, 0);
	listTwo->add(5, 1);
	listTwo->add(7, 1);
	listTwo->add(3, 1);
	listTwo->add(4, 1);

	//CoolArray<int> x = andMethodCell(listOne, listTwo); //WORKS CORRECTLY
	//CoolArray<int> x = orMethodCell(listOne, listTwo);  //WORKS CORRECTLY
	CoolArray<int> x = xorMethodCell(listOne, listTwo);
	cout << x << endl;
	//cout << listOne->orMethodCell(listOne, listTwo) << endl;
	// know xor method doesnt work

	return 0;



	/////////////////////////////////END TESTING/////////////////////////////////


	char c;											// Next char from standard in
	char blank;
	int numItems;									// Number of cells to make
	int val;										// Value of cell
	int nodes = 0;									// Number of cells added to masterNode
	bool firstLine = false;							// Expression to see if we read in first number
	int numberOfLines = 1;							// Tells us how many lines we got to read
	CoolArray<char> name;							// Name of CellNode
	MasterCell<CoolArray<char>, int> masterCell;	// Holds CellNodes

	cin >> numberOfLines;

	while (numberOfLines > 0)
	{
			// Clearing name
			name.clear();
			// Getting the name of the Node to add
			do
			{
				cin.get(c);
				if (c != ',')
				{
					name.add(c);
				}
			} while (!cin.eof() && c != ',');

			cin.get(blank);		// Gets first space

			masterCell.addNode(name); 					// Adds node to masterCell
			cin >> numItems;							// Getting number of cells

			while (numItems > 0)
			{
				cin >> val;
				masterCell[nodes].add(val);
				numItems--;
			}
			nodes++;									// Increments node count

			while (!cin.eof() && c != '\n')
			{
				cin.get(c);
			}											// Clearing until next newline
			numberOfLines--;
	}
	cout << masterCell << endl;
}