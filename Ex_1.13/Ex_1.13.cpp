#include <stdio.h>

# define IN 1 /* in the word*/
# define OUT 2 /* out of the word*/
# define MAXSIZE 10 /* max length of input words*/

/* print a histogram of the lengths of input words */

int main()
{
	int i, c, nc, state;
	state = OUT;
	nc = 0;
	int hist[MAXSIZE];
	for (i = 0; i < MAXSIZE; i++)
	{
		hist[i] = 0;
	}
	while ((c = getchar()) != EOF)
	{
		if ((c == ' ' || c == '\t' || c == '\n') && (state == IN))
		{
			state = OUT;
			hist[nc - 1]++;			
			printf("Word length = %d\n", nc);
			nc = 0;
		}
		else if (state == IN)
		{
			nc++;
		}
		else
		{
			state = IN;
			nc++;
		}
	}
	return 0;
}