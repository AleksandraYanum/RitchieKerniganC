#include <stdio.h>
#include <stdlib.h>

/*
Program returns the first location in the string s1 where any character from the string s2 occurs,
or-1 if s1 contains no characters from s2
*/

#define MAXSIZE 101

//###########################################################################
// functions
// ###########################################################################

int getline(char s[], int lim);
int any(const char source[], const char pattern[]);
int any_test(const char source[], const char pattern[], int expected_pos);


int main()
{
	char main_string[MAXSIZE];
	char string_to_find[MAXSIZE];

	/*
	printf("Input main string no longer than %d symbols:\n", (MAXSIZE - 1));
	getline(main_string, MAXSIZE);

	printf("\nInput chars to find in main string:\n");
	getline(string_to_find, MAXSIZE);
	*/

	//any(main_string, string_to_find);

	int test1_result = any_test("aleksandra yanum", "knky", 3);
	printf("Test1 %s \n", test1_result == 1 ? "passed" : "failed");


	return EXIT_SUCCESS;
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


int any(const char source[], const char pattern[])
{

	return 0;
}


int any_test(const char source[], const char pattern[], int expected_pos)
{
	int actual_pos = any(source, pattern);
	int result = (actual_pos == expected_pos);
	return result;
}