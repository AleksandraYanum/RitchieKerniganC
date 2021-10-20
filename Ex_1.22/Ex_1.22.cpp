#include <stdio.h>
#include <stdlib.h>

/* program "folds" long input lines into shorter lines */

# define MAXSIZE 6 //max size of the symbol array; it's also the length of line

// ###########################################################################
// global variables
// ###########################################################################

int pos = 0; // position of current symbol; shows, how many symbols were inputed
int pos_arr = 0; //position of current symbol in array
int space_pos = 0; // position of the last space
char symb_arr[MAXSIZE];

// ###########################################################################
// functions
// ###########################################################################

void print_array();

int main()
{
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
				space_pos = pos_arr;
			}
			symb_arr[pos_arr] = c;
			pos++;
			pos_arr++;
		}

		else if (pos == MAXSIZE)
		{
			symb_arr[space_pos] = '\n';
			print_array();
			symb_arr[0] = c;
			pos = pos - space_pos;
			space_pos = 0;
			pos_arr = 1;
		}
	}

	print_array();
	return EXIT_SUCCESS;
}


void print_array()
{
	//symb_arr[space_pos] = '\n';
	for (int i = 0; i < pos_arr; i++)
	{
		putchar(symb_arr[i]);
		symb_arr[i] = 0;
	}
	return;
}