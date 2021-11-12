#include <stdio.h>
#include <stdlib.h>

#define YES 1 //yes - insignificant bit
#define NO 0 
#define MAXSIZE 33 //size of array that will turned in binary numaber, 33 is to int value

/*
Program returns target_number with the bit_amount bits that begin at position pos_from set to the 
rightmost bit_amount bits of source_number, leaving the otherbits unchanged: 
setbits(target_number, pos_from, bit_amount, source_number)
Program works with all unsigned int values (because uses (<< and ~) instead >>)
*/

//###########################################################################
// functions
// ###########################################################################

unsigned int setbits(unsigned int target_number, int pos_from, int bit_amount, unsigned int source_number);
void print_bit(unsigned int number, int print_leading_zeroes);
int getline(char s[], int lim);
unsigned int bintoi(char s[]);

// ###########################################################################

int main()
{
	/*
	unsigned int target_number = 0b10110101;
	int bit_amount = 4;
	int pos_from = 6;
	unsigned int source_number = 0b11000111;
	unsigned int result_number = 0;
	*/

	char source_number_arr[MAXSIZE];
	char target_number_arr[MAXSIZE];
	int bit_amount = 0;
	int pos_from = -1;
	unsigned int result_number = 0;
	unsigned int target_number = 0; //0b10110101;
	unsigned int source_number = 0; //0b11000111;

	printf("Program returns target_number with the bit_amount bits that begin at position pos_from set to the rightmost bit_amount bits of source_number, leaving the otherbits unchanged.\nFor input use no more than %d symbols:\n", (MAXSIZE - 1));
	printf("\nInput target number in binary view (0 and 1 only):\n");
	getline(target_number_arr, MAXSIZE);
	target_number = bintoi(target_number_arr);

	printf("\nInput source number in binary view (0 and 1 only):\n");
	getline(source_number_arr, MAXSIZE);
	source_number = bintoi(source_number_arr);

	printf("\nInput an amount of bits:\n");
	scanf_s("%d", &bit_amount);

	printf("\nInput the position in target number:\n");
	scanf_s("%d", &pos_from);

	result_number = setbits(target_number, pos_from, bit_amount, source_number);
	print_bit(result_number, NO);

	return EXIT_SUCCESS;
}


unsigned int setbits(unsigned int target_number, int pos_from, int bit_amount, unsigned int source_number)
{
	unsigned int part_before_pos = 0;
	unsigned int part_after_pos = 0;

	//Mask rightmost bit_amount bits from sourse_number and move it to the pos_from in target_number
	source_number = (source_number & ~(~ 0u << bit_amount)) << (pos_from + 1 - bit_amount);
	//printf("%d", source_number);

	//Target_number can be represented as: part_before_pos + pos_from + part_after_pos
	//Mask part_before_pos
	part_before_pos = target_number & (~ 0u << (pos_from + 1));
	
	//Mask part_after_pos
	part_after_pos = target_number & ~(~ 0u << (pos_from + 1 - bit_amount));

	//Set to one in target_number bits that are set to one in part_before_pos, part_after_pos and source_number
	target_number = part_before_pos | part_after_pos | source_number;

	return target_number;
}


void print_bit(unsigned int number, int print_leading_zeroes) //if print_leading_zeroes = 1 - print insignificant zeroes
{
	unsigned int mask = 0;
	unsigned int number_and_mask = 0;
	int is_bit_insignificant = YES;

	printf("Bin number = ");
	mask = ~(~ 0u >> 1);	//for ex mask = 1000..00

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


unsigned int bintoi (char s[])
{
	int number = 0;
	for (int i = 0; s[i] >= '0' && s[i] <= '1'; i++)
	{
		number = 2 * number + (s[i] - '0');
	}

	return number;
}