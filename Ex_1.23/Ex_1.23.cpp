#include <stdio.h>

// deletes comments from program

# define IN 1 // in the comment
# define OUT 0 // out of the comment
# define SINGLE_COMMENT_SLASH_COUNT 2 // amount of slashes that create comment

// ###########################################################################
// global variables
// ###########################################################################

int one_line_comment = OUT; // IN or OUT (of) the one-line comment (begins with '//')
int multi_line_comment = OUT; // IN or OUT (of) the multi-line comment (begins with '/*' and ends with '*/')
int slash_count = 0; // count of slashes that are standing in a ROW
char prev_symb = 0; //previous symbol
char c; // input

// ###########################################################################
// functions
// ###########################################################################

int out_of_comment();
void slash_handler();
void enter_handler();
void asterisk_handler();

// ###########################################################################

int main()
{
	while ((c = getchar()) != EOF)
	{
		if (c == '/')
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

		else //other symbols
		{
			//default_handler();
			if (out_of_comment())
			{
				if (slash_count < SINGLE_COMMENT_SLASH_COUNT)
				{
					for (int i = 0; i < slash_count; i++)
					{
						putchar('/');
					}
				}
				putchar(c);
				slash_count = 0;
			}
		}

		prev_symb = c;
	}
	return 0;
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

void slash_handler()
{
	if (out_of_comment())
	{
		slash_count++;
		if (slash_count == SINGLE_COMMENT_SLASH_COUNT)
		{
			one_line_comment = IN;
		}
	}
	else if ((multi_line_comment == IN) && (prev_symb == '*'))
	{
		multi_line_comment = OUT;
	}
	return;
}

void enter_handler()
{
	if (out_of_comment())
	{
		putchar(c);
		slash_count = 0;
	}
	else if (one_line_comment == IN)
	{
		one_line_comment = OUT;
		putchar(c);
	}
	return;
}

void asterisk_handler()
{
	if (out_of_comment())
	{
		if (prev_symb == '/')
		{
			multi_line_comment = IN;
		}
		else
		{
			putchar(c);
		}
	}
	return;
}