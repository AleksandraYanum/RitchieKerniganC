#include <stdio.h>
#include <stdlib.h>

/*
Program returns the first location in the string s1 where any character from the string s2 occurs,
or-1 if s1 contains no characters from s2
*/


//###########################################################################
// functions
// ###########################################################################

int any(const char source[], const char pattern[]);
int any_test(const char source[], const char pattern[], int expected_pos);


int main()
{
	int test_result = 0;

	test_result = any_test("aleksandra yanum", "knky", 3);
	printf("Test1 %s \n", test_result == 1 ? "passed" : "failed");

	test_result = any_test("", "knky", -1);
	printf("Test2 %s \n", test_result == 1 ? "passed" : "failed");

	test_result = any_test("vlad yanum", "", -1);
	printf("Test3 %s \n", test_result == 1 ? "passed" : "failed");

	test_result = any_test("", "", -1);
	printf("Test4 %s \n", test_result == 1 ? "passed" : "failed");

	test_result = any_test("qwetyqwerty", "rt", 3);
	printf("Test5 %s \n", test_result == 1 ? "passed" : "failed");

	test_result = any_test("aleksandra", "bmw", -1);
	printf("Test6 %s \n", test_result == 1 ? "passed" : "failed");

	return EXIT_SUCCESS;
}


int any(const char source[], const char pattern[])
{

	return -99;
}


int any_test(const char source[], const char pattern[], int expected_pos)
{
	int actual_pos = any(source, pattern);
	int result = (actual_pos == expected_pos);
	return result;
}