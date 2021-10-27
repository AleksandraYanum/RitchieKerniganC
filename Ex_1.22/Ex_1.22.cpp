#include <stdio.h>
#include <stdlib.h>

/* 
program "folds" long input lines into shorter lines 
Version_2: Program shifts words partially
NB! Program accept words for input no longer than MAXSIZE letters
*/

# define MAXSIZE 50 //max size of the symbol array; it's also the length of line

// ###########################################################################
// global variables
// ###########################################################################

char c;
char symb_arr[MAXSIZE + 1];
int pos = 0; // position of the next symbol in input
int delimiter_pos = -1; // position after the last delimiter
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
				delimiter_pos = pos;
			}
			if (c == '\n')
			{
				print_array(pos, 0);
				pos = 0;
				delimiter_pos = -1;
			}
		}

		else if (pos == MAXSIZE)
		{
			find_limit_to_print();
			print_array(print_to, 1);
			array_left_shift();
			int last_symb = pos;
			pos = (delimiter_pos > -1) ? (pos - delimiter_pos) : 0;
			init_array(pos, last_symb);
			if (c != '\n')
			{
				symb_arr[pos] = c;
			}
			pos++;
			delimiter_pos = is_delimiter(c) ? pos : -1;
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
	print_to = (delimiter_pos > -1) ? delimiter_pos : pos;
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
	for (int i = delimiter_pos; i < pos; i++)
	{
		symb_arr[i - delimiter_pos] = symb_arr[i];

	}
	return;
}
