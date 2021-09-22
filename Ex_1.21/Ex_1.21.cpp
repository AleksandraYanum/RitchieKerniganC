#include <stdio.h>

# define IN 1 // in the word
# define OUT 0 // out of the word

// entab: prints certain amount of tabs instead of spaces

void print_tab_space (int tab_to_print, int space_to_print);
void print_symbol(int c, int n);
void spaces2tabs(int last, int first, int len_tab);

int main()
{
	int len_tab = 8; // length of tab (8 by default)
	int state;
	int pos = 0; // position of current symbol;
	int first = 0; // position of the first letter of the next word (after spaces)
	int last = 0; // position of the last letter of the previous word (before spaces)
	char c; // input
	state = OUT;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (state == IN)
			{
				last = pos - 1;
				state = OUT;
			}
			pos++;
			
		}
		else if (c == '\n')
		{
			pos = 0;
			putchar(c);
		}
		else
		{			
			if (state == OUT)
			{
				state = IN;
				first = pos;

				spaces2tabs(last, first, len_tab);

				/*
				past_tabs = last / len_tab; // how many tab positions have we already passed
				all_tabs = first / len_tab; // how many tab positions are there from the line beginning
				tab_to_print = all_tabs - past_tabs;
				space_to_print = first % len_tab;
				print_tab_space(tab_to_print, space_to_print);
				*/

				first = last = 0;

				
			}
			pos++;
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

void spaces2tabs(int last, int first, int len_tab)
{
	int space_to_print = 0;
	int past_tabs = (last + 1) / len_tab; // how many tab positions have we already passed
	int all_tabs = (first + 1) / len_tab; // how many tab positions are there from the line beginning
	int tab_to_print = all_tabs - past_tabs;
	
	if ((tab_to_print == 0) && (first != 0))
	{
		space_to_print = first - last - 1;
	}
	else
	{
		space_to_print = first % len_tab;
	}
	print_tab_space(tab_to_print, space_to_print);

	return;
}
