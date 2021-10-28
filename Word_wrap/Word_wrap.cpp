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

// ###########################################################################
// functions
// ###########################################################################

/*
int find_word_wrap_position_v2(const char* str);
int wrap_test_v2(const char* str, int expected_pos);
*/

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