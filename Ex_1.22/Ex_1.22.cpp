#include <stdio.h>
#include <stdlib.h>

/* 
program "folds" long input lines into shorter lines 
Version_1: Program replaces the necessary space with enter
NB! Program accept words for input no longer than MAXSIZE letters
*/

# define MAXSIZE 6 //max size of the symbol array; it's also the length of line
# define YES 1
# define NO 0


// ###########################################################################
// global variables
// ###########################################################################

char symb_arr[MAXSIZE + 1];
int pos = 0; // position of current symbol in current output; shows, how many symbols were inputed
int space_pos = -1; // position of the last space in the array
int array_is_empty = YES;


// ###########################################################################
// functions
// ###########################################################################

void print_array();
void init_array(int index_from, int index_to);
void array_left_shift();


// ###########################################################################

int main()
{
	char c;

	init_array(0, MAXSIZE + 1);

	while ((c = getchar()) != EOF)
	{
		if (pos < MAXSIZE + 1)
		{
			if (c == ' ')
			{
				space_pos = pos;
			}
			symb_arr[pos] = c;
			pos++;
			array_is_empty = NO;
		}

		else if (pos == MAXSIZE + 1)
		{
			print_array();
			putchar('\n');
			if (array_is_empty == NO)
			{
				array_left_shift();
				int last_symb = pos;
				pos = pos - (space_pos + 1);
				init_array(pos, last_symb);
			}
			else
			{
				pos = 0;
			}
			symb_arr[pos] = c;
			if (c == ' ')
			{
				space_pos = pos;
			}
			else
			{
				space_pos = -1;
			}
			pos++;
		}
	}

	print_array();
	
	if (array_is_empty == NO)
	{
		putchar('\n');
		array_left_shift();
		int last_symb = pos;
		pos = pos - (space_pos + 1);
		space_pos = -1;
		init_array(pos, last_symb);
		print_array();
	}
	
	return EXIT_SUCCESS;
}


void print_array()
{
	if (space_pos > -1)
	{
		for (int i = 0; i <= space_pos; i++)
		{
			putchar(symb_arr[i]);
		}
	}
	else if (space_pos == -1)
	{
		for (int i = 0; i < pos; i++)
		{
			putchar(symb_arr[i]);
			symb_arr[i] = '\0';
			
		}
		array_is_empty = YES;
	}
	
	return;
}

void init_array(int index_from, int index_to)
{
	for (int i = index_from; i < index_to; i++)
	{
		symb_arr[i] = 0;
	}
	return;
}

void array_left_shift()
{
	for (int i = space_pos + 1; i < pos; i++)
	{
		symb_arr[i - (space_pos + 1)] = symb_arr[i];

	}
	return;
}
