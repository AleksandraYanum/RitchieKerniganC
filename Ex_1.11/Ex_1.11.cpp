#include <stdio.h>

# define IN 1 /* in the word*/
# define OUT 2 /* out of the word*/

/* count lines, words and symbols */

int main()
{
	int nl, nw, nc, state, c;
	nl = nw = nc = 0;
	state = OUT;
	while ((c = getchar()) != EOF)
	{
		nc++;
		if (c == '\n')
		{
			nl++;
		}
		if (c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
		}
		else if (state == OUT)
		{
			state = IN;
			nw++;
		}
	}
	printf ("Symbols count = %d\n", nc);
	printf("Lines count = %d\n", nl);
	printf("Words count = %d\n", nw);
	return 0;
}