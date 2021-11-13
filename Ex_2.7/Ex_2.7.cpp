#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 33 //size of array that will turned in binary numaber, 33 is to int value
enum boolean { NO, YES };

/*
Program returns target_number with the bit_amount bits that begin at position pos_from inverted 
(i.e., 1 changed into 0 and vice versa), leaving the others unchanged. 
*/

//###########################################################################
// functions
// ###########################################################################

int getline(char s[], int lim);
unsigned int bintoi(char s[]);
unsigned int invert(unsigned int target_number, int pos_from, int bit_amount);
void print_bit(unsigned int number, int print_leading_zeroes);
unsigned int invert_test(unsigned int target_number, int pos_from, int bit_amount, unsigned int expected_target_number);

// ###########################################################################

int main()
{
	char target_number_arr[MAXSIZE];
	unsigned int target_number = 0; 
	int bit_amount = 0;
	int pos_from = -1;
	unsigned int result_number = 0;
	int test_result = 0;

	test_result = invert_test(0b10110101, 4, 3, 0b10101001);
	printf("Test1 %s \n", test_result == 1 ? "passed" : "failed");
	
	test_result = invert_test(0b11000101111, 10, 7, 0b00111011111);
	printf("Test1 %s \n", test_result == 1 ? "passed" : "failed");

	printf("\nInput target number in binary view (0 and 1 only):\n");
	getline(target_number_arr, MAXSIZE);
	target_number = bintoi(target_number_arr);

	printf("\nInput an amount of bits:\n");
	scanf_s("%d", &bit_amount);

	printf("\nInput the position in target number:\n");
	scanf_s("%d", &pos_from);

	result_number = invert(target_number, pos_from, bit_amount);
	print_bit(result_number, NO);
	
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


unsigned int bintoi(char s[])
{
	int number = 0;
	for (int i = 0; s[i] >= '0' && s[i] <= '1'; i++)
	{
		number = (number << 1) + (s[i] - '0'); //(number << 1) - fast equivalent of (number * 2)
	}
	return number;
}


unsigned int invert(unsigned int target_number, int pos_from, int bit_amount)
{
	unsigned int mask = 0;

	mask = ~(~0u << bit_amount) << (pos_from + 1 - bit_amount);
	target_number = target_number ^ mask;
	return target_number;
}


void print_bit(unsigned int number, int print_leading_zeroes) //if print_leading_zeroes = 1 - print insignificant zeroes
{
	unsigned int mask = 0;
	unsigned int number_and_mask = 0;
	int is_bit_insignificant = YES;

	printf("\nBin number = ");
	mask = ~(~0u >> 1);	//for ex mask = 1000..00

	is_bit_insignificant = (print_leading_zeroes == 0) ? YES : NO;
	for (int i = 0; i < sizeof(number) * 8; i++)
	{
		number_and_mask = number & mask;
		if (number_and_mask == 0)
		{
			if (is_bit_insignificant == NO)
			{
				putchar('0');
			}
		}
		else
		{
			putchar('1');
			is_bit_insignificant = NO;
		}
		//putchar((number_and_mask == 0) ? '0' : '1');
		mask = mask >> 1;	//shift 1 in mask to one pos right
	}
	return;
}


unsigned int invert_test(unsigned int target_number, int pos_from, int bit_amount, unsigned int expected_target_number)
{
	unsigned int actual_target_number = invert(target_number, pos_from, bit_amount);
	unsigned int result = (actual_target_number == expected_target_number);
	return result;
}