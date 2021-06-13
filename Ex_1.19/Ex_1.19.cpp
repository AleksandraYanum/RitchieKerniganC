#include <stdio.h>

/* program reverses the line */

#define MAXLINE 1000 /* max size of input line */

int getline(char line[], int maxline);
void reverse(char s[]);
int strlen(char s[]);
void swap(char s[], int i, int k);

int main()

{
	int len; /* length of current line */
	char line[MAXLINE]; /* current line */

	printf("Please, print the line (not longer than 1000 symbols):\n");

	while ((len = getline(line, MAXLINE)) > 0)
	{
		reverse(line);
		printf("Your line was reversed: \n");
		printf("%s\n", line);
	}

	return 0;
}

/* reverse: reverses the character string s" */

void reverse(char s[])
{
	int i;
	int temp, size, delta;

	i = 0;

	size = strlen(s);
	delta = size % 2;
	
	for (i = 0; i < (size / 2); i++)
	{
		
		swap(s, i, size / 2 + i + delta); 
	}

	return;
}

int strlen(char s[])
{
	int i;
	for (i = 0; (s[i] != '\n') && (s[i] != '\0'); i++)
	{}

	return i;
}

//swaps char with index i to char with index k in the line s

void swap(char s[], int i, int k) 
{
	int temp;
	temp = s[i];
	s[i] = s[k];
	s[k] = temp;
}


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
