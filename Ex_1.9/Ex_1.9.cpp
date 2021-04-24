#include <stdio.h>

int main()
{
	int prev, c;
	prev = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (prev != ' ')
			{
				putchar(c);
			}
		}
		else
		{
			putchar(c);
		}
		prev = c;
	}
	return 0;
}

