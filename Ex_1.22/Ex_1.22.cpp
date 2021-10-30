#include <stdio.h>
#include <stdlib.h>

/* 
program "folds" long input lines into shorter lines 
Version_2: Program wraps words partially
NB! Program accept words for input no longer than MAXSIZE letters
*/

# define MAXSIZE 10 //max size of symbol array in the output string. Enter can have 11th position

// ###########################################################################
// global variables
// ###########################################################################

char c;
char symb_arr[MAXSIZE + 1];
int pos = 0; // position of the next symbol in input
int pos_after_delimiter = -1; // position after the last delimiter
int print_to = -1; //the element to print array to
char delimiter_arr[] = " /\\()\"\'-.,:;<>~!@#$%^&*|+=[]{}~\?│";
int wrap_position = -1;

// ###########################################################################
// functions
// ###########################################################################

void print_array(int print_to, int is_new_line); //is_new_line: 1 - to print enter, 0 - not to print
void find_limit_to_print();
void init_array(int index_from, int index_to);
void array_left_shift();
int is_delimiter(char c);

/* 
function takes the word from the global array XXX and limit_position to wrap the word
Returns the top right possible position of word wrap, otherwise -1
Rules:
1. Do not leave just one letter on the line (have at least 2 letters on the line)
2. Each part should contain vowel letter (a, e, u, etc)
3. Wrapping ends with vowel letter (e.g. hello -> he--llo)
*/
int find_word_wrap_position();
	
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
				pos_after_delimiter = pos;
			}
			if (c == '\n')
			{
				print_array(pos, 0);
				pos = 0;
				pos_after_delimiter = -1;
			}
		}

		else if (pos == MAXSIZE)
		{
			find_limit_to_print();
			print_array(print_to, 0);
			array_left_shift();
			int last_symb = pos;
			pos = (pos_after_delimiter > -1) ? (pos - pos_after_delimiter) : 0;
			init_array(pos, last_symb);

			wrap_position = find_word_wrap_position();
			if (wrap_position == -1)
			{
				putchar('\n');
			}
			else
			{
				print_array(wrap_position, 0);
				putchar('\n');
			}
			

			if (c != '\n')
			{
				symb_arr[pos] = c;
			}
			pos++;
			pos_after_delimiter = is_delimiter(c) ? pos : -1;
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
	print_to = (pos_after_delimiter > -1) ? pos_after_delimiter : pos;
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
	for (int i = pos_after_delimiter; i < pos; i++)
	{
		symb_arr[i - pos_after_delimiter] = symb_arr[i];

	}
	return;
}

int find_word_wrap_position()
{
	wrap_position = 2;
	return wrap_position;
}
