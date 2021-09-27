#include <stdio.h>

// deletes comments from program

# define IN 1 // in the comment
# define OUT 0 // out of the comment
# define SINGLE_COMMENT_SLASH_COUNT 2 // amount of slashes that create comment

int main()
{
	int slash_count = 0; // count of slashes that are standing in a ROW
	int asterisk_count = 0; // count of '*'
	int state = OUT; // IN or OUT (of) the comment
	char c; // input
	int i = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '/')
		{
			slash_count++;
			if (slash_count == SINGLE_COMMENT_SLASH_COUNT)
			{
				state = IN;
			}

		}
		else if (c == '\n')
		{
			if (state == OUT)
			{
				putchar(c);
				slash_count = 0;
			}
			else
			{
				if ((slash_count > 1) && (slash_count <= SINGLE_COMMENT_SLASH_COUNT))
				{
					state = OUT;
					putchar(c);
					slash_count = 0;
				}
			}
		}
		else if (c == '*')
		{
			asterisk_count++;
			if (slash_count == 1)
			{
				state = IN;
			}
		}
		else
		{
			/* if (slash_count < SINGLE_COMMENT_SLASH_COUNT)
			{
				for (i = 0; i < slash_count; i++)
				{
					putchar('/');
				}
				slash_count = 0;
				asterisk_count = 0; */
			
			if (state == OUT)
			{
				if ((slash_count !=0) && (slash_count < SINGLE_COMMENT_SLASH_COUNT))
				{
					for (i = 0; i < slash_count; i++)
					{
						putchar('/');
					}
					slash_count = 0;
					asterisk_count = 0;
				}
				putchar(c);
			}
		}
	}

	return 0;
}