#include <stdio.h>

# define IN 1 /* in the word*/
# define OUT 2 /* out of the word*/

/* print input one word per line*/

int main()
{
	int c, state;
	state = OUT;
	printf ("Enter string: ");
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t')
		{
			state = OUT;
			printf("\n");
		}
		else if (state = OUT)
		{
			state = IN;
			putchar(c);
		}
	}
		
	return 0;
}
