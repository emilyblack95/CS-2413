/**
Exceptions.h
Purpose: This class holds exception objects.

@author Emily Black
@version 5.0
@date 4/7/16
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
}

