/**
Exceptions.h
Purpose: This class holds exception objects.

@author Emily Black
@version 4.0
@date 3/24/16
*/

#pragma once
#include <iostream>
using namespace std;

class Exception
{
private:
	char * message;
public:
	Exception();  //default constructor
	Exception(char * customMessage); //initializer
	char* getMessage();  //accessor
	void printMessage(); //prints error message
	~Exception(); //deconstructor
};

//Default Constructor
Exception::Exception()
{
	message = "An unknown exception was thrown.";
}

//Initializer
Exception::Exception(char * customMessage)
{
	message = customMessage;
}

//accessor
char* Exception::getMessage()
{
	return message;
}

//prints error message
void Exception::printMessage()
{
	cout << message << endl; //prints error message
}

//Destructor
Exception::~Exception()
{
	//cout << "~~~EXCEPTION OBJECT HAS BEEN DESTROYED~~~" << endl; commented this out due to spam. this is to see that my output works!
	//cout << '\a';  //you hear a sound everytime a exceptions object is deleted
}

