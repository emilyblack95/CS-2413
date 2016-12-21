/**
Source - C++ file
Purpose: This file runs the main function.

@author Emily Black
@version 1.0
@date 2/2/16
*/

#pragma once
#include <iostream> 
#include "browserTab.h"
#include "webAddressInfo.h"
#include "StringHelpers.h"
using namespace std;

//The main function basically runs the whole program.
void main()
{
	char action; //N F B P - command
	int i;  //counter for adding URL
	char aChar;
	char myURL[MAX_SIZE_OF_URL]; //obj of webAddressInfo class. Contains 1 url.
	browserTab myTabs[20]; //Creates 20 tabs - each tab has space for 20 URLS 
	int tabNumber;  //tab number  
	char blank; //space
	while (!cin.eof())  // while end of line is not reached 
	{
		while (!cin.eof())
		{
			cin >> tabNumber;  //1-20	 	
			cin.get(blank);		//space 	
			cin.get(action);  	 //get action char(N F B or P)	
			switch (action)
			{
			case 'N': //New url - if char action = N
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
				} while ((aChar != '\n') && (i < 201) && (!cin.eof()));  //suppose to implement strCopy somehow
				myURL[i] = '\0';  //puts string terminator at end of input
				myTabs[tabNumber].addAddress(myURL);  //creates new URL 
				if (i > 0)
				{
					cout << myURL << " added URL!" << endl;
				}
				break;
			}

			case 'F': //Forward - if char action = F
			{
				cout << "Action Invoked: Forward" << endl;
				cout << "Tab Number: " << tabNumber << endl;
				myTabs[tabNumber].forward(); //forward method from browserTab
				break;
			}

			case 'B': //Backward - if char action = B
			{
				cout << "Action Invoked: Backward" << endl;
				cout << "Tab Number: " << tabNumber << endl;
				myTabs[tabNumber].backward(); //backward method from browserTab
				break;
			}

			case 'P': //Print current URLS in tab - if char action = P
			{
				cout << "Action Invoked: Print" << endl;
				cout << "Tab Number: " << tabNumber << endl;
				myTabs[tabNumber].display();  //display method from browserTab
				break;
			}

			default: //illegal action
			{
				cout << "I'm sorry, but that is a illegal action. Try again." << endl;
			}
			}
		}
	}
}
