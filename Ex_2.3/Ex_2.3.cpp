#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Program converts hexadecimal digits from string to integer value

#define MAXSIZE 100
#define IN 1
#define OUT 0

// ###########################################################################
// functions
// ###########################################################################

long int htoi(char s[]);
int is_hexadecimal(char c);
int is_new_hex_digit(char s[]);

// ###########################################################################
// global variables
// ###########################################################################

int pos = -1;

// ###########################################################################

int main()
{
	long int n = 0;
	char string[MAXSIZE] = "0X1F--";
	
	n = htoi(string);

	printf("Integer equivalent is %ld", n);
	
	return EXIT_SUCCESS;
}


long int htoi(char s[])
{
	int hex = 0;
	long int number = 0;

	if (is_new_hex_digit(s))
	{
		for (int i = pos; is_hexadecimal(s[i]); i++)
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

int is_new_hex_digit(char s[])
{
	char prev_symb = 0;
	int result = 0;
	
	for (int i = 0; (s[i] != '\0') && (result == 0); i++)
	{
		if ((s[i] == 'x' || s[i] == 'X') && (prev_symb == '0'))
		{
			result = 1;
			pos = i + 1;
		}
		prev_symb = s[i];
	}
	return result;
}