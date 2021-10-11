#include <stdio.h>
#include <stdlib.h>

/* program checks a C program for syntax errors like unbalanced brackets */
// test commit

# define OPENING_BRACKET '{'
# define CLOSING_BRACKET '}'


int main()
{
	int bracket_count = 0; // count paired brackets: +1 if opening braket; -1 if closing bracket
	char c; //input

	while (((c = getchar()) != EOF) && (bracket_count >= 0))
	{
		if (c == OPENING_BRACKET)
		{
			bracket_count++;
		}
		else if (c == CLOSING_BRACKET)
		{
			bracket_count--;
		}
	}

	if (bracket_count == 0)
	{
		printf("Program compiled");
	}
	else
	{
		printf("Program has syntax errors withn unbalanced brackets");
	}

	return EXIT_SUCCESS;
}