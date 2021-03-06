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
int str = OUT; // IN or OUT (of) the printed string
int slash_count = 0; // count of slashes that are standing in a ROW
char prev_symb = 0; //previous symbol
char prev_quote = 0; //type of previous quote (it can be " or ')
char c; // input

// ###########################################################################
// functions
// ###########################################################################

int out_of_comment();
void slash_handler();
void enter_handler();
void asterisk_handler();
void default_handler();
void quote_handler();

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

		else if ((c == '"') || (c == '\''))
		{
			quote_handler();
		}

		else //other symbols
		{
			default_handler();
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
	if (str == OUT)
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
	}
	else
	{
		putchar(c);
	}
	return;
}

void enter_handler()
{
	if (str == OUT)
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
	}
	else
	{
		putchar(c);
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
			else
			{
				putchar(c);
			}
		}
	}
	else
	{
		putchar(c);
	}
	return;
}

void default_handler()
{
	if (str == OUT)
	{
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
	else
	{
		putchar(c);
	}
	return;
}

void quote_handler()
{
	if (out_of_comment())
	{
		if (prev_symb != '\\')
		{
			if (str == OUT)
			{
				str = IN;
				prev_quote = c;
			}
			else
			{
				if (c == prev_quote)
				{
					str = OUT;
					prev_quote = 0;
				}
			}
		}
		putchar(c);
	}
	
	return;
}