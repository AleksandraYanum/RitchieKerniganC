#include <stdio.h>

/* count lines, words and symbols */

int main()
{
	int nl, nw, nc, state, c;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		nc++;
	}
	printf ("Symbol count = %d\n", nc);
	return 0;
}