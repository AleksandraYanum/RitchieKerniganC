#include <stdio.h>
#include <stdlib.h>

//Program returns the value of the int target_number rotated to the right by bit_amount bit positions

//###########################################################################
// functions
// ###########################################################################

unsigned int rightrot(unsigned int target_number, int bit_amount);
unsigned int rightrot_test(unsigned int target_number, int bit_amount, unsigned int expected);

int main()
{
	int test_result = 0;

	test_result = rightrot_test(0b00000000000000000000000011011001, 3, 0b00100000000000000000000000011011);
	printf("Test1 %s \n", test_result == 1 ? "passed" : "failed");

	test_result = rightrot_test(0b101, 32, 0b101);
	printf("Test2 %s \n", test_result == 1 ? "passed" : "failed");

	test_result = rightrot_test(1, 34, 1073741824);
	printf("Test3 %s \n", test_result == 1 ? "passed" : "failed");

	return EXIT_SUCCESS;
}


unsigned int rightrot(unsigned int target_number, int bit_amount)
{

	return 0;
}


unsigned int rightrot_test(unsigned int target_number, int bit_amount, unsigned int expected)
{
	unsigned int actual = rightrot(target_number, bit_amount);
	unsigned int result = (actual == expected);
	return result;
}