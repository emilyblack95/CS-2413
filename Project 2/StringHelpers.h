/**
StringHelper class
Purpose: This class holds random functions for strings.

@author Emily Black
@version 2.0
@date 2/18/16
*/

#pragma once
#include "browserTab.h"
#include <iostream>

//Finds length of a char array. FOR LATER USE.
int strLength(const char * const x)
{
	int i = 0;
	while (x[i] != '\0')
	{
		i++;
	}

	return i;
}

//strCopy: Copies from 1 char array to the other. from(variable) copies its contents and puts it in to(variable). FOR LATER USE.
void strCopy(const char * const from, char * to)  //PUT CONST AFTER POINTER
{
	int lengthOfStr = strLength(to);

	int size = strLength(from);

	for (int i = 0; i <= size; i++)
	{
		to[i] = from[i];
	}
}

//empties URL
void emptyString(char * somestr, int length)
{
	for (int i = 0; i < length; i++)
	{
		somestr[i] = '\0'; //string terminator
	}
}
