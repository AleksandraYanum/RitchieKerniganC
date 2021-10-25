#include <stdio.h>
#include <stdlib.h>

/* 
program "folds" long input lines into shorter lines 
Version_1: Program find the right position to shift words (after delimiter character)
NB! Program accept words for input no longer than MAXSIZE letters
*/

# define MAXSIZE 10 //max size of the symbol array; it's also the length of line

// ###########################################################################
// global variables
// ###########################################################################

char c;
char symb_arr[MAXSIZE + 1];
int pos = 0; // position of the next symbol in input
int space_pos = -1; // position of the last space in the array
int print_to = -1; //the element to print array to
char delimiter_arr[] = " /\\()\"\'-.,:;<>~!@#$%^&*|+=[]{}~\?│";

// ###########################################################################
// functions
// ###########################################################################

void print_array(int print_to, int is_new_line); //is_new_line: 1 - to print enter, 0 - not to print
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
		if (pos < MAXSIZE)
		{
			
			symb_arr[pos] = c;
			pos++;
			if (is_delimiter(c))
			{
				space_pos = pos;
			}
			if (c == '\n')
			{
				print_array(pos, 0);
				pos = 0;
				space_pos = -1;
			}
		}

		else if (pos == MAXSIZE)
		{
			find_limit_to_print();
			print_array(print_to, 1);
			array_left_shift();
			int last_symb = pos;
			if (space_pos > -1)
			{
				pos = pos - space_pos; //!!!!!!!!!!!!!!!!!!!
			}
			else
			{
				pos = 0;
			}
			init_array(pos, last_symb);
			if (c != '\n')
			{
				symb_arr[pos] = c;
			}
			pos++;
			if (is_delimiter(c))
			{
				space_pos = pos;
			}
			else
			{
				space_pos = -1;
			}
			
		}
	}

	print_array(pos, 0);
	
	return EXIT_SUCCESS;
}

int is_delimiter(char c)
{
	int result = 0;
	for (int i = 0; (delimiter_arr[i] != '\0') && (result == 0); i++)
	{
		if (c == delimiter_arr[i])
		{
			result = 1;
		}
	}
	return result;
}

void find_limit_to_print()
{
	if (space_pos > -1)
	{
		print_to = space_pos;
	}
	else
	{
		print_to = pos;
	}
	return;
}

void print_array(int print_to, int is_new_line)
{
	for (int i = 0; i < print_to; i++)
	{
		putchar(symb_arr[i]);
	}
	if (is_new_line == 1)
	{
		putchar('\n');
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
	for (int i = space_pos; i < pos; i++)
	{
		symb_arr[i - space_pos] = symb_arr[i];

	}
	return;
}
