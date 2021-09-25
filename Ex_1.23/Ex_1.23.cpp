#include <stdio.h>

// deletes comments from program

# define IN 1 // in the comment
# define OUT 0 // out of the comment

int main()
{
	int slash_count = 0; // count of slashes that are standing in a ROW
	int state = OUT; // IN or OUT (of) the comment
	char c; // input

	while ((c = getchar()) != EOF)
	{
		if (c == '/')
		{
			slash_count++;
			if (slash_count == 2)
			{
				state = IN;
			}

		}
		else
		{
			if (slash_count == 1)
			{
				putchar('/');
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