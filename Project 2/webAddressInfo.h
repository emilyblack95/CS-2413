/**
webAddressInfo class functions
Purpose: This part of the class holds what each function does in the class.

@author Emily Black
@version 2.0
@date 2/18/16
*/

#pragma once
#include <iostream>
#include "StringHelpers.h"
#include "CustomExceptions.h"
#define MAX_SIZE_OF_URL 200  //constant - max number of URLS
using namespace std;

class webAddressInfo
{
	friend ostream & operator<< (ostream& s, const webAddressInfo & x);  //overloaded ostream operator

private:
	char url[MAX_SIZE_OF_URL + 1]; //allow a maximum of 200 characters  

public:
	webAddressInfo(); //Default Constructor
	webAddressInfo(char * inputString);  //Initializer Constructor 
	webAddressInfo(const webAddressInfo& other); //Copy Constructor
	webAddressInfo& operator=(const webAddressInfo& x); //Overloaded equals operator
	bool operator==(const webAddressInfo& x); //Overloaded comparison operator
	void setWebAddressInfo(char * inputString);  //sets URL
	void display();
	~webAddressInfo(); //Destructor
};

//Default Constructor
webAddressInfo::webAddressInfo()
{
	for (int i = 0; i <= MAX_SIZE_OF_URL; i++)
	{
		url[i] = '\0';  //empties URL array
	}
}

//Initializer Constructor
webAddressInfo::webAddressInfo(char * inputString)
{
	setWebAddressInfo(inputString);
}

//Copy constructor
webAddressInfo::webAddressInfo(const webAddressInfo& other)
//:url=other.url  //THIRD WAY OF COPYING STUFF - INITIALIZER LIST
{
	operator= (other);  //FIRST WAY OF COPYING STUFF
						//strCopy(other.url, url);  //SECOND WAY OF COPYING STUFF - DEEP COPY
}

//Overloaded equals operator
webAddressInfo& webAddressInfo::operator= (const webAddressInfo& x) //const means you can't change x
{
	strCopy(x.url, url);
	return (*this);
}

//Overloaded comparison operator
bool webAddressInfo::operator==(const webAddressInfo& x)
{
	bool areTheyEqual;
	int lengthOfUrl = strLength(url);
	int lengthOfSecondURL = strLength(x.url);
	if (lengthOfUrl != lengthOfSecondURL)  //if they arent the same length - base case
	{
		areTheyEqual = false;
		return areTheyEqual;
	}
	else  //if they are the same length
	{
		for (int i = 0; i <= lengthOfUrl; i++)
		{
			if (url[i] != x.url[i]) //if they dont have same character
			{
				areTheyEqual = false;
				return areTheyEqual;
			}
		}
		areTheyEqual = true;   //if they never hit inside the if statement, return true
		return areTheyEqual;
	}
}

//Mutator Method
void webAddressInfo::setWebAddressInfo(char * inputString)
{
	int lengthOfInput = strLength(inputString);

	if (lengthOfInput < MAX_SIZE_OF_URL)  //if it doesnt reach max character length
	{
		strCopy(inputString, url);
		cout << "URL has been successfully created." << endl;
	}
	else
	{
		throw Exception("The input URL exceeded the maximum character limit of 200.");
	}
}

//Overloaded ostream operator
ostream& operator<< (ostream & s, const webAddressInfo & x)
{
	int lengthOfURL = strLength(x.url);
	if (lengthOfURL == 0)  //if there is no URL
	{
		s << "Nothing to print!" << endl;
	}
	else
	{
		for (int k = 0; k <= lengthOfURL; k++)
		{
			s << x.url[k];
		}
		s << '\n';
	}
	return s;
}


//Cout method that prints URL
void webAddressInfo::display()
{
	//operator<< (cout,(*this));  //does the same thing
	cout << *this;
}

//Destructor
webAddressInfo::~webAddressInfo()
{
	//cout << "~~~WEBADDRESSINFO OBJECT HAS BEEN DESTROYED~~~" << endl; commented this out due to spam. this is to see that my output works!
	//cout << '\a';  //you hear a sound everytime a webaddressinfo object is deleted
}