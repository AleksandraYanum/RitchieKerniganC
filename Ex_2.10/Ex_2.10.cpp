#include <stdio.h>
#include <stdlib.h>

//Program converts upper case lettres to lower case (with a conditional expression instead of if-else)

//###########################################################################
// functions
// ###########################################################################

int lower(char c);

// ###########################################################################

int main()
{
	char symb;
	while (((symb = getchar()) != EOF) && (symb != '\n'))
	{
		symb = lower(symb);
		putchar(symb);
	}

	return EXIT_SUCCESS;
}

int lower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c = c + 'a' - 'A';
	}
	return c;
}

