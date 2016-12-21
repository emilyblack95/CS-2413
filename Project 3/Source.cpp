/**
Source.cpp
Purpose: This class runs the main functions.

@author Emily Black
@version 3.0
@date 2/24/16
*/

#include <iostream>
#define MAX_SIZE_OF_NAME 50  //default size for buffer before it breaks
#define MAX_SIZE_OF_INT 50
#include "Exceptions.h"
#include "CellNode.h"
#include "MasterCell.h"
#include "StringHelpers.h"
using namespace std;


int main()
{
	char blank = NULL;
	char aChar = NULL;
	char firstWord[MAX_SIZE_OF_NAME];  //first word buffer
	char intBuffer[MAX_SIZE_OF_INT]; //int buffer
	CellNode<char, int> myCellNode;  //contains values for the cell nodes 
	MasterCell<char, int> myMasterCell;  //contains all the cellnodes 
	Cell<int> myCell;
	CellNode<char, int> myEmptyCellNode;  //used for the purpose of clearing out the cellnode
	Cell<int> myEmptyCell;  //used for the purpose of clearing out the cell
	int i;
	int k;
	int myInt;
	bool readInput = true; //~~~~~~TURN FALSE, AND CHANGE PROJECT PORPERTIES TO TEST METHODS~~~~~~


	/**
	WHEN TESTING THIS PART
	MAKE SURE YOU HAVE PROJECT PROPERTIES READ IN FILE AS ARGUMENT
	AND THAT YOU SET readInput = true
	*/
	while (readInput == true)
	{
		while (!cin.eof()) 
		{
			while (!cin.eof())
			{
				try {
					i = 0;
					emptyString(firstWord, MAX_SIZE_OF_NAME);
					do
					{
						cin.get(aChar);
						firstWord[i] = aChar;
						i++;
					} while ((aChar != ',') && (aChar != '\n') && (i < MAX_SIZE_OF_NAME));  //after we exit this, we have first word	


					i = i - 1;
					firstWord[i] = '\0';
					myCellNode.setInfo(firstWord);  //adds first word to cell

					cin.get(blank);  //grabs space

					while ((blank != '\n') && (aChar != '\n') && (!cin.eof()))   //while we havent reached the end of the line
					{
						k = 0;
						emptyString(intBuffer, MAX_SIZE_OF_INT);
						do
						{
							cin.get(aChar);
							intBuffer[k] = aChar;
							k++;
						} while ((aChar != ' ') && (aChar != '\n') && (!cin.eof()));  //(!cin.eof())


						k = k - 1;
						intBuffer[k] = '\0';

						myInt = 0;
						//this function converts a list of chars to ints
						for (int m = 0; m < k; m++)
						{
							myInt *= 10;
							myInt += intBuffer[m] - '0';  //converts char to int
						}
						myCell.add(myInt);
					}
					myCellNode.setCellList(&myCell);  //this connects mycell and mycellnode together
					myMasterCell.addRow(myCellNode);  //copies myCell correctly


					myCellNode = myEmptyCellNode;
					myCell = myEmptyCell;
				}
				catch (Exception e)
				{
					e.printMessage();
				}
			}
		}
		cout << "Input has been successfully read in." << endl;
		return 0;
	}


	/**
	WHEN TESTING THIS PART
	MAKE SURE YOU STOP READING FROM A FILE
	AND THAT YOU SET readInput = false
	*/
	while (readInput == false)
	{
		int input; //for testing methods
		int keepTesting = 1;

		//Now we must test each of the 6 basic methods for a C++ class work!
		cout << "1 for empty constructor." << endl;
		cout << "2 for non-empty constructor." << endl;
		cout << "3 for destructor." << endl;
		cout << "4 for copy constructor." << endl;
		cout << "5 for overloaded equals operator." << endl;
		cout << "6 for ostream operator." << endl;
		cin >> input;
		try
		{
			while(keepTesting == 1)
			{
				if (input == 1) //tests empty constructor
				{
					MasterCell<int, int> testMCell;
					CellNode<int, int> testNode;
					Cell<int> testCell;

					cout << "Default constructor successfully invoked!" << endl;
				}
				else if (input == 2) //tests non-empty constructor
				{
					Cell<int> testCell1(483);
					Cell<int> testCell2(234, &testCell1);
					Cell<int> testCell3(523, &testCell2);
					
					CellNode<int, int> testCellNode1(99);
					CellNode<int, int> testCellNode2(231, &testCellNode1);
					CellNode<int, int> testCellNode3(2334, &testCellNode2);
					
					int numOfCellNodes = 3;
					CellNode<int, int> myListOfNodes[3] = { testCellNode1, testCellNode2, testCellNode3 };
					MasterCell<int, int> testMCell(myListOfNodes, numOfCellNodes);  

					cout << "Initializer constructor successfully invoked!" << endl;
				}
				else if (input == 3) //tests destructor
				{
					Cell<int> * testCell = new Cell<int>{ 50, NULL }; //why is this giving me errors?

					CellNode<int, int> * testCellNode = new CellNode<int, int>{ 4323, NULL }; //why is this giving me errors?

					CellNode<int, int> testCellNode1(4323, NULL); //creates a cellnode of type int,int with value 4323 that points to nothing
					CellNode<int, int> testCellNode2(4723, NULL);
					CellNode<int, int> testCellNode3(2334, NULL);
					CellNode<int, int> cellNodeArray[3];
					cellNodeArray[0] = testCellNode1;
					cellNodeArray[1] = testCellNode2;
					cellNodeArray[2] = testCellNode3;
					MasterCell<int, int> * testMCell = new MasterCell<int, int>{ cellNodeArray, 3 };  //why is this giving me errors?

					delete testCell;
					delete testCellNode;
					delete testMCell;

					cout << "Destructor successfully invoked!" << endl;

				}
				else if (input == 4) //tests copy constructor
				{
					Cell<int> testCell1(483);
					Cell<int> testCell2(234, &testCell1);
					Cell<int> testCell3(523, &testCell2);
					testCell2 = testCell3;
					testCell1 = testCell3;

					CellNode<int, int> testCellNode1(99);
					CellNode<int, int> testCellNode2(231, &testCellNode1);
					CellNode<int, int> testCellNode3(2334, &testCellNode2);
					testCellNode2 = testCellNode3;
					testCellNode1 = testCellNode3;

					int numOfCellNodes1 = 3;
					CellNode<int, int> myListOfNodes1[3] = { testCellNode1, testCellNode2, testCellNode3 };
					MasterCell<int, int> testMCell1(myListOfNodes1, numOfCellNodes1);

					int numOfCellNodes2 = 4;
					CellNode<int, int> testCellNode4(99);
					CellNode<int, int> testCellNode5(231, &testCellNode4);
					CellNode<int, int> testCellNode6(2334, &testCellNode5);
					CellNode<int, int> testCellNode7(2334, &testCellNode6);
					CellNode<int, int> myListOfNodes2[4] = { testCellNode4, testCellNode5, testCellNode6, testCellNode7 };
					MasterCell<int, int> testMCell2(myListOfNodes2, numOfCellNodes2);

					testMCell1 = testMCell2;

					cout << "Copy constructor successfully invoked!" << endl;
				}
				else if (input == 5) //tests overloaded equals operator - basically same thing as copy constructor because they call they same methods
				{
					Cell<int> testCell1(483);
					Cell<int> testCell2(234, &testCell1);
					Cell<int> testCell3(523, &testCell2);
					testCell2 = testCell3;
					testCell1 = testCell3;

					CellNode<int, int> testCellNode1(99);
					CellNode<int, int> testCellNode2(231, &testCellNode1);
					CellNode<int, int> testCellNode3(2334, &testCellNode2);
					testCellNode2 = testCellNode3;
					testCellNode1 = testCellNode3;

					int numOfCellNodes1 = 3;
					CellNode<int, int> myListOfNodes1[3] = { testCellNode1, testCellNode2, testCellNode3 };
					MasterCell<int, int> testMCell1(myListOfNodes1, numOfCellNodes1);

					int numOfCellNodes2 = 4;
					CellNode<int, int> testCellNode4(99);
					CellNode<int, int> testCellNode5(231, &testCellNode4);
					CellNode<int, int> testCellNode6(2334, &testCellNode5);
					CellNode<int, int> testCellNode7(2334, &testCellNode6);
					CellNode<int, int> myListOfNodes2[4] = { testCellNode4, testCellNode5, testCellNode6, testCellNode7 };
					MasterCell<int, int> testMCell2(myListOfNodes2, numOfCellNodes2);

					testMCell1 = testMCell2;

					cout << "Overloaded equals operator successfully invoked!" << endl;
				}
				else if (input == 6)  //tests ostream operator - WARNING WONT WORK!
				{
					Cell<int> testCell1(483);
					Cell<int> testCell2(234, &testCell1);
					Cell<int> testCell3(523, &testCell2);
					cout << testCell3 << endl;

					CellNode<int, int> testCellNode1(99);
					CellNode<int, int> testCellNode2(231, &testCellNode1);
					CellNode<int, int> testCellNode3(2334, &testCellNode2);
					cout << testCellNode2 << endl;

					int numOfCellNodes = 3;
					CellNode<int, int> myListOfNodes[3] = { testCellNode1, testCellNode2, testCellNode3 };
					MasterCell<int, int> testMCell(myListOfNodes, numOfCellNodes);
					cout << testMCell << endl;

					cout << "Overloaded ostream operator successfully invoked!" << endl;
				}
				else
				{
					cout << "Sorry but that is invalid input. If you didn't enter any input, that is because you are still reading in from the file." << endl;
					return 0;
				}
				cout << "Do you want to keep testing? Type 1 for yes or 2 for no." << endl;
				cin >> keepTesting;
			}
			if (keepTesting == 2)
			{
				cout << "Goodbye!" << endl;
				return 0;
			}
			else
			{
				cout << "Sorry but that is invalid input! Try again!" << endl;
				return 0;
			}
		}
		catch (Exception e)
		{
			e.printMessage();
		}
	}
	return 0;
}