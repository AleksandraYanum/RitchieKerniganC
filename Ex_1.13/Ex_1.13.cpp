#include <stdio.h>

# define IN 1 /* in the word*/
# define OUT 2 /* out of the word*/
# define MAXSIZE 10 /* max length of input words*/
# define SIZE 4 /* array size of words with length from 2 to 5 symbols */
# define SYMB '*' /* symbol of histogram */

/* print a histogram of the lengths of input words */

int main()
{
	int i, k, c, nc, state;
	state = OUT;
	nc = 0;
	int hist[MAXSIZE];
	/*
	int histrev[MAXSIZE];
	int hist2_5[4];
	*/
	for (i = 0; i < MAXSIZE; i++)
	{
		hist[i] = 0;
	/*
		histrev[i] = 0;
	*/
	}
	/*
	for (i = 0; i < SIZE; i++)
	{
		hist2_5[i] = 0;
	}
	*/
	while ((c = getchar()) != EOF)
	{
		if ((c == ' ' || c == '\t' || c == '\n') && (state == IN))
		{
			state = OUT;
			/* 
			if ((nc >= 2) && (nc <= 5))
			{
				hist2_5[nc - 2]++;
			}
			*/
			hist[nc - 1]++;	
			/*
			histrev[MAXSIZE - nc]++;
			printf("Word length = %d\n", nc);
			*/
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
	printf ("Amount of words with certain length:\n");
	for (i = 0; i < MAXSIZE; i++)
	{
		printf("%d - ", i + 1);
		for (k = 0; k < hist[i]; k++)
		{
			putchar(SYMB);
		}
		putchar('\n');
	}

	return 0;
}