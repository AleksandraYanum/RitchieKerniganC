#include <stdio.h>
#include <stdlib.h>

/* program checks a C program for syntax errors like unbalanced brackets */
// test commit

# define OPENING_BRACKET '{'
# define CLOSING_BRACKET '}'
# define MAXSIZE 10 //max size of the array with opening brackets


int main()
{
	//int bracket_count = 0; // count paired brackets: +1 if opening braket; -1 if closing bracket
	char c; //input
	char bracket[MAXSIZE];
	int pos = 0; //position of array elements
	int is_error = 0; // 1 - error, 0 - not error

	for (int i = 0; i < MAXSIZE; i++)
	{
		bracket[i] = 0;
	}

	while (((c = getchar()) != EOF) && (is_error == 0))
	{
		if ((c == '{') || (c == '['))						//|| (c == '[') || (c == '('))
		{
			bracket[pos] = c;
			pos++;
		}

		else if (c == '}')
		{
			if ((pos > 0) && (bracket[pos - 1] == '{'))
			{
				bracket[pos - 1] = 0;
				pos--;
			}
			else
			{
				is_error = 1;
			}
		}

		else if (c == ']')
		{
			if ((pos > 0) && (bracket[pos - 1] == '['))
			{
				bracket[pos - 1] = 0;
				pos--;
			}
			else
			{
				is_error = 1;
			}
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