#include <stdio.h>
#include <stdlib.h>

/* 
program "folds" long input lines into shorter lines 
Version_2: Program wraps words partially
NB! Program accept words for input no longer than MAXSIZE letters
*/

# define MAXSIZE 40 //max size of symbol array in the output string. Enter can have 11th position
# define NO_WRAP -1 

// ###########################################################################
// global variables
// ###########################################################################

char c;
char symb_arr[MAXSIZE + 1];
char vowels_arr[] = "aeiou";
int pos = 0; // position of the next symbol in input
int pos_after_delimiter = -1; // position after the last delimiter
int print_to = -1; //the element to print array to
char delimiter_arr[] = " /\\()\"\'-.,:;<>~!@#$%^&*|+=[]{}~\?│";
int wrap_position = -1;

// ###########################################################################
// functions
// ###########################################################################

void symbol_handler();
void wrap_handler();
void print_array(int print_to); 
void find_delimiter_limit_to_print();
void init_array(char array[], int index_from, int index_to);
void array_left_shift(int left_pos_to_shift);
int is_delimiter(char c);
void shift_array_by_delimiter();
void shift_array_by_wrap();

/* 
function takes the word from the global array XXX and limit_position to wrap the word
Returns the top right possible position of word wrap, otherwise -1
Rules:
1. Do not leave just one letter on the line (have at least 2 letters on the line)
2. Each part should contain vowel letter (a, e, u, etc)
3. Wrapping ends with vowel letter (e.g. hello -> he--llo)
*/
int find_word_wrap_position();
int is_vowel(char symb);
int find_vowel_position(int last_pos, int number);

// ###########################################################################

int main()
{
	init_array(symb_arr, 0, MAXSIZE + 1);

	while ((c = getchar()) != EOF)
	{
		if (pos < MAXSIZE)
		{
			symbol_handler();
		}
		else if (pos == MAXSIZE)
		{
			wrap_handler();
		}
	}

	print_array(pos);
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


void symbol_handler()
{
	symb_arr[pos] = c;
	pos++;
	if (is_delimiter(c))
	{
		pos_after_delimiter = pos;
	}
	if (c == '\n')
	{
		print_array(pos);
		pos = 0;
		pos_after_delimiter = -1;
	}
	return;
}


void wrap_handler()
{
	find_delimiter_limit_to_print();
	print_array(print_to);
	shift_array_by_delimiter();

	wrap_position = find_word_wrap_position();
	if (wrap_position != NO_WRAP)
	{
		print_array(wrap_position);
		putchar('-');
		shift_array_by_wrap();
	}
	putchar('\n');

	if (c != '\n')
	{
		symb_arr[pos] = c;
	}
	pos++;
	pos_after_delimiter = is_delimiter(c) ? pos : -1;
	return;
}


void find_delimiter_limit_to_print()
{
	print_to = (pos_after_delimiter > -1) ? pos_after_delimiter : pos;
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


void init_array(char array[], int index_from, int index_to)
{
	for (int i = index_from; i < index_to; i++)
	{
		array[i] = 0;
	}
	return;
}


void array_left_shift(int left_pos_to_shift)
{
	for (int i = left_pos_to_shift; i < pos; i++)
	{
		symb_arr[i - left_pos_to_shift] = symb_arr[i];

	}
	return;
}


void shift_array_by_delimiter()
{
	array_left_shift(pos_after_delimiter);
	int last_symb = pos;
	pos = (pos_after_delimiter > -1) ? (pos - pos_after_delimiter) : 0;
	init_array(symb_arr, pos, last_symb);
	return;
}


void shift_array_by_wrap()
{
	array_left_shift(wrap_position);
	int last_symb = pos;
	pos = pos - wrap_position;
	init_array(symb_arr, pos, last_symb);
	return;
}


int find_vowel_position(int last_pos, int number)
{
	int vowel_pos = -1;
	int result = 0;

	for (int n = 0; n < number; n++)
	{
		for (int i = last_pos; (i >= 0) && (result == 0); i--)
		{
			if (is_vowel(symb_arr[i]))
			{
				vowel_pos = last_pos;
				result = 1;
			}
			last_pos--;
		}
		if ((last_pos < 0) && (result == 0))
		{
			vowel_pos = -1;
		}
		else
		{
			last_pos = vowel_pos - 1;
			result = 0;
		}
	}
	return vowel_pos;
}


int is_vowel(char symb)
{
	int result = 0;
	for (int i = 0; (vowels_arr[i] != '\0') && (result == 0); i++)
	{
		if (symb == vowels_arr[i])
		{
			result = 1;
		}

	}
	return result;
}


int find_word_wrap_position()
{
	int word_length = -1;
	int vowel_position = -1;
	int last_symb_position = -1;
	int wrap_position = -1;

	word_length = pos;
	last_symb_position = word_length - 1;

	if (word_length > 3)
	{
		vowel_position = find_vowel_position(last_symb_position, 2);

		//printf("Vowel position = %d\n", vowel_position);
		if ((vowel_position > 0) && ((last_symb_position - vowel_position) > 1))
		{
			wrap_position = vowel_position + 1;
		}
		else if ((last_symb_position - vowel_position) <= 1)
		{
			vowel_position = find_vowel_position(last_symb_position, 3);
			if (vowel_position > 0)
			{
				wrap_position = vowel_position + 1;
			}
		}
		//printf("Pos to wrap = %d\n", wrap_position);
	}
	return wrap_position;
}