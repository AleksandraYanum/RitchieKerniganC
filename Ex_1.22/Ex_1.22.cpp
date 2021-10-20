#include <stdio.h>
#include <stdlib.h>

/* program "folds" long input lines into shorter lines */

# define MAXSIZE 6 //max size of the symbol array; it's also the length of line

int main()
{
	int pos = 0; // position of the next symbol; shows, how many symbols were inputed
	int space_pos = 0; // position of the last space
	char symb_arr[MAXSIZE];
	char c;

	for (int i = 0; i < MAXSIZE; i++)
	{
		symb_arr[i] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		if (pos < MAXSIZE)
		{
			if (c == ' ')
			{
				space_pos = pos;
			}
			symb_arr[pos] = c;
			pos++;
		}

		else if (pos == MAXSIZE)
		{
			symb_arr[space_pos] = '\n';

			for (int i = 0; i < pos; i++)
			{
				putchar(symb_arr[i]);
				symb_arr[i] = 0;
			}

			pos = 1;
			symb_arr[0] = c;
			space_pos = 0;
		}

	}
	
	for (int i = 0; i < pos; i++)
	{
		putchar(symb_arr[i]);
		symb_arr[i] = 0;
	}



	return EXIT_SUCCESS;
}