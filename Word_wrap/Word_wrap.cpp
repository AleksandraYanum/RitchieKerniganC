#include <stdio.h>
#include <stdlib.h>

/* 
function takes the word from the global array XXX and limit_position to wrap the word
Returns the top right possible position of word wrap, otherwise -1
Rules:
1. Do not leave just one letter on the line (have at least 2 letters on the line)
2. Each part should contain vowel letter (a, e, u, etc)
3. Wrapping ends with vowel letter (e.g. hello -> he--llo)
*/

# define MAXSIZE 10 //max size of the symbol array

// ###########################################################################
// functions
// ###########################################################################

int find_word_length();
int is_vowel(char symb);

/*
int find_word_wrap_position_v2(const char* str);
int wrap_test_v2(const char* str, int expected_pos);
*/

// ###########################################################################
// global variables
// ###########################################################################

char word[MAXSIZE + 1] = "hello";
char vowels_arr[] = "aeiou";

// ###########################################################################

int main()
{
	/*
	int test1_result = wrap_test_v2("uncle", -1);
	printf("Test1 %s \n", test1_result == 1 ? "passed" : "failed");
	int test2_result = wrap_test_v2("hello", 2);
	printf("Test2 %s \n", test1_result == 1 ? "passed" : "failed");
	*/

	return EXIT_SUCCESS;
}

/*
int find_word_wrap_position_v2(const char* str)
{
	return -99;
}

int wrap_test_v2(const char* str, int expected_pos)
{
	int actual_pos = find_word_wrap_position_v2(str);
	int result = (actual_pos == expected_pos) ? 1 : 0;
	return result;
}
*/


int find_word_length()
{
	int count = 0;
	for (int i = 0; word[i] != '\0'; i++)
	{
		count++;
	}
	return count;
}


int is_vowel(char symb)
{
	int result = 0;
	for (int i = 0; (vowels_arr[i] != '\0') && (result == 0); i++)
	{
		if (symb == vowels_arr[i])
		{
			result = 1;
		}

	}
	return result;
}