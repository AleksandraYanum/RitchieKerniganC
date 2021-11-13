#include <stdio.h>
#include <stdlib.h>

//Program returns the value of the int target_number rotated to the right by bit_amount bit positions

//###########################################################################
// functions
// ###########################################################################

unsigned int rightrot(unsigned int number, int bit_amount);
unsigned int rightrot_test(unsigned int number, int bit_amount, unsigned int expected);

// ###########################################################################

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


unsigned int rightrot(unsigned int number, int bit_amount)
{
	unsigned int number_to_left = 0;
	unsigned int number_to_right = 0;
	int type_size = sizeof(number) * 8;

	if (bit_amount != type_size)
	{
		if (bit_amount > type_size)
		{
			bit_amount = bit_amount % type_size;
		}
		number_to_left = number << type_size - bit_amount;
		number_to_right = number >> bit_amount;
		number = number_to_left | number_to_right;
	}
	return number;
}


unsigned int rightrot_test(unsigned int number, int bit_amount, unsigned int expected)
{
	unsigned int actual = rightrot(number, bit_amount);
	unsigned int result = (actual == expected);
	return result;
}