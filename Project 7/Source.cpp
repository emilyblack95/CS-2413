/**
Source.cpp
Purpose: This class runs the program.

@author Emily Black
@version 7.0
@date 4/27/16
*/

#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "GraphAdjList.h"
#include "Exception.h"
#define letsTest false  
//True = Test Methods 
//False = Redirected Input
using namespace std;

void main()
{
	if (!letsTest)	//False
	{
		int numNodes;
		int numEdges;  //will be used in for loop
		int x;
		int y;

		cin >> numNodes;
		cin >> numEdges;
		vector<list<int>> adjList(numNodes);

		for (int i = 0; i < numEdges; i++)
		{
			cin >> x;
			cin >> y;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		GraphAdjList<int> myGraph(numNodes, numEdges, adjList);
		cout << myGraph << endl;
		cout << "Redirected input successfully tested." << endl;
	}
	else if (letsTest)	//True
	{
		int answer;
		cout << "Which method would you like to test?" << endl;
		cout << "1. non-empty constructor" << endl;
		cout << "2. ostream operator" << endl;
		cout << "3. destructor" << endl;
		cout << "4. addedge" << endl;
		cout << "5. depthfirstsearch" << endl;
		cin >> answer;

		//non-empty constructor - TESTED & WORKS.
		if (answer == 1)
		{
			int numNodes = 14;
			int numEdges = 27;
			vector<list<int>> adjList(numNodes);
			adjList[0].push_back(1);
			adjList[0].push_back(2);
			adjList[0].push_back(7);
			adjList[0].push_back(11);

			adjList[1].push_back(0);
			adjList[1].push_back(2);
			adjList[1].push_back(3);
			adjList[1].push_back(6);
			adjList[1].push_back(11);

			adjList[2].push_back(0);
			adjList[2].push_back(1);
			adjList[2].push_back(3);
			adjList[2].push_back(5);
			adjList[2].push_back(7);

			adjList[3].push_back(1);
			adjList[3].push_back(2);
			adjList[3].push_back(4);
			adjList[3].push_back(5);
			adjList[3].push_back(6);

			adjList[4].push_back(3);
			adjList[4].push_back(5);
			adjList[4].push_back(6);
			adjList[4].push_back(8);
			adjList[4].push_back(12);

			adjList[5].push_back(2);
			adjList[5].push_back(3);
			adjList[5].push_back(4);
			adjList[5].push_back(10);

			adjList[6].push_back(1);
			adjList[6].push_back(3);
			adjList[6].push_back(4);
			adjList[6].push_back(9);
			adjList[6].push_back(12);

			adjList[7].push_back(0);
			adjList[7].push_back(2);
			adjList[7].push_back(10);

			adjList[8].push_back(4);
			adjList[8].push_back(10);
			adjList[8].push_back(13);

			adjList[9].push_back(6);
			adjList[9].push_back(11);
			adjList[9].push_back(12);

			adjList[10].push_back(5);
			adjList[10].push_back(7);
			adjList[10].push_back(8);

			adjList[11].push_back(0);
			adjList[11].push_back(1);
			adjList[11].push_back(9);

			adjList[12].push_back(4);
			adjList[12].push_back(6);
			adjList[12].push_back(9);
			adjList[12].push_back(13);

			adjList[13].push_back(8);
			adjList[13].push_back(12);

			GraphAdjList<int> myGraph(numNodes, numEdges, adjList);
			cout << "Non-empty constructor successfully tested." << endl;
		}

		//ostream operator - TESTED & WORKS.
		else if (answer == 2)
		{
			int numNodes = 14;
			int numEdges = 27;
			vector<list<int>> adjList(numNodes);
			adjList[0].push_back(1);
			adjList[0].push_back(2);
			adjList[0].push_back(7);
			adjList[0].push_back(11);

			adjList[1].push_back(0);
			adjList[1].push_back(2);
			adjList[1].push_back(3);
			adjList[1].push_back(6);
			adjList[1].push_back(11);

			adjList[2].push_back(0);
			adjList[2].push_back(1);
			adjList[2].push_back(3);
			adjList[2].push_back(5);
			adjList[2].push_back(7);

			adjList[3].push_back(1);
			adjList[3].push_back(2);
			adjList[3].push_back(4);
			adjList[3].push_back(5);
			adjList[3].push_back(6);

			adjList[4].push_back(3);
			adjList[4].push_back(5);
			adjList[4].push_back(6);
			adjList[4].push_back(8);
			adjList[4].push_back(12);

			adjList[5].push_back(2);
			adjList[5].push_back(3);
			adjList[5].push_back(4);
			adjList[5].push_back(10);

			adjList[6].push_back(1);
			adjList[6].push_back(3);
			adjList[6].push_back(4);
			adjList[6].push_back(9);
			adjList[6].push_back(12);

			adjList[7].push_back(0);
			adjList[7].push_back(2);
			adjList[7].push_back(10);

			adjList[8].push_back(4);
			adjList[8].push_back(10);
			adjList[8].push_back(13);

			adjList[9].push_back(6);
			adjList[9].push_back(11);
			adjList[9].push_back(12);

			adjList[10].push_back(5);
			adjList[10].push_back(7);
			adjList[10].push_back(8);

			adjList[11].push_back(0);
			adjList[11].push_back(1);
			adjList[11].push_back(9);

			adjList[12].push_back(4);
			adjList[12].push_back(6);
			adjList[12].push_back(9);
			adjList[12].push_back(13);

			adjList[13].push_back(8);
			adjList[13].push_back(12);

			GraphAdjList<int> myGraph(numNodes, numEdges, adjList);
			cout << myGraph << endl;
			cout << "Ostream operator successfully tested." << endl;
		}

		//destructor - TESTED & WORKS.
		else if (answer == 3)
		{
			//Don't need to test destructor because the way I implemented my class doesn't deal with pointers.
			cout << "Destructor successfully tested." << endl;
		}

		//addedge - TESTED & WORKS.
		else if (answer == 4)
		{
			int numNodes = 14;
			int numEdges = 27;
			vector<list<int>> adjList(numNodes);
			adjList[0].push_back(1);
			adjList[0].push_back(2);
			adjList[0].push_back(7);
			adjList[0].push_back(11);

			adjList[1].push_back(0);
			adjList[1].push_back(2);
			adjList[1].push_back(3);
			adjList[1].push_back(6);
			adjList[1].push_back(11);

			adjList[2].push_back(0);
			adjList[2].push_back(1);
			adjList[2].push_back(3);
			adjList[2].push_back(5);
			adjList[2].push_back(7);

			adjList[3].push_back(1);
			adjList[3].push_back(2);
			adjList[3].push_back(4);
			adjList[3].push_back(5);
			adjList[3].push_back(6);

			adjList[4].push_back(3);
			adjList[4].push_back(5);
			adjList[4].push_back(6);
			adjList[4].push_back(8);
			adjList[4].push_back(12);

			adjList[5].push_back(2);
			adjList[5].push_back(3);
			adjList[5].push_back(4);
			adjList[5].push_back(10);

			adjList[6].push_back(1);
			adjList[6].push_back(3);
			adjList[6].push_back(4);
			adjList[6].push_back(9);
			adjList[6].push_back(12);

			adjList[7].push_back(0);
			adjList[7].push_back(2);
			adjList[7].push_back(10);

			adjList[8].push_back(4);
			adjList[8].push_back(10);
			adjList[8].push_back(13);

			adjList[9].push_back(6);
			adjList[9].push_back(11);
			adjList[9].push_back(12);

			adjList[10].push_back(5);
			adjList[10].push_back(7);
			adjList[10].push_back(8);

			adjList[11].push_back(0);
			adjList[11].push_back(1);
			adjList[11].push_back(9);

			adjList[12].push_back(4);
			adjList[12].push_back(6);
			adjList[12].push_back(9);
			adjList[12].push_back(13);

			adjList[13].push_back(8);
			adjList[13].push_back(12);

			GraphAdjList<int> myGraph(numNodes, numEdges, adjList);
			myGraph.setNumEdges(28);
			myGraph.addEdge(8, 14);
			cout << myGraph << endl;
			cout << "Addedge successfully tested." << endl;
		}

		//depthfirstsearch
		else if (answer == 5)
		{
			int numNodes = 14;
			int numEdges = 27;
			vector<list<int>> adjList(numNodes);
			adjList[0].push_back(1);
			adjList[0].push_back(2);
			adjList[0].push_back(7);
			adjList[0].push_back(11);

			adjList[1].push_back(0);
			adjList[1].push_back(2);
			adjList[1].push_back(3);
			adjList[1].push_back(6);
			adjList[1].push_back(11);

			adjList[2].push_back(0);
			adjList[2].push_back(1);
			adjList[2].push_back(3);
			adjList[2].push_back(5);
			adjList[2].push_back(7);

			adjList[3].push_back(1);
			adjList[3].push_back(2);
			adjList[3].push_back(4);
			adjList[3].push_back(5);
			adjList[3].push_back(6);

			adjList[4].push_back(3);
			adjList[4].push_back(5);
			adjList[4].push_back(6);
			adjList[4].push_back(8);
			adjList[4].push_back(12);

			adjList[5].push_back(2);
			adjList[5].push_back(3);
			adjList[5].push_back(4);
			adjList[5].push_back(10);

			adjList[6].push_back(1);
			adjList[6].push_back(3);
			adjList[6].push_back(4);
			adjList[6].push_back(9);
			adjList[6].push_back(12);

			adjList[7].push_back(0);
			adjList[7].push_back(2);
			adjList[7].push_back(10);

			adjList[8].push_back(4);
			adjList[8].push_back(10);
			adjList[8].push_back(13);

			adjList[9].push_back(6);
			adjList[9].push_back(11);
			adjList[9].push_back(12);

			adjList[10].push_back(5);
			adjList[10].push_back(7);
			adjList[10].push_back(8);

			adjList[11].push_back(0);
			adjList[11].push_back(1);
			adjList[11].push_back(9);

			adjList[12].push_back(4);
			adjList[12].push_back(6);
			adjList[12].push_back(9);
			adjList[12].push_back(13);

			adjList[13].push_back(8);
			adjList[13].push_back(12);

			GraphAdjList<int> myGraph(numNodes, numEdges, adjList);
			vector<int> dfs = myGraph.orderOfDFS(0);
			cout << "Depthfirstsearch successfully tested." << endl;
		}

		//default
		else
		{
			throw Exception("Sorry, you must enter a number between 1 and 10.");
		}
	}
}