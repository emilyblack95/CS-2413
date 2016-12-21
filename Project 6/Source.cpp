/**
Source.cpp
Purpose: This class runs the program.

@author Emily Black
@version 6.0
@date 4/20/16
*/

#pragma once
#include <iostream>
#include "Array.h"
#include "ParentMultiTree.h"
#include "Exceptions.h"
#define letsTest false   // TRUE = TEST METHODS, FALSE = REDIRECTED INPUT	
using namespace std;

void main()
{
	// TESTS REDIRECTED INPUT
	if (letsTest == false)
	{
		int parent;
		int counter = 1;
		int numOfChildren;
		int x;
		int numOfNodes;
		bool firstTime = true;
		cin >> numOfNodes;
		Array<int> parentArray(numOfNodes);
		Array<int> childOrder(numOfNodes);

		for (int i = 0; i < numOfNodes; i++)  // Sets all elements equal to 0
		{
			parentArray.add(0, i);
			childOrder.add(0, i);
		}

		while (!cin.eof())  // While we havent reached the end of the file
		{
			cin >> parent;
			cin >> numOfChildren;

			if (firstTime)  // Adds root
			{
				parentArray[parent] = -1;
				childOrder[parent] = -1;
				firstTime = false;
			}

			while (numOfChildren != 0)
			{
				cin >> x;
				parentArray[x] = parent; 
				childOrder[x] = counter; 
				counter++;
				numOfChildren--;
			}
			counter = 0;
		}
		ParentMultiTree<int> myTree(numOfNodes, parentArray, childOrder);
		cout << "Preorder traversal: " << endl;
		cout << myTree << endl;
		cout << "ParentMultiTree successfully created!" << endl;
	}

	// TESTS METHODS - TESTED ALL & THEY ALL WORK
	else if (letsTest == true)
	{
		cout << "Which one would you like to test? (TYPE #)" << endl;
		cout << "1. empty constructor" << endl;
		cout << "2. non-empty constructor" << endl;
		cout << "3. destructor" << endl;
		cout << "4. copy constructor" << endl;
		cout << "5. overloaded equal to operator" << endl;
		cout << "6. ostream operator(preorder traversal)" << endl;
		cout << "7. size method" << endl;
		cout << "8. height method" << endl;
		cout << "9. getChildren method" << endl;
		cout << "10. preorder traversal method" << endl;
		int answer;
		cin >> answer;

		//empty constructor - TESTED & WORKS
		if (answer == 1)
		{
			ParentMultiTree<int> myTree;
			cout << "Empty constructor successfully tested." << endl;
		}

		//non-empty constructor - TESTED & WORKS
		else if (answer == 2)
		{
			int size;
			cout << "Enter the size of your tree:" << endl;
			cin >> size;
			if (size < 0)
			{
				throw Exception("Sorry you cannot have a negative sized tree.");
			}
			ParentMultiTree<int> myTree(size);

			cout << "Non-empty constructor successfully tested." << endl;
		}

		//destructor - TESTED & WORKS
		else if (answer == 3)
		{
			// Nothing to test here, size I implemented ParentBinaryTree as having no pointer class variables.
			cout << "Destructor successfully tested." << endl;
		}

		//copy constructor - TESTED & WORKS
		else if (answer == 4)
		{
			int numNodes = 22;

			Array<int> parentArray(numNodes);
			parentArray.add(1, 0);
			parentArray.add(5, 1);
			parentArray.add(1, 2);
			parentArray.add(10, 3);
			parentArray.add(10, 4);
			parentArray.add(20, 5);
			parentArray.add(5, 6);
			parentArray.add(8, 7);
			parentArray.add(20, 8);
			parentArray.add(20, 9);
			parentArray.add(9, 10);
			parentArray.add(9, 11);
			parentArray.add(9, 12);
			parentArray.add(9, 13);
			parentArray.add(12, 14);
			parentArray.add(21, 15);
			parentArray.add(21, 16);
			parentArray.add(21, 17);
			parentArray.add(21, 18);
			parentArray.add(20, 19);
			parentArray.add(-1, 20);
			parentArray.add(19, 21);

			Array<int> childOrder(numNodes);
			childOrder.add(1, 0);
			childOrder.add(1, 1);
			childOrder.add(2, 2);
			childOrder.add(1, 3);
			childOrder.add(2, 4);
			childOrder.add(1, 5);
			childOrder.add(2, 6);
			childOrder.add(1, 7);
			childOrder.add(2, 8);
			childOrder.add(3, 9);
			childOrder.add(1, 10);
			childOrder.add(2, 11);
			childOrder.add(3, 12);
			childOrder.add(4, 13);
			childOrder.add(1, 14);
			childOrder.add(1, 15);
			childOrder.add(2, 16);
			childOrder.add(3, 17);
			childOrder.add(4, 18);
			childOrder.add(4, 19);
			childOrder.add(-1, 20);
			childOrder.add(1, 21);

			ParentMultiTree<int> testOne(numNodes, parentArray, childOrder);
			ParentMultiTree<int> testTwo(numNodes);

			testTwo = testOne;
			cout << "Copy constructor successfully tested." << endl;
		}

		//overloaded equal to operator - TESTED & WORKS
		else if (answer == 5)
		{
			int numNodes = 22;

			Array<int> parentArray(numNodes);
			parentArray.add(1, 0);
			parentArray.add(5, 1);
			parentArray.add(1, 2);
			parentArray.add(10, 3);
			parentArray.add(10, 4);
			parentArray.add(20, 5);
			parentArray.add(5, 6);
			parentArray.add(8, 7);
			parentArray.add(20, 8);
			parentArray.add(20, 9);
			parentArray.add(9, 10);
			parentArray.add(9, 11);
			parentArray.add(9, 12);
			parentArray.add(9, 13);
			parentArray.add(12, 14);
			parentArray.add(21, 15);
			parentArray.add(21, 16);
			parentArray.add(21, 17);
			parentArray.add(21, 18);
			parentArray.add(20, 19);
			parentArray.add(-1, 20);
			parentArray.add(19, 21);

			Array<int> childOrder(numNodes);
			childOrder.add(1, 0);
			childOrder.add(1, 1);
			childOrder.add(2, 2);
			childOrder.add(1, 3);
			childOrder.add(2, 4);
			childOrder.add(1, 5);
			childOrder.add(2, 6);
			childOrder.add(1, 7);
			childOrder.add(2, 8);
			childOrder.add(3, 9);
			childOrder.add(1, 10);
			childOrder.add(2, 11);
			childOrder.add(3, 12);
			childOrder.add(4, 13);
			childOrder.add(1, 14);
			childOrder.add(1, 15);
			childOrder.add(2, 16);
			childOrder.add(3, 17);
			childOrder.add(4, 18);
			childOrder.add(4, 19);
			childOrder.add(-1, 20);
			childOrder.add(1, 21);

			ParentMultiTree<int> testOne(numNodes, parentArray, childOrder);
			ParentMultiTree<int> testTwo(numNodes);

			testTwo = testOne;
			cout << "Overloaded equals operator successfully tested." << endl;
		}

		//ostream operator(preorder traversal) - TESTED & WORKS
		else if (answer == 6)
		{
			int numNodes = 22;

			Array<int> parentArray(numNodes);
			parentArray.add(1, 0);
			parentArray.add(5, 1);
			parentArray.add(1, 2);
			parentArray.add(10, 3);
			parentArray.add(10, 4);
			parentArray.add(20, 5);
			parentArray.add(5, 6);
			parentArray.add(8, 7);
			parentArray.add(20, 8);
			parentArray.add(20, 9);
			parentArray.add(9, 10);
			parentArray.add(9, 11);
			parentArray.add(9, 12);
			parentArray.add(9, 13);
			parentArray.add(12, 14);
			parentArray.add(21, 15);
			parentArray.add(21, 16);
			parentArray.add(21, 17);
			parentArray.add(21, 18);
			parentArray.add(20, 19);
			parentArray.add(-1, 20);
			parentArray.add(19, 21);

			Array<int> childOrder(numNodes);
			childOrder.add(1, 0);
			childOrder.add(1, 1);
			childOrder.add(2, 2);
			childOrder.add(1, 3);
			childOrder.add(2, 4);
			childOrder.add(1, 5);
			childOrder.add(2, 6);
			childOrder.add(1, 7);
			childOrder.add(2, 8);
			childOrder.add(3, 9);
			childOrder.add(1, 10);
			childOrder.add(2, 11);
			childOrder.add(3, 12);
			childOrder.add(4, 13);
			childOrder.add(1, 14);
			childOrder.add(1, 15);
			childOrder.add(2, 16);
			childOrder.add(3, 17);
			childOrder.add(4, 18);
			childOrder.add(4, 19);
			childOrder.add(-1, 20);
			childOrder.add(1, 21);

			ParentMultiTree<int> myTree(numNodes, parentArray, childOrder);

			cout << myTree << endl;
			cout << "Ostream operator successfully tested." << endl;
		}

		//size method - TESTED & WORKS
		else if (answer == 7)
		{
			int numNodes = 22;

			Array<int> parentArray(numNodes);
			parentArray.add(1, 0);
			parentArray.add(5, 1);
			parentArray.add(1, 2);
			parentArray.add(10, 3);
			parentArray.add(10, 4);
			parentArray.add(20, 5);
			parentArray.add(5, 6);
			parentArray.add(8, 7);
			parentArray.add(20, 8);
			parentArray.add(20, 9);
			parentArray.add(9, 10);
			parentArray.add(9, 11);
			parentArray.add(9, 12);
			parentArray.add(9, 13);
			parentArray.add(12, 14);
			parentArray.add(21, 15);
			parentArray.add(21, 16);
			parentArray.add(21, 17);
			parentArray.add(21, 18);
			parentArray.add(20, 19);
			parentArray.add(-1, 20);
			parentArray.add(19, 21);

			Array<int> childOrder(numNodes);
			childOrder.add(1, 0);
			childOrder.add(1, 1);
			childOrder.add(2, 2);
			childOrder.add(1, 3);
			childOrder.add(2, 4);
			childOrder.add(1, 5);
			childOrder.add(2, 6);
			childOrder.add(1, 7);
			childOrder.add(2, 8);
			childOrder.add(3, 9);
			childOrder.add(1, 10);
			childOrder.add(2, 11);
			childOrder.add(3, 12);
			childOrder.add(4, 13);
			childOrder.add(1, 14);
			childOrder.add(1, 15);
			childOrder.add(2, 16);
			childOrder.add(3, 17);
			childOrder.add(4, 18);
			childOrder.add(4, 19);
			childOrder.add(-1, 20);
			childOrder.add(1, 21);

			ParentMultiTree<int> myTree(numNodes, parentArray, childOrder);
			int size = myTree.size();
			cout << "The size is: " << size << endl;
			cout << "Size method successfully tested." << endl;
		}

		//height method - TESTED & WORKS
		else if (answer == 8)
		{
			int numNodes = 22;

			Array<int> parentArray(numNodes);
			parentArray.add(1, 0);
			parentArray.add(5, 1);
			parentArray.add(1, 2);
			parentArray.add(10, 3);
			parentArray.add(10, 4);
			parentArray.add(20, 5);
			parentArray.add(5, 6);
			parentArray.add(8, 7);
			parentArray.add(20, 8);
			parentArray.add(20, 9);
			parentArray.add(9, 10);
			parentArray.add(9, 11);
			parentArray.add(9, 12);
			parentArray.add(9, 13);
			parentArray.add(12, 14);
			parentArray.add(21, 15);
			parentArray.add(21, 16);
			parentArray.add(21, 17);
			parentArray.add(21, 18);
			parentArray.add(20, 19);
			parentArray.add(-1, 20);
			parentArray.add(19, 21);

			Array<int> childOrder(numNodes);
			childOrder.add(1, 0);
			childOrder.add(1, 1);
			childOrder.add(2, 2);
			childOrder.add(1, 3);
			childOrder.add(2, 4);
			childOrder.add(1, 5);
			childOrder.add(2, 6);
			childOrder.add(1, 7);
			childOrder.add(2, 8);
			childOrder.add(3, 9);
			childOrder.add(1, 10);
			childOrder.add(2, 11);
			childOrder.add(3, 12);
			childOrder.add(4, 13);
			childOrder.add(1, 14);
			childOrder.add(1, 15);
			childOrder.add(2, 16);
			childOrder.add(3, 17);
			childOrder.add(4, 18);
			childOrder.add(4, 19);
			childOrder.add(-1, 20);
			childOrder.add(1, 21);

			ParentMultiTree<int> myTree(numNodes, parentArray, childOrder);
			int height = myTree.height(20);
			cout << "The height is: " << height << endl;
			cout << "Height method successfully tested." << endl;
		}

		//getChildren method - TESTED & WORKS
		else if (answer == 9)
		{
			int numNodes = 22;

			Array<int> parentArray(numNodes);
			parentArray.add(1, 0);
			parentArray.add(5, 1);
			parentArray.add(1, 2);
			parentArray.add(10, 3);
			parentArray.add(10, 4);
			parentArray.add(20, 5);
			parentArray.add(5, 6);
			parentArray.add(8, 7);
			parentArray.add(20, 8);
			parentArray.add(20, 9);
			parentArray.add(9, 10);
			parentArray.add(9, 11);
			parentArray.add(9, 12);
			parentArray.add(9, 13);
			parentArray.add(12, 14);
			parentArray.add(21, 15);
			parentArray.add(21, 16);
			parentArray.add(21, 17);
			parentArray.add(21, 18);
			parentArray.add(20, 19);
			parentArray.add(-1, 20);
			parentArray.add(19, 21);

			Array<int> childOrder(numNodes);
			childOrder.add(1, 0);
			childOrder.add(1, 1);
			childOrder.add(2, 2);
			childOrder.add(1, 3);
			childOrder.add(2, 4);
			childOrder.add(1, 5);
			childOrder.add(2, 6);
			childOrder.add(1, 7);
			childOrder.add(2, 8);
			childOrder.add(3, 9);
			childOrder.add(1, 10);
			childOrder.add(2, 11);
			childOrder.add(3, 12);
			childOrder.add(4, 13);
			childOrder.add(1, 14);
			childOrder.add(1, 15);
			childOrder.add(2, 16);
			childOrder.add(3, 17);
			childOrder.add(4, 18);
			childOrder.add(4, 19);
			childOrder.add(-1, 20);
			childOrder.add(1, 21);

			ParentMultiTree<int> myTree(numNodes, parentArray, childOrder);
			int parent;
			cout << "Enter a parent between 1-21:" << endl;
			cin >> parent;
			if (parent < 0)
			{
				throw Exception("Sorry you cannot have a negative parent.");
			}
			Array<int> answers = myTree.getChildren(parent);  // Feel free to change this number
			cout << "The children are: " << answers << endl;
			cout << "getChildren method successfully tested." << endl;
		}

		//preorder traversal method - TESTED & WORKS
		else if (answer == 10)
		{
			int numNodes = 22;

			Array<int> parentArray(numNodes);
			parentArray.add(1, 0);
			parentArray.add(5, 1);
			parentArray.add(1, 2);
			parentArray.add(10, 3);
			parentArray.add(10, 4);
			parentArray.add(20, 5);
			parentArray.add(5, 6);
			parentArray.add(8, 7);
			parentArray.add(20, 8);
			parentArray.add(20, 9);
			parentArray.add(9, 10);
			parentArray.add(9, 11);
			parentArray.add(9, 12);
			parentArray.add(9, 13);
			parentArray.add(12, 14);
			parentArray.add(21, 15);
			parentArray.add(21, 16);
			parentArray.add(21, 17);
			parentArray.add(21, 18);
			parentArray.add(20, 19);
			parentArray.add(-1, 20);
			parentArray.add(19, 21);

			Array<int> childOrder(numNodes);
			childOrder.add(1, 0);
			childOrder.add(1, 1);
			childOrder.add(2, 2);
			childOrder.add(1, 3);
			childOrder.add(2, 4);
			childOrder.add(1, 5);
			childOrder.add(2, 6);
			childOrder.add(1, 7);
			childOrder.add(2, 8);
			childOrder.add(3, 9);
			childOrder.add(1, 10);
			childOrder.add(2, 11);
			childOrder.add(3, 12);
			childOrder.add(4, 13);
			childOrder.add(1, 14);
			childOrder.add(1, 15);
			childOrder.add(2, 16);
			childOrder.add(3, 17);
			childOrder.add(4, 18);
			childOrder.add(4, 19);
			childOrder.add(-1, 20);
			childOrder.add(1, 21);

			ParentMultiTree<int> myTree(numNodes, parentArray, childOrder);

			cout << myTree << endl;
			cout << "Preorder traversal successfully tested." << endl;
		}

		//default
		else
		{
			throw Exception("Sorry, you must enter a number between 1 and 10.");
		}
	}
}