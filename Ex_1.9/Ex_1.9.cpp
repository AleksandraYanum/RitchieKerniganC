#include <stdio.h>
int main()

/* don't print more than 1 space together*/

{
	int c, space = 0;
	while ((c = getchar()) != EOF)
	{
		if (c != ' ')
		{
			space = 0;
		}
		else
		{
			space++;
		}
		if (space <= 1)
		{
			putchar(c);
		}
	}
	return 0;
}

		
		