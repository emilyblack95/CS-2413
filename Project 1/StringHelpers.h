/**
browserTab class
Purpose: This class holds random string functions.

@author Emily Black
@version 1.0
@date 2/2/16
*/
#pragma once


//Finds length of a char array. FOR LATER USE.
int strLength(char * x)
{
	int i = 0;
	while (x[i] != '\0')
	{
		i++;
	}

	return i;
}

//strCopy: Copies from 1 char array to the other. from(variable) copies its contents and puts it in to(variable). FOR LATER USE.
void strCopy(char * from, char * to)
{
	int size = strLength(from);
	for (int i = 0; i <= size; i++)
	{
		to[i] = from[i];
	}
}
