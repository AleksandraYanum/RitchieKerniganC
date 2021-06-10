#include <stdio.h>

/* program removes trailing spaces and tabs and deletes empty lines */

#define MAXLINE 1000 /* max size of input line */

int getline(char line[], int maxline);

int main()
{
	int len; /* length of current line */
	char line[MAXLINE]; /* current line */

	printf ("Please, print the line (not longer than 1000 symbols):\n");

	while ((len = getline(line, MAXLINE)) > 0)
	{
		if (len > 1)
		{
			printf("Your line was formatted:\n");
			printf("%s", line);
			printf("Print another line.\n");
		}
		else
		{
			printf("Your line is empty. Please, print another line.\n");
		}
	}

	return 0;
}

int getline(char s[], int lim)
{
	int  i, n, space;
	int c;
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
				}
			}
			else
			{
				space = 0;
				s[n] = c;
				n++;
			}
		}

	}
	if (c == '\n')
	{
		if (i < (lim - 1))
		{
			if (n > 0)
			{
				s[n] = c;
			}
		
		}
		i++;
	}

	s[n+1] = '\0';
	return i;
}