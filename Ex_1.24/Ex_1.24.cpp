#include <stdio.h>
#include <stdlib.h>

/* program checks a C program for syntax errors like unbalanced brackets */

# define MAXSIZE 10 //max size of the array with opening brackets
# define IN 1 // in the comment
# define OUT 0 // out of the comment
# define SINGLE_COMMENT_SLASH_COUNT 2 // amount of slashes that create comment

// ###########################################################################
// functions
// ###########################################################################

void bracket_handler(char bracket_type);
void slash_handler();
void enter_handler();
void asterisk_handler();
int out_of_comment();
void print_status();
void quote_handler();
void backslash_handler();
void default_handler();


// ###########################################################################
// global variables
// ###########################################################################

int pos = 0; //position of array elements
char bracket[MAXSIZE];
int is_error = 0; // 1 - error, 0 - not error
int one_line_comment = OUT; // IN or OUT (of) the one-line comment (begins with '//')
int multi_line_comment = OUT; // IN or OUT (of) the multi-line comment (begins with '/*' and ends with '*/')
int str = OUT; // IN or OUT (of) the printed string
int slash_count = 0; // count of slashes that are standing in a ROW
char prev_symb = 0; //previous symbol
char prev_quote = 0; //type of previous quote (it can be " or ')
char c; // input
int line_count = 1;
char error_bracket; //unbalanced closing bracket
int escape = 0; // 0 - not a character constant; 1 - is a character constant


int main()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		bracket[i] = 0;
	}

	while (((c = getchar()) != EOF) && (is_error == 0))
	{
		if (((c == '{') || (c == '[') || (c == '(')) && (out_of_comment()) && (str == OUT))
		{
			bracket[pos] = c;
			pos++;
		}

		else if (c == '}')
		{
			bracket_handler('{');
		}

		else if (c == ']')
		{
			bracket_handler('[');
		}

		else if (c == ')')
		{
			bracket_handler('(');
		}

		else if (c == '/')
		{
			slash_handler();
		}

		else if (c == '\n')
		{
			enter_handler();
		}

		else if (c == '*')
		{
			asterisk_handler();
		}

		else if ((c == '"') || (c == '\''))
		{
			quote_handler();
		}

		else if (c == '\\')
		{
			backslash_handler();
		}

		else
		{
			default_handler();
		}

		prev_symb = c;
	}

	print_status();

	return EXIT_SUCCESS;
}


void bracket_handler(char bracket_type)
{
	if (str == OUT)
	{
		if (out_of_comment())
		{
			if (slash_count < SINGLE_COMMENT_SLASH_COUNT)
			{
				if ((pos > 0) && (bracket[pos - 1] == bracket_type))
				{
					bracket[pos - 1] = 0;
					pos--;
				}
				else
				{
					is_error = 1;
					error_bracket = c;
				}
			}
		}
	}
	else
	{
		escape = 0;
	}
	return;
}

void slash_handler()
{
	if (str == OUT)
	{
		if (out_of_comment())
		{
			slash_count++;
			if (slash_count == SINGLE_COMMENT_SLASH_COUNT)		//amount of slashes that create comment
			{
				one_line_comment = IN;
			}
		}
		else if ((multi_line_comment == IN) && (prev_symb == '*'))
		{
			multi_line_comment = OUT;
		}
	}
	else
	{
		escape = 0;
	}
	return;
}

void enter_handler()
{
	if (str == OUT)
	{
		if (one_line_comment == IN)
		{
			one_line_comment = OUT;
			slash_count = 0;
		}
		line_count++;
	}
	return;
}

void asterisk_handler()
{
	if (str == OUT)
	{
		if (out_of_comment())
		{
			if (prev_symb == '/')
			{
				multi_line_comment = IN;
			}
		}
	}
	else
	{
		escape = 0;
	}
	return;
}

int out_of_comment()
{
	int result = 0;
	if ((multi_line_comment == OUT) && (one_line_comment == OUT))
	{
		result = 1;
	}
	return result;
}

void print_status()
{
	if ((is_error == 0) && (pos == 0))
	{
		printf("Program is correct.");
	}
	else

	{
		printf("Line %d: Program has syntax errors with unbalanced brackets.\n", line_count);

		if ((is_error == 1) && (pos == 0))
		{
			printf("Bracket %c doesn't have the corresponding opening one.", error_bracket);
		}

		else if ((is_error == 0) && (pos > 0))
		{
			printf("Bracket %c doesn't have the corresponding closing one.", bracket[pos - 1]);
		}

		else if ((is_error == 1) && (pos > 0))
		{
			printf("Unbalanced brackets are: %c and %c.", bracket[pos - 1], error_bracket);
		}
	}
	return;
}

void quote_handler()
{
	if (out_of_comment())
	{
		if (str == OUT)
		{
			str = IN;
			prev_quote = c;
		}
		else
		{
			if (escape == 0)
			{
				if (c == prev_quote)
				{
					str = OUT;
					prev_quote = 0;
				}
			}
			else
			{
				escape = 0;
			}
		}
	}

	return;
}

void backslash_handler()
{
	if (str == IN)
	{
		if (escape == 0)
		{
			escape = 1;
		}
		else
		{
			escape = 0;
		}
	}
	return;
}

void default_handler()
{
	escape = 0;
	return;
}

