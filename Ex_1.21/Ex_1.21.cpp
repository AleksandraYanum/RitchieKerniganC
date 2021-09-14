#include <stdio.h>

# define IN 1 /* in the word*/
# define OUT 2 /* out of the word*/

/* entab: prints certain amount of tabs insted spaces  */

int main()
{
	int len_tab = 8; /* length of tab (8 by default) */
	int i = 0; /* position of current symbol */
	int c, space_count, state;
	space_count = 0;
	state = OUT;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (state == IN)
			{
				state = OUT;
			}
			space_count++;
		}
		else
		{
			if (state == OUT)
			{
				/* change spaces into tabs */
				state = IN;
				space_count = 0;
			}
			putchar(c);
		}
	}
	
	return 0;
}