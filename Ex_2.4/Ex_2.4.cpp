#include <stdio.h>
#include <stdlib.h>

//Program deletes each character in s1 that matches any character in the string s2

#define MAXSIZE 101

// ###########################################################################
// functions
// ###########################################################################

void squeeze(char source[], char pattern[]);
void deduplicate(char line[]);
int getline(char s[], int lim);

// ###########################################################################

int main()
{
	int len = 0;
	char main_string[MAXSIZE];
	char string_to_delete[MAXSIZE];

	printf("Input main string no longer than %d symbols:\n", (MAXSIZE - 1));
	getline(main_string, MAXSIZE);

	printf("\nInput chars that should be deleted:\n");
	getline(string_to_delete, MAXSIZE);

	squeeze(main_string, string_to_delete);
	printf("\nModifyed string is:\n%s\n", main_string);

	return EXIT_SUCCESS;
}


void squeeze(char source[], char pattern[])
{
	int i = 0;
	int j = 0;

	deduplicate(pattern);
	while (pattern[j] != '\0')
	{
		while (source[i] != '\0')
		{
			if (source[i] != pattern[j])
			{
				i++;
			}
			else
			{
				//shift array to one element left
				for (int pos = i; source[pos] != '\0'; pos++)
				{
					source[pos] = source[pos + 1];
				}
			}
		}
		i = 0;
		j++;
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


void deduplicate(char line[])
{
	int i = 0;
	int j = i + 1;
	
	while (line[i] != '\0')
	{
		while (line[j] != '\0')
		{
			if (line[i] == line[j])
			{
				//shift array to one element left
				for (int pos = j; line[pos] != '\0'; pos++)
				{
					line[pos] = line[pos + 1];
				}
			}
			else
			{
				j++;
			}
		}
		i++;
		j = i + 1;
	}

	//printf("\nDeduplicated pattern is: \n%s\n", line);
	return;
}