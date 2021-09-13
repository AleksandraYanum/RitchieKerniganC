#include <stdio.h>

/* detab: print certain amount of spaces insted tabs*/

void print_space(int count);

int main()
{
	int len_tab = 8; /* length of tab (8 by default) */
	int i = 0; /* position of current symbol */
	int r; /* remainder of division */
	int c, n;
	i = n = r = 0;
	while ((c = getchar()) != EOF)
	{	
		if (c == '\t')
		{
			r = i % len_tab;
			n = len_tab - r;
			i = i + n;
			print_space(n);
		}
		else
		{
			putchar(c);
			if (c == '\n')
			{
				i = 0;
			}
			else
			{
				i++;
			}
		}
	}
	return 0;
}


void print_space(int count)
{
	for (int i = 0; i < count; i++)
	{
		putchar(' ');
	}
	return;
}