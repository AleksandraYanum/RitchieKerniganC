#include <stdio.h>

/* program prints lines with length > MINLENGTH symbols */

#define MAXLINE 1000 /* max size of input line */
#define MINLENGTH 10 /* min size of lines that shold be printed */

int getline(char line[], int maxline);

int main()
{
	int len; /* length of current line */
	char line[MAXLINE]; /* current line */
	printf("Please, input the first line.\n");

	while ((len = getline(line, MAXLINE)) > 0)
	{
		if (len > MINLENGTH)
		{
			printf("This line has more than %d symbols: %s", MINLENGTH, line);
		}
		else
		{
			printf("The line shorter than %d symbols.\n", MINLENGTH);
		}
		printf("Its length is %d symbol(s).\n", len);
		printf("Please, input another line.\n");
	}

	return 0;
}

/* getline: reads s and count its length */

int getline(char s[], int lim)
{
	int  i, k;
	int c;
	k = 0;
	for (i = 0; ((c = getchar()) != EOF) && c != '\n'; i++)
	{
		if (i < (lim - 1))
		{
			s[i] = c;
			k = i + 1;
		}
	}
	if (c == '\n')
	{
		if (i < (lim - 1))
		{
			s[i] = c;
			k++;
		}
		i++;
	}

	s[k] = '\0';
	return i;
}

