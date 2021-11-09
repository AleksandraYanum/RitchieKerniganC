#include <stdio.h>
#include <stdlib.h>

//Program deletes each character in s1 that matches any character in the string s2

#define MAXSIZE 100

// ###########################################################################
// functions
// ###########################################################################

void squeeze(char s1[], char s2[]);

// ###########################################################################

int main()
{
	char main_string[MAXSIZE] = "alexyanum";
	char string_to_delete[MAXSIZE] = "ay";

	squeeze(main_string, string_to_delete);
	printf("Modifyed string is:\n%s\n", main_string);

	return EXIT_SUCCESS;
}


void squeeze(char s1[], char s2[])
{
	int i, j, pos;

	for (j = 0; s2[j] != '\0'; j++)
	{
		for (i = 0; s1[i] != '\0'; i++)
		{
			if (s1[i] == s2[j])
			{
				for (pos = i; s1[pos] != '\0'; pos++)
				{
					s1[pos] = s1[pos + 1];
				}
				i--;
			}
		}
	}

	return;
}