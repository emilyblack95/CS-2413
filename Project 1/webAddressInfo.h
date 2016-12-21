/**
webAddressInfo class functions
Purpose: This part of the class holds what each function does in the class.

@author Emily Black
@version 1.0
@date 2/2/16
*/

#pragma once
#include <iostream>
#include "StringHelpers.h"
#define MAX_SIZE_OF_URL 200  //constant
using namespace std;

class webAddressInfo
{
private:
	char url[MAX_SIZE_OF_URL + 1]; //allow a maximum of 200 characters  

public:
	webAddressInfo();
	webAddressInfo(char * inputString);
	void setWebAddressInfo(char * inputString);
	char * getWebAddressInfo();
	void display();
};

//Default Constructor
webAddressInfo::webAddressInfo()
{
	for (int i = 0; i <= MAX_SIZE_OF_URL; i++)
	{
		url[i] = '\0';  //empties URL array
	}
}

//Constructor that creates URL
webAddressInfo::webAddressInfo(char * inputString)
{
	setWebAddressInfo(inputString);
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
		cout << "Sorry, but the input URL exceeds the maximum character limit of 200" << endl;
	}
}

//Accessor Method
char * webAddressInfo::getWebAddressInfo()
{
	return url;
}

//Cout method that prints URL
void webAddressInfo::display()
{
	int lengthOfURL = strLength(url);
	if (lengthOfURL == 0)  //if there is no URL
	{
		cout << "Nothing to print!" << endl;
	}
	else
	{
		for (int k = 0; k <= lengthOfURL; k++)
		{
			cout << url[k];
		}
		cout << '\n';
	}
}
