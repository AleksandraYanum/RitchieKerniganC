#include <stdio.h>
#include <stdlib.h>

/* 
program "folds" long input lines into shorter lines 
Version_1: Program replaces the necessary space with enter
NB! Program accept words for input no longer than MAXSIZE letters
*/

# define MAXSIZE 6 //max size of the symbol array; it's also the length of line

// ###########################################################################
// global variables
// ###########################################################################

int pos = 0; // position of current symbol in current output; shows, how many symbols were inputed
int pos_arr = 0; //position of current symbol in array
int space_pos = -1; // position of the last space
char symb_arr[MAXSIZE + 1];

// ###########################################################################
// functions
// ###########################################################################

void print_array();

int main()
{
	char c;

	for (int i = 0; i < MAXSIZE + 1; i++)
	{
		symb_arr[i] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		if (pos < MAXSIZE + 1)
		{
			if (c == ' ')
			{
				space_pos = pos_arr;
			}
			symb_arr[pos_arr] = c;
			pos++;
			pos_arr++;
		}

		else if (pos == MAXSIZE + 1)
		{
			if (space_pos >= 0)
			{
				symb_arr[space_pos] = '\n';
			}
			print_array();
			symb_arr[0] = c;
			pos = pos - space_pos;
			if (c == ' ')
			{
				space_pos = 0;
			}
			else
			{
				space_pos = -1;
			}
			
			pos_arr = 1;
		}
	}

	if (space_pos >= 0)
	{
		symb_arr[space_pos] = '\n';
	}
	print_array();
	return EXIT_SUCCESS;
}


void print_array()
{

	for (int i = 0; i < pos_arr; i++)
	{
		putchar(symb_arr[i]);
		symb_arr[i] = 0;
	}
	return;
}