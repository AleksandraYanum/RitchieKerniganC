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

char c;
char symb_arr[MAXSIZE + 1];
int pos = 0; // position of current symbol in current output; shows, how many symbols were inputed
int space_pos = -1; // position of the last space in the array
int array_is_empty = YES;
int print_to = -1; //the element to print array to


// ###########################################################################
// functions
// ###########################################################################

void print_array(int print_to);
void find_limit_to_print();
void init_array(int index_from, int index_to);
void array_left_shift();
int is_delimiter(char c);


// ###########################################################################

int main()
{


	init_array(0, MAXSIZE + 1);

	while ((c = getchar()) != EOF)
	{
		if (pos < MAXSIZE + 1)
		{
			if (is_delimiter(c))
			{
				space_pos = pos;
			}
			symb_arr[pos] = c;
			pos++;
			array_is_empty = NO;
		}

		else if (pos == MAXSIZE + 1)
		{
			find_limit_to_print();
			print_array(print_to);
			putchar('\n');
			array_left_shift();
			int last_symb = pos;
			pos = pos - (space_pos + 1);
			init_array(pos, last_symb);
			
			symb_arr[pos] = c;
			if (is_delimiter(c))
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

	print_array(pos);
	
	return EXIT_SUCCESS;
}

int is_delimiter(char c)
{
	int result = 0;
	if ((c == ' ') || (c == ','))
	{
		result = 1;
	}
	return result;
}

void find_limit_to_print()
{
	if (space_pos > -1)
	{
		print_to = space_pos + 1;
	}
	else
	{
		print_to = pos;
	}
	return;
}

void print_array(int print_to)
{
	for (int i = 0; i < print_to; i++)
	{
		putchar(symb_arr[i]);
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
