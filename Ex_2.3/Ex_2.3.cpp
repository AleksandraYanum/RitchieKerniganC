#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Program converts hexadecimal digits from string to integer value

#define MAXSIZE 100

// ###########################################################################
// functions
// ###########################################################################

long int htoi(char s[]);
int is_hexadecimal(char c);

// ###########################################################################

int main()
{
	long int n = 0;
	char string[MAXSIZE] = "123AB---";
	
	n = htoi(string);
	printf("Integer equivalent is %ld", n);
	
	return EXIT_SUCCESS;
}


long int htoi(char s[])
{
	int hex = 0;
	long int number = 0;

	for (int i = 0; is_hexadecimal(s[i]); i++)
	{
		if (isdigit(s[i]))
		{
			hex = s[i] - '0';
		}
		if (s[i] >= 'A' && s[i] <= 'F')
		{
			hex = s[i] - 'A' + 10;
		}
		if (s[i] >= 'a' && s[i] <= 'f')
		{
			hex = s[i] - 'a' + 10;
		}
		number = 16 * number + hex;
	}
	return number;
}


int is_hexadecimal(char c)
{
	int result = 0;
	if ((c >= '0' && c <= '9') ||
		(c >= 'A' && c <= 'F') ||
		(c >= 'a' && c <= 'f'))
	{
			result = 1;
	}
	return result;
}