#include <stdio.h>
#include <stdlib.h>

/* program "folds" long input lines into shorter lines */

# define MAXSIZE 6 //max size of the symbol array; it's also the length of line

// ###########################################################################
// global variables
// ###########################################################################

int pos = 0; // position of current symbol; shows, how many symbols were inputed
char symb_arr[MAXSIZE];

// ###########################################################################
// functions
// ###########################################################################

void print_array();

int main()
{
	int space_pos = 0; // position of the last space
	char c;

	for (int i = 0; i < MAXSIZE; i++)
	{
		symb_arr[i] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		if (pos < MAXSIZE)
		{
			if (c == ' ')
			{
				space_pos = pos;
			}
			symb_arr[pos] = c;
			pos++;
		}

		else if (pos == MAXSIZE)
		{
			symb_arr[space_pos] = '\n';
			print_array();
			pos = 1;
			symb_arr[0] = c;
			space_pos = 0;
		}
	}

	print_array();
	return EXIT_SUCCESS;
}


void print_array()
{
	for (int i = 0; i < pos; i++)
	{
		putchar(symb_arr[i]);
		symb_arr[i] = 0;
	}
	return;
}