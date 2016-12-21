/**
StringHelper class
Purpose: This class holds random functions for strings.

@author Emily Black
@version 3.0
@date 3/5/16
*/

#pragma once
#include <iostream>

//empties URL
void emptyString(char * somestr, int length)
{
	for (int i = 0; i < length; i++)
	{
		somestr[i] = '\0'; //string terminator
	}
}
