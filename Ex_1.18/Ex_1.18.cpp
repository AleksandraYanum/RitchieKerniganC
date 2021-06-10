#include <stdio.h>

/* program removes trailing spaces and tabs and deletes empty lines */

#define MAXLINE 1000 /* max size of input line */

int getline(char line[], int maxline);

int main()
{
	int len; /* length of current line */
	char line[MAXLINE]; /* current line */

	printf("Please, print the line (not longer than 1000 symbols):\n");

	while ((len = getline(line, MAXLINE)) > 0)
	{
		printf("Your line was formatted:\n");
		printf("%s", line);
	}

	return 0;
}

int getline(char s[], int lim)
{
	int  i, k, n, space;
	int c;
	k = 0;
	n = 0;
	space = 0;
	for (i = 0; ((c = getchar()) != EOF) && c != '\n'; i++)
	{
		if (i < (lim - 1))
		{
			if ((c == ' ') || (c == '\t'))
			{
				if (space == 0)
				{
					s[n] = c;
					n++;
					space = 1;
					k = n + 1;
				}
			}
			else
			{
				space = 0;
				s[n] = c;
				n++;
				k = n + 1;
			}
		}

	}
	if (c == '\n')
	{
		if (i < (lim - 1))
		{
			s[n] = c;
		}
		i++;
	}

	s[k] = '\0';
	return i;
}