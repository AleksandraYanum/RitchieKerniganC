#include <stdio.h>
#include <stdlib.h>

//Program deletes each character in s1 that matches any character in the string s2

#define MAXSIZE 101

// ###########################################################################
// functions
// ###########################################################################

void squeeze(char source[], const char pattern[]);
int getline(char s[], int lim);

// ###########################################################################

int main()
{
	int len = 0;
	char main_string[MAXSIZE];
	char string_to_delete[MAXSIZE];

	printf("Input main string no longer than %d symbols:\n", (MAXSIZE - 1));
	getline(main_string, MAXSIZE);

	printf("Input chars that should be deleted:\n");
	getline(string_to_delete, MAXSIZE);

	squeeze(main_string, string_to_delete);
	printf("Modifyed string is:\n%s\n", main_string);

	return EXIT_SUCCESS;
}


void squeeze(char source[], const char pattern[])
{
	int i, j, pos;

	for (j = 0; pattern[j] != '\0'; j++)
	{
		for (i = 0; source[i] != '\0'; i++)
		{
			if (source[i] == pattern[j])
			{
				//shift source to 1 element left
				for (pos = i; source[pos] != '\0'; pos++) 
				{
					source[pos] = source[pos + 1];
				}
				i--;
			}
		}
	}

	return;
}


int getline(char s[], int lim)
{
	int i;
	int end_of_line = 0;
	int c;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		s[i] = c;
		end_of_line = i + 1;
	}
	s[end_of_line] = '\0';
	return i;
}