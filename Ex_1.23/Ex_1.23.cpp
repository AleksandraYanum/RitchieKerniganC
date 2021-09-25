#include <stdio.h>

// deletes comments from program

# define IN 1 // in the comment
# define OUT 0 // out of the comment
# define SINGLE_COMMENT_SLASH_COUNT 2 // amount of slashes that create comment

int main()
{
	int slash_count = 0; // count of slashes that are standing in a ROW
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
			putchar(c);
			slash_count = 0;
			state = OUT;
		}
		else
		{
			if (slash_count < SINGLE_COMMENT_SLASH_COUNT)
			{
				for (i = 0; i < slash_count; i++)
				{
					putchar('/');
				}
				slash_count = 0;
			}
			if (state == OUT)
			{
				putchar(c);
			}
		}
	}

	return 0;
}