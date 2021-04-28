#include <stdio.h>

# define IN 1 /* in the word*/
# define OUT 2 /* out of the word*/

/* print a histogram of the lengths of input words */

int main()
{
	int c, nc, state;
	state = OUT;
	nc = 0;
	while ((c = getchar()) != EOF)
	{
		if ((c == ' ' || c == '\t' || c == '\n') && (state == IN))
		{
			state = OUT;
			/* склдываем nc в массив*/
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