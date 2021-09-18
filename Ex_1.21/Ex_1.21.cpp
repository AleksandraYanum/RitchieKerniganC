#include <stdio.h>

# define IN 1 /* in the word*/
# define OUT 0 /* out of the word*/

/* entab: prints certain amount of tabs insted spaces  */

void print_tab_space (int tab_to_print, int space_to_print);
void print_symbol(int c, int n);

int main()
{
	int len_tab = 8; /* length of tab (8 by default) */
	int i = 0; /* position of current symbol */
	int c, space_count, state, tab_to_print, r, space_to_print;
	space_count = 0;
	tab_to_print = 0;
	space_to_print = 0;
	r = 0;
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
				state = IN;
				/* change spaces into tabs */
				tab_to_print = space_count / len_tab;
				space_to_print = space_count % len_tab;
			
				print_tab_space(tab_to_print, space_to_print);
				space_count = 0;
			}
			
			putchar(c);
		}
	}
	
	return 0;
}
void print_tab_space(int tab_to_print, int space_to_print)
{
	print_symbol('\t', tab_to_print);
	print_symbol(' ', space_to_print);
	return;
}

void print_symbol(int c, int n)
{
	for (int i = 0; i < n; i++)
	{
		putchar(c);
	}
	return;
}