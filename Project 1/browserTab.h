/**
browserTab class
Purpose: This class creates tabs and holds URLs.

@author Emily Black
@version 1.0
@date 2/2/16
*/

#pragma once
#include <iostream>
#include "webAddressInfo.h"
using namespace std;

class browserTab
{
protected:
	int numAddress; //Current number of web addresses in this tab  	
	webAddressInfo webAddresses[20]; //Web addresses in this tab  //BASICALLY 1 TAB CAN HAVE 20 URLS	
	int currentAddress; //index of current location in webAddresses  

public:
	browserTab();
	browserTab(char * inputString); //creates a new tab with the inputString  	
	webAddressInfo& forward();
	webAddressInfo& backward();
	void addAddress(char * inputString);
	void display();
};



//Default Constructor
browserTab::browserTab()
{
	numAddress = 0;  //starts fresh
	currentAddress = 0;  //starts fresh
}

//Constructor
browserTab::browserTab(char * inputString)  //NEW TAB
{
	numAddress = 1;  //starts with 1 since we create new tab object with address
	currentAddress = 0;  //starts fresh
	webAddresses[currentAddress].setWebAddressInfo(inputString);
}

//Goes forward
webAddressInfo& browserTab::forward()
{
	if (currentAddress + 1 == numAddress)  //if current location cannot go forward anymore (range is 0 to 19)
	{
		cout << "Sorry you cannot go forward anymore." << endl;
	}
	else if (numAddress == 0)  //if no URLs in tab
	{
		cout << "Sorry you have no URLs to go forward." << endl;
	}
	else	//if you can go forward & if you have URLs
	{
		cout << "Went forward to: ";  //doesnt start new line
		currentAddress++;
		webAddresses[currentAddress].display();  //calls display method from webaddressinfo class. prints url.
		return webAddresses[currentAddress];
	}
}

//Goes backward
webAddressInfo& browserTab::backward()
{
	if (currentAddress == 0) //if current location cannot go backward anymore
	{
		cout << "Sorry you cannot go backward anymore." << endl;
	}
	else if (numAddress == 0)  //if no URLs in tab
	{
		cout << "Sorry you have no URLs to go backward." << endl;
	}
	else	//if you can go backward & if you have URLs
	{
		cout << "Went backward to: "; //doesnt start new line
		currentAddress--;
		webAddresses[currentAddress].display();  //calls display method from webaddressinfo class. prints url.
		return webAddresses[currentAddress];
	}
}


//Adds URL 1 after the original one, and then moves to it
void browserTab::addAddress(char * inputString)
{
	if (numAddress == 0) //if there are no URLS
	{
		webAddresses[currentAddress].setWebAddressInfo(inputString);
		numAddress = currentAddress + 1;
	}
	else if (numAddress < 19)  //if we don't have 20 URLS in a tab
	{
		currentAddress++;
		webAddresses[currentAddress].setWebAddressInfo(inputString);
		numAddress = currentAddress + 1;
	}
	else if (numAddress == 19) //if we have MAX amount of URLS in this tab
	{
		cout << "Sorry this tab is currently full of web addresses." << endl;
	}

}

//Cout method that prints all URLS in tab
void browserTab::display()
{
	int c = 0;

	if (numAddress == 0)  //if there are no URLS to display
	{
		cout << "No URLS to display." << endl;
	}
	else
	{
		cout << "Number of URLS in this tab: " << numAddress << endl;
		for (int c = 0; c < numAddress; c++)  //prints out all URLS
		{
			cout << "URL index: " << c << endl;
			cout << "URL: ";
			webAddresses[c].display();
		}
	}
}
