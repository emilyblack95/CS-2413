/**
browserTab class
Purpose: This class creates tabs and holds URLs.

@author Emily Black
@version 2.0
@date 2/18/16
*/

#pragma once
#include <iostream>
#include "webAddressInfo.h"
#include "CustomExceptions.h"
#define MAX_NUMBER_OF_URLS 20  //constant - max number of URLS in ONE tab
using namespace std;

class browserTab
{
	friend ostream& operator<< (ostream & s, const browserTab & x);  //overloaded ostream operator

protected:
	int numAddress; //Current number of web addresses in this tab  	
	webAddressInfo webAddresses[MAX_NUMBER_OF_URLS]; //Web addresses in this tab  //BASICALLY 1 TAB CAN HAVE 20 URLS	
	int currentAddress; //index of current location in webAddresses  

public:
	browserTab(); //Default Constructor
	browserTab(char * inputString); //Initializer Constructor  
	browserTab(const browserTab& other); //Copy Constructor
	browserTab& operator= (const browserTab& x); //Overloaded equals operator
	bool operator== (const browserTab& x); //Overloaded comparison operator
	bool operator!= (const browserTab& x); //Overloaded opposite comparison operator
	webAddressInfo& forward();
	webAddressInfo& backward();
	void browserTabSwap(browserTab & to);  //swaps 2 browsertab objects
	void removeTab();  //removes current tab
	void changeAddress(char * inputString);
	void addAddress(char * inputString);
	void display()const;
	~browserTab(); //Destructor
};



//Default Constructor
browserTab::browserTab()
{
	numAddress = 0;  //starts fresh
	currentAddress = 0;  //starts fresh
}

//Initializer Constructor
browserTab::browserTab(char * inputString)  //NEW TAB
{
	numAddress = 1;  //starts with 1 since we create new tab object with address
	currentAddress = 0;  //starts fresh
	webAddresses[currentAddress].setWebAddressInfo(inputString);
}

//Copy Constructor
browserTab::browserTab(const browserTab& other)
{
	operator= (other);
}

//Overloaded equals operator
browserTab& browserTab::operator=(const browserTab& x)
{
	numAddress = x.numAddress;
	currentAddress = x.currentAddress;
	for (int i = 0; i < numAddress; i++)
	{
		webAddresses[i] = x.webAddresses[i];
	}
	return (*this);
}

//Overloaded comparison operator
bool browserTab::operator==(const browserTab& x)
{
	return ((numAddress == x.numAddress) && (currentAddress = x.currentAddress) && (webAddresses == x.webAddresses));  //if one if these cases is false, it will return false
}

//Overloaded opposite comparison operator
bool browserTab::operator!= (const browserTab& x)
{
	return !(*this == x);  //compares this to x. if its false, return true. if its true, return false.
}

//Goes forward
webAddressInfo& browserTab::forward()
{
	if (currentAddress + 1 == numAddress)  //if current location cannot go forward anymore (range is 0 to 19)
	{
		throw Exception("You cannot go forward anymore.");
	}
	else if (numAddress == 0)  //if no URLs in tab
	{
		throw Exception("There are no URLS to go forward!");
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
		throw Exception("You cannot go backward anymore.");
	}
	else if (numAddress == 0)  //if no URLs in tab
	{
		throw Exception("There are no URLS to go backward!");
	}
	else	//if you can go backward & if you have URLs
	{
		cout << "Went backward to: "; //doesnt start new line
		currentAddress--;
		webAddresses[currentAddress].display();  //calls display method from webaddressinfo class. prints url.
		return webAddresses[currentAddress];
	}
}

//swaps 2 browserTabs
void browserTab::browserTabSwap(browserTab & to)
{
	//finish this. make it like bubblesort.
	browserTab temp;

	temp = to;
	to = *this;
	*this = temp;
}

//removes current tab
void browserTab::removeTab()
{
	numAddress = 0;
	currentAddress = 0;
}

//Changes address without having to worry about indexes
void browserTab::changeAddress(char * inputString)
{
	if (numAddress == 0) //if there are no URLs to change
	{
		throw Exception("There are no URLS to change!");
	}
	else //else change it
	{
		webAddresses[currentAddress].setWebAddressInfo(inputString);
		cout << "URL successfully changed.";
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
	else if (numAddress < (MAX_NUMBER_OF_URLS - 1))  //if we don't have 20 URLS in a tab
	{
		currentAddress++;
		webAddresses[currentAddress].setWebAddressInfo(inputString);
		numAddress = currentAddress + 1;
	}
	else if (numAddress == (MAX_NUMBER_OF_URLS - 1)) //if we have MAX amount of URLS in this tab
	{
		throw Exception("This tab is currently full of web addresses. Try a different tab.");
	}
}

//Overloaded ostream operator
ostream& operator<< (ostream & s, const browserTab & x)
{
	int c = 0;

	if (x.numAddress == 0)  //if there are no URLS to display
	{
		s << "No URLS to display." << endl;
	}
	else
	{
		s << "Number of URLS in this tab: " << x.numAddress << endl;
		for (int c = 0; c < x.numAddress; c++)  //prints out all URLS
		{
			s << "URL index: " << c << endl;
			s << "URL: ";
			s << x.webAddresses[c];
		}
	}
	return s;
}

//Cout method that prints all URLS in tab
void browserTab::display()const
{
	cout << *this;
}

//Destructor
browserTab::~browserTab()
{
	//cout << "~~~BROWSERTAB OBJECT HAS BEEN DESTROYED~~~" << endl; commented this out due to spam. this is to see that my output works!
	//cout << '\a';  //you hear a sound everytime a browsertab object is deleted
}
