#include <stdio.h>

/* program that reads a set of text lines and prints the longest */

#define MAXLINE 4 /* max size of input line */

int getline (char line[], int maxline);
void copy (char to [], char from[]);

int main()
{
	int len; /* length of current line */
	int max; /* length of max readed line */
	char line[MAXLINE]; /* current line */
	char longest[MAXLINE]; /* the longest line */
	max = 0;
	while ((len = getline (line, MAXLINE)) > 0)
	{
		if (len > max)
		{
			max = len;
			copy (longest, line);
		}
	}
	if (max > 0)
	{
		printf("The longest string is: %s\n", longest);
		printf("The length is: %d", max);
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

/* copy: copy from "from" to "to" */

void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
	{
		i++;
	}
}
