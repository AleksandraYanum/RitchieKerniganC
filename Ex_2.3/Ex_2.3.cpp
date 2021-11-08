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
int is_new_hex_digit(char s[]);

// ###########################################################################

int main()
{
	long int htoi_result = -1;
	char string[MAXSIZE] = "0xzwFF--";
	
	htoi_result = htoi(string);
	
	if (htoi_result > -1)
	{
		printf("Integer equivalent is %ld", htoi_result);
	}
	else
	{
		printf("Value is not a hexadecimal");
	}

	
	return EXIT_SUCCESS;
}


long int htoi(char s[])
{
	int hex = 0;
	long int number = 0;
	int pos = -1;

	if ((pos = is_new_hex_digit(s)) > -1)
	{
		for (int i = pos; is_hexadecimal(s[i]); i++)
		{
			if (isdigit(s[i]))
			{
				hex = s[i] - '0';
			}
			else if (s[i] >= 'A' && s[i] <= 'F')
			{
				hex = s[i] - 'A' + 10;
			}
			else if (s[i] >= 'a' && s[i] <= 'f')
			{
				hex = s[i] - 'a' + 10;
			}
			number = 16 * number + hex;
		}
	}
	else
	{
		number = -1;
	}
	return number;
}


int is_hexadecimal(char c)
{
	int result =	(c >= '0' && c <= '9') ||
					(c >= 'A' && c <= 'F') ||
					(c >= 'a' && c <= 'f');
	
	return result;
}

int is_new_hex_digit(char s[])
{
	char prev_symb = '\0';
	int pos = -1;

	for (int i = 0; (s[i] != '\0') && (pos == -1); i++)
	{
		if ((s[i] == 'x' || s[i] == 'X') && (prev_symb == '0'))
		{
			pos = i + 1;
		}
		prev_symb = s[i];
	}
	return pos;
}