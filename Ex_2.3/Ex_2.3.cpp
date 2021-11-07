#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Program converts hexadecimal digits from string to integer value

#define MAXSIZE 100

// ###########################################################################
// functions
// ###########################################################################

long int htoi(char s[]);

// ###########################################################################

int main()
{

	char string[MAXSIZE] = "123AB";
	char c; 
	int hex = 0;
	long int number = 0;

	for (int i = 0; string[i] != '\0'; i++)
	{
		if (isdigit(string[i]))
		{
			hex = string[i] - '0';
		}
		if (string[i] >= 'A' && string[i] <= 'F')
		{
			hex = string[i] - 'A' + 10;
		}
		if (string[i] >= 'a' && string[i] <= 'f')
		{
			hex = string[i] - 'a' + 10;
		}
		number = 16 * number + hex;
	}

	printf("Integer equivalent is %ld", number);
	
	return EXIT_SUCCESS;
}


long int htoi(char s[])
{
	return 0;
}
