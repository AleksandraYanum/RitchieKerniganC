#include <stdio.h>

/* count digits, white spaces and other symbols*/

int main()
{
	int c, i, nspace, nother;
	int ndigit[10];
	nspace = nother = 0;
	for (i = 0; i < 10; i++)
	{
		ndigit[i] = 0;
	}
	while ((c = getchar()) != EOF)
	{
		if (c >= '0' && c <= '9')
		{
			ndigit[c - '0']++;
		}
		else if (c == ' ' || c == '\t' || c == '\n')
		{
			nspace++;
		}
		else
		{
			nother++;
		}
	}

	printf("Digits: \n");
	for (i = 0; i < 10; i++)
	{
		printf("%d - ", i);
		printf ("%d\n", ndigit[i]);
	}

	printf("\nWhite spaces (space, tab, ent): %d", nspace);
	printf("\nOther symbols: %d", nother);

	return 0;
}