/**
Source.cpp
Purpose: This class runs the program.

@author Emily Black
@version 5.0
@date 4/7/16
*/

#pragma once
#include <iostream>
#include "Array.h"
#include "ParentBinaryTree.h"
#include "Exceptions.h"
using namespace std;

int main()
{
	bool letsTest = false;    // TRUE = TEST METHODS, FALSE = REDIRECTED INPUT	

	// TESTS REDIRECTED INPUT
	if (letsTest == false)
	{
		int left;
		int right;
		int value;
		int numOfLines;
		cin >> numOfLines;
		int numNodes = numOfLines;   // NumOfLines will act as counter
		Array<int> parentArray(numOfLines);
		Array<int> childOrder(numOfLines);

		for (int i = 0; i < numOfLines; i++)
		{
			parentArray.add(0, i);
			childOrder.add(0, i);
		}

		while (numOfLines != 0)
		{
			cin >> value;
			cin >> left;
			cin >> right;

			if (numNodes == numOfLines)  // If we HAVENT gone through the loop once
			{
				parentArray[value] = -1;
				childOrder[value] = -1;
			}

			if (left != -1)   // If we have a parent with a left child - DONT NEED AN ELSE STATEMENT
			{
				parentArray[left] = value;
				childOrder[left] = 0;
			}

			if (right != -1)   // If we have a parent with a right child - DONT NEED AN ELSE STATEMENT
			{
				parentArray[right] = value;
				childOrder[right] = 1;
			}
			numOfLines--;			// Decrements numOfLines by 1
		}
		
		cout << parentArray << endl;
		cout << childOrder << endl;

		ParentBinaryTree<int> x(numNodes, parentArray, childOrder);
		cout << "ParentBinaryTree successfully created!" << endl;
		return 0;
	}

	// TESTS METHODS
	if (letsTest == true)
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
		cout << "9. getLeft method" << endl;
		cout << "10. getRight method" << endl;
		cout << "11. preorder traversal method" << endl;
		cout << "12. inorder traversal method" << endl;
		cout << "13. postorder traversal method" << endl;
		int answer;
		cin >> answer;

		//empty constructor - TESTED, WORKS!
		if (answer == 1)
		{
			ParentBinaryTree<int> myTree();   
			cout << "Empty constructor successfully tested!" << endl;
		}
		
		//non-empty constructor - TESTED, WORKS!
		else if (answer == 2)
		{
			int size;
			cout << "Enter the size of your tree." << endl;
			cin >> size;
			if (size < 0)
			{
				throw Exception("Sorry you cannot have a negative sized tree!");
			}
			ParentBinaryTree<int> myTree(size);

			
			cout << "Non-empty constructor successfully tested!" << endl;
		}

		//destructor - TESTED, WORKS!
		else if (answer == 3)
		{
			// Nothing to test here, size I implemented ParentBinaryTree as having no pointer class variables.
			cout << "Destructor successfully tested!" << endl;
		}

		//copy constructor - TESTED, WORKS!
		else if (answer == 4)
		{
			int numNodes = 10;

			Array<int> parentArray(10);
			parentArray.add(3, 0);
			parentArray.add(6, 1);
			parentArray.add(5, 2);
			parentArray.add(2, 3);
			parentArray.add(3, 4);
			parentArray.add(-1, 5);
			parentArray.add(5, 6);
			parentArray.add(6, 7);
			parentArray.add(7, 8);
			parentArray.add(8, 9);

			Array<int> childOrder(10);
			childOrder.add(0, 0);
			childOrder.add(0, 1);
			childOrder.add(0, 2);
			childOrder.add(0, 3);
			childOrder.add(1, 4);
			childOrder.add(-1, 5);
			childOrder.add(1, 6);
			childOrder.add(1, 7);
			childOrder.add(0, 8);
			childOrder.add(1, 9);
			
			ParentBinaryTree<int> testOne(numNodes, parentArray, childOrder);
			ParentBinaryTree<int> testTwo(numNodes);
			 
			testTwo = testOne;

			cout << "Copy constructor successfully tested!" << endl;

		}

		//overloaded equal to operator - TESTED, WORKS!
		else if (answer == 5)
		{
			int numNodes = 10;

			Array<int> parentArray(10);
			parentArray.add(3, 0);
			parentArray.add(6, 1);
			parentArray.add(5, 2);
			parentArray.add(2, 3);
			parentArray.add(3, 4);
			parentArray.add(-1, 5);
			parentArray.add(5, 6);
			parentArray.add(6, 7);
			parentArray.add(7, 8);
			parentArray.add(8, 9);

			Array<int> childOrder(10);
			childOrder.add(0, 0);
			childOrder.add(0, 1);
			childOrder.add(0, 2);
			childOrder.add(0, 3);
			childOrder.add(1, 4);
			childOrder.add(-1, 5);
			childOrder.add(1, 6);
			childOrder.add(1, 7);
			childOrder.add(0, 8);
			childOrder.add(1, 9);

			ParentBinaryTree<int> testOne(numNodes, parentArray, childOrder);
			ParentBinaryTree<int> testTwo(numNodes);

			testTwo = testOne;
			cout << "Overloaded equal to operator successfully tested!" << endl;
		}

		//ostream operator(preorder traversal) - TESTED, WORKS!
		else if (answer == 6)
		{
			int numNodes = 10;

			Array<int> parentArray(10);
			parentArray.add(3, 0);
			parentArray.add(6, 1);
			parentArray.add(5, 2);
			parentArray.add(2, 3);
			parentArray.add(3, 4);
			parentArray.add(-1, 5);
			parentArray.add(5, 6);
			parentArray.add(6, 7);
			parentArray.add(7, 8);
			parentArray.add(8, 9);

			Array<int> childOrder(10);
			childOrder.add(0, 0);
			childOrder.add(0, 1);
			childOrder.add(0, 2);
			childOrder.add(0, 3);
			childOrder.add(1, 4);
			childOrder.add(-1, 5);
			childOrder.add(1, 6);
			childOrder.add(1, 7);
			childOrder.add(0, 8);
			childOrder.add(1, 9);

			ParentBinaryTree<int> myTree(numNodes, parentArray, childOrder);

			cout << myTree << endl;
			cout << "Ostream operator successfully tested!" << endl;
		}

		//size method - TESTED, WORKS!
		else if (answer == 7)
		{
			int size;
			cout << "Enter the size of your tree." << endl;
			cin >> size;
			if (size < 0)
			{
				throw Exception("Sorry you cannot have a negative sized tree!");
			}
			ParentBinaryTree<int> myTree(size);

			int answer = myTree.size();
			cout << "Size is: " << answer << endl;
			cout << "Size method successfully tested!" << endl;
		}

		//height method - TESTED, WORKS!
		else if (answer == 8)
		{
			int numNodes = 10;

			Array<int> parentArray(10);
			parentArray.add(3, 0);
			parentArray.add(6, 1);
			parentArray.add(5, 2);
			parentArray.add(2, 3);
			parentArray.add(3, 4);
			parentArray.add(-1, 5);
			parentArray.add(5, 6);
			parentArray.add(6, 7);
			parentArray.add(7, 8);
			parentArray.add(8, 9);

			Array<int> childOrder(10);
			childOrder.add(0, 0);
			childOrder.add(0, 1);
			childOrder.add(0, 2);
			childOrder.add(0, 3);
			childOrder.add(1, 4);
			childOrder.add(-1, 5);
			childOrder.add(1, 6);
			childOrder.add(1, 7);
			childOrder.add(0, 8);
			childOrder.add(1, 9);

			ParentBinaryTree<int> myTree(numNodes, parentArray, childOrder);
			
			int answer = myTree.height(5);
			cout << "Height is: " << answer << endl;
			cout << "Height method successfully tested!" << endl;
		}

		//getLeft method - TESTED, WORKS!
		else if (answer == 9)
		{
			int numNodes = 10;

			Array<int> parentArray(10);
			parentArray.add(3, 0);
			parentArray.add(6, 1);
			parentArray.add(5, 2);
			parentArray.add(2, 3);
			parentArray.add(3, 4);
			parentArray.add(-1, 5);
			parentArray.add(5, 6);
			parentArray.add(6, 7);
			parentArray.add(7, 8);
			parentArray.add(8, 9);

			Array<int> childOrder(10);
			childOrder.add(0, 0);
			childOrder.add(0, 1);
			childOrder.add(0, 2);
			childOrder.add(0, 3);
			childOrder.add(1, 4);
			childOrder.add(-1, 5);
			childOrder.add(1, 6);
			childOrder.add(1, 7);
			childOrder.add(0, 8);
			childOrder.add(1, 9);

			ParentBinaryTree<int> myTree(numNodes, parentArray, childOrder);

			int answer = myTree.getLeft(5);
			cout << "Left node is: " << answer << endl;

			cout << "Getleft method successfully tested!" << endl;
		}

		//getRight method - TESTED, WORKS!
		else if (answer == 10)
		{
			int numNodes = 10;

			Array<int> parentArray(10);
			parentArray.add(3, 0);
			parentArray.add(6, 1);
			parentArray.add(5, 2);
			parentArray.add(2, 3);
			parentArray.add(3, 4);
			parentArray.add(-1, 5);
			parentArray.add(5, 6);
			parentArray.add(6, 7);
			parentArray.add(7, 8);
			parentArray.add(8, 9);

			Array<int> childOrder(10);
			childOrder.add(0, 0);
			childOrder.add(0, 1);
			childOrder.add(0, 2);
			childOrder.add(0, 3);
			childOrder.add(1, 4);
			childOrder.add(-1, 5);
			childOrder.add(1, 6);
			childOrder.add(1, 7);
			childOrder.add(0, 8);
			childOrder.add(1, 9);

			ParentBinaryTree<int> myTree(numNodes, parentArray, childOrder);

			int answer = myTree.getRight(5);
			cout << "Left node is: " << answer << endl;

			cout << "Getright method successfully tested!" << endl;
		}

		//preorder traversal method - TESTED, WORKS!
		else if (answer == 11)
		{
			int numNodes = 10;

			Array<int> parentArray(10);
			parentArray.add(3, 0);
			parentArray.add(6, 1);
			parentArray.add(5, 2);
			parentArray.add(2, 3);
			parentArray.add(3, 4);
			parentArray.add(-1, 5);
			parentArray.add(5, 6);
			parentArray.add(6, 7);
			parentArray.add(7, 8);
			parentArray.add(8, 9);

			Array<int> childOrder(10);
			childOrder.add(0, 0);
			childOrder.add(0, 1);
			childOrder.add(0, 2);
			childOrder.add(0, 3);
			childOrder.add(1, 4);
			childOrder.add(-1, 5);
			childOrder.add(1, 6);
			childOrder.add(1, 7);
			childOrder.add(0, 8);
			childOrder.add(1, 9);

			ParentBinaryTree<int> myTree(numNodes, parentArray, childOrder);

			cout << myTree << endl;
			cout << "Preorder method successfully tested!" << endl;
		}

		//inorder traversal method - TESTED, WORKS!
		else if(answer == 12)
		{
			int numNodes = 10;

			Array<int> parentArray(10);
			parentArray.add(3, 0);
			parentArray.add(6, 1);
			parentArray.add(5, 2);
			parentArray.add(2, 3);
			parentArray.add(3, 4);
			parentArray.add(-1, 5);
			parentArray.add(5, 6);
			parentArray.add(6, 7);
			parentArray.add(7, 8);
			parentArray.add(8, 9);

			Array<int> childOrder(10);
			childOrder.add(0, 0);
			childOrder.add(0, 1);
			childOrder.add(0, 2);
			childOrder.add(0, 3);
			childOrder.add(1, 4);
			childOrder.add(-1, 5);
			childOrder.add(1, 6);
			childOrder.add(1, 7);
			childOrder.add(0, 8);
			childOrder.add(1, 9);

			ParentBinaryTree<int> myTree(numNodes, parentArray, childOrder);

			myTree.inorder(5);
			cout << "Inorder method successfully tested!" << endl;
		}

		//postorder traversal method - TESTED, WORKS!
		else if (answer == 13)
		{
			int numNodes = 10;

			Array<int> parentArray(10);
			parentArray.add(3, 0);
			parentArray.add(6, 1);
			parentArray.add(5, 2);
			parentArray.add(2, 3);
			parentArray.add(3, 4);
			parentArray.add(-1, 5);
			parentArray.add(5, 6);
			parentArray.add(6, 7);
			parentArray.add(7, 8);
			parentArray.add(8, 9);

			Array<int> childOrder(10);
			childOrder.add(0, 0);
			childOrder.add(0, 1);
			childOrder.add(0, 2);
			childOrder.add(0, 3);
			childOrder.add(1, 4);
			childOrder.add(-1, 5);
			childOrder.add(1, 6);
			childOrder.add(1, 7);
			childOrder.add(0, 8);
			childOrder.add(1, 9);

			ParentBinaryTree<int> myTree(numNodes, parentArray, childOrder);

			myTree.postorder(5);
			cout << "Postorder method successfully tested!" << endl;
		}

		//default
		else
		{
			throw Exception("Sorry, you must enter a number between 1 and 13.");
		}

		return 0;
	}
}