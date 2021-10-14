#include <stdio.h>
#include <stdlib.h>

/* program checks a C program for syntax errors like unbalanced brackets */

# define MAXSIZE 10 //max size of the array with opening brackets

// ###########################################################################
// functions
// ###########################################################################

void bracket_handler(char bracket_type);

// ###########################################################################
// global variables
// ###########################################################################

int pos = 0; //position of array elements
char bracket[MAXSIZE];
int is_error = 0; // 1 - error, 0 - not error

int main()
{
	char c; //input

	for (int i = 0; i < MAXSIZE; i++)
	{
		bracket[i] = 0;
	}

	while (((c = getchar()) != EOF) && (is_error == 0))
	{
		if ((c == '{') || (c == '[') || (c == '(') || (c == '<'))
		{
			bracket[pos] = c;
			pos++;
		}

		else if (c == '}')
		{
			bracket_handler('{');
		}

		else if (c == ']')
		{
			bracket_handler('[');
		}

		else if (c == ')')
		{
			bracket_handler('(');
		}

		else if (c == '>')
		{
			bracket_handler('<');
		}
	}

	if ((is_error == 0) && (pos == 0))
	{
		printf("Program is correct");
	}
	else
	{
		printf("Program has syntax errors with unbalanced brackets");
	}
	return EXIT_SUCCESS;
}


void bracket_handler(char bracket_type)
{
	if ((pos > 0) && (bracket[pos - 1] == bracket_type))
	{
		bracket[pos - 1] = 0;
		pos--;
	}
	else
	{
		is_error = 1;
	}
	return;
}