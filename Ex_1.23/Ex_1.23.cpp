#include <stdio.h>

// deletes comments from program

# define IN 1 // in the comment
# define OUT 0 // out of the comment
# define SINGLE_COMMENT_SLASH_COUNT 2 // amount of slashes that create comment

int main()
{
	int slash_count = 0; // count of slashes that are standing in a ROW
	int one_line_comment = OUT; // IN or OUT (of) the one-line comment (begins with '//')
	int multi_line_comment = OUT; // IN or OUT (of) the multi-line comment (begins with '/*' and ends with '*/')
	char c; // input
	char prev_symb = 0; //previous symbol
	
	while ((c = getchar()) != EOF)
	{
		if (c == '/')
		{
			if ((multi_line_comment == OUT) && (one_line_comment == OUT))
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

		else if (c == '\n')
		{
			if ((multi_line_comment == OUT) && (one_line_comment == OUT))
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

		else if (c == '*')
		{
			if ((multi_line_comment == OUT) && (one_line_comment == OUT))
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

		else //other symbols
		{
			if ((one_line_comment == OUT) && (multi_line_comment == OUT))
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