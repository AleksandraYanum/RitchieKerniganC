#include <stdio.h>

// deletes comments from program

# define IN 1 // in the comment
# define OUT 0 // out of the comment

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
			if (slash_count == 4)
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
			if (slash_count < 4)
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