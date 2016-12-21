/**
Source - C++ file
Purpose: This file runs the main function.

@author Emily Black
@version 2.0
@date 2/18/16
*/

#pragma once
#include <iostream>
#define DEBUG_PRINT true
#define MAX_NUMBER_OF_TABS 20
#include "browserTab.h"
#include "webAddressInfo.h"
#include "StringHelpers.h"
#include "CustomExceptions.h"
using namespace std;




//The main function basically runs the whole program.
int main()
{
	char action; //N F B P - command
	int i;  //counter for adding URL
	char aChar;
	char myURL[MAX_SIZE_OF_URL]; //obj of webAddressInfo class. Contains 1 url.
	char changeURL[MAX_SIZE_OF_URL]; //obj of webAddressInfo class. Contains 1 url.
	browserTab myTabs[MAX_NUMBER_OF_TABS]; //Creates 20 tabs - each tab has space for 20 URLS 
	int tabNumber;  //tab number  
	int secondTabNumber;  //second tab number for move action
	char blank; //space
	while (!cin.eof())  // while end of line is not reached 
	{
		while (!cin.eof())  // while end of line is not reached 
		{
			try {
				cin >> tabNumber;  //1-20
				tabNumber = tabNumber - 1;  //indexing purposes
				if (tabNumber >= MAX_NUMBER_OF_TABS || tabNumber < 0)
				{
					throw Exception("There are only 20 tabs. Please try again.");
				}
				cin.get(blank);		//space 	
				cin.get(action);  	 //get action char(N F B or P)	
				switch (action)
				{
				case 'N': //NEW URL - if char action = N
				{
					cin.get(blank);
					i = 0;

					cout << "Action Invoked: New URL" << endl;
					cout << "Tab Number: " << tabNumber << endl;


					//REDIRECTED INPUT
					do {  //This do while loop takes each character in from the keyboard, and adds it to inputString
						cin.get(aChar);
						if (aChar != '\n')
						{
							myURL[i++] = aChar;  //after exiting if loop, i has size of URL entered

						}
					} while ((aChar != '\n') && (i < MAX_SIZE_OF_URL + 1) && (!cin.eof()));


					if (i >= MAX_SIZE_OF_URL + 1)
					{
						do {  //This do while loop takes each character in from the keyboard, and adds it to inputString
							cin.get(aChar);
						} while ((aChar != '\n') && (!cin.eof()));
						throw Exception("Too big of URL");
					}

					myURL[i] = '\0';  //puts string terminator at end of input
					myTabs[tabNumber].addAddress(myURL);  //creates new URL 
					if (i > 0)
					{
						cout << myURL << " added URL!" << endl;
					}
					break;
				}

				case 'F': //FORWARD - if char action = F
				{
					cout << "Action Invoked: Forward" << endl;
					cout << "Tab Number: " << tabNumber << endl;
					myTabs[tabNumber].forward(); //forward method from browserTab
					break;
				}

				case 'B': //BACKWARD - if char action = B
				{
					cout << "Action Invoked: Backward" << endl;
					cout << "Tab Number: " << tabNumber << endl;
					myTabs[tabNumber].backward(); //backward method from browserTab
					break;
				}

				case 'P': //PRINTS current URLS in tab - if char action = P
				{
					cout << "Action Invoked: Print" << endl;
					cout << "Tab Number: " << tabNumber << endl;
					myTabs[tabNumber].display();  //display method from browserTab
					break;
				}

				case 'M': //MOVES first tab number given before the second tab number given
				{
					cin >> secondTabNumber;

					secondTabNumber = secondTabNumber - 1;  //indexing purposes
					if (secondTabNumber >= MAX_NUMBER_OF_TABS || secondTabNumber < 0)
					{
						throw Exception("There are only 20 tabs. Please try again.");
					}

					while (tabNumber != secondTabNumber)  //while we have not moved x before y
					{
						if (tabNumber > secondTabNumber)
						{
							myTabs[tabNumber].browserTabSwap(myTabs[tabNumber - 1]);  //CALLING METHOD IN BROWSERTAB CLASS
							tabNumber--;
						}
						else if (tabNumber < secondTabNumber)
						{
							myTabs[tabNumber].browserTabSwap(myTabs[tabNumber + 1]);  //CALLING METHOD IN BROWSERTAB CLASS
							tabNumber++;
						}
					}
					break;
				}

				case 'R': //REMOVES tab number, moves every tab after it down 1 (indexing)
				{
					myTabs[tabNumber].removeTab(); //CALLS REMOVETAB METHOD FROM BROWSERTAB CLASS
					for (tabNumber; tabNumber < MAX_NUMBER_OF_TABS - 1; tabNumber++)
					{
						myTabs[tabNumber] = myTabs[tabNumber++];  //moves each one above tabnumber down one
					}
					myTabs[MAX_NUMBER_OF_TABS - 1] = browserTab();
					break;
				}

				case 'C': //CHANGES url for current tab number given. basically just like new url.
				{
					cin.get(blank);
					i = 0;

					cout << "Action Invoked: Change URL" << endl;
					cout << "Tab Number: " << tabNumber << endl;

					//REDIRECTED INPUT
					do {  //This do while loop takes each character in from the keyboard, and adds it to inputString
						cin.get(aChar);
						if (aChar != '\n')
						{
							changeURL[i++] = aChar;  //after exiting if loop, i has size of URL entered

						}
					} while ((aChar != '\n') && (i < MAX_SIZE_OF_URL + 1) && (!cin.eof()));
					changeURL[i] = '\0';  //puts string terminator at end of input
					myTabs[tabNumber].changeAddress(changeURL);  //creates new URL 
					break;
				}

				default: //illegal command
				{
					//REDIRECTED INPUT
					do {  //This do while loop takes each character in from the keyboard, and adds it to inputString
						cin.get(aChar);
					} while ((aChar != '\n') && (!cin.eof()));
					throw Exception("Illegal action. Please try again.");  //after this, breaks out of default 
				}
				}
			}
			catch (Exception e)
			{
				e.printMessage();
			}
		}
	}
	return 0;
}