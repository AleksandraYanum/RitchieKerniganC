#include <stdio.h>

# define IN 1 // in the word
# define OUT 0 // out of the word

// entab: prints certain amount of tabs instead of spaces

void print_tab_space (int tab_to_print, int space_to_print);
void print_symbol(int c, int n);

int main()
{
	int len_tab = 8; // length of tab (8 by default)
	int state, tab_to_print, space_to_print;
	int pos = 0; // position of current symbol;
	int first = 0; // position of the first letter of the next word (after spaces)
	int last = 0; // position of the last letter of the previous word (before spaces)
	int past_tabs, all_tabs;
	char c; // input
	past_tabs = all_tabs = 0;
	tab_to_print = space_to_print = 0;
	state = OUT;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (state == IN)
			{
				last = pos;
				state = OUT;
			}
			
		}
		else
		{
			if (state == OUT)
			{
				state = IN;
				first = pos;
				// change spaces into tabs:
				past_tabs = last / len_tab; // how many tab positions have we already passed
				all_tabs = first / len_tab; // how many tab positions are there from the line beginning
				tab_to_print = all_tabs - past_tabs;
				space_to_print = first % len_tab;
				print_tab_space(tab_to_print, space_to_print);
				first = last = 0;
				
			}
			
			putchar(c);
		}
		pos++;
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