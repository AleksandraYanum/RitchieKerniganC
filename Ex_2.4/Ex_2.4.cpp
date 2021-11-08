#include <stdio.h>
#include <stdlib.h>

//Program deletes each character in s1 that matches any character in the string s2

#define MAXSIZE 100

// ###########################################################################
// functions
// ###########################################################################

void squeeze(char s1[], char s2[]);

// ###########################################################################

int main()
{
	char main_string[MAXSIZE];
	char string_to_delete[MAXSIZE];

	squeeze(main_string, string_to_delete);

	return EXIT_SUCCESS;
}


void squeeze(char s1[], char s2[])
{
	return;
}