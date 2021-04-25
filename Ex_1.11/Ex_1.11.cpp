#include <stdio.h>

/* count lines, words and symbols */

int main()
{
	int nl, nw, nc, state, c;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		nc++;
		if (c == '\n')
		{
			nl++;
		}
	}
	printf ("Symbols count = %d\n", nc);
	printf("Lines count = %d\n", nl);
	return 0;
}