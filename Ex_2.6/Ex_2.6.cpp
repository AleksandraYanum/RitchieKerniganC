#include <stdio.h>
#include <stdlib.h>

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
void print_bit(unsigned int number);

// ###########################################################################

int main()
{
	unsigned int target_number = 0b10110101;
	int bit_amount = 4;
	int pos_from = 6;
	unsigned int source_number = 0b11000111;
	unsigned int result_number = 0;

	result_number = setbits(target_number, pos_from, bit_amount, source_number);
	print_bit(result_number);

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


void print_bit(unsigned int number)
{
	unsigned int mask = 0;
	unsigned int number_and_mask = 0;

	printf("Bin number = ");
	mask = ~(~ 0u >> 1);	//for ex mask = 1000..00

	for (int i = 0; i < sizeof(number) * 8; i++)
	{
		number_and_mask = number & mask;
		putchar((number_and_mask == 0) ? '0' : '1');
		mask = mask >> 1;	//shift 1 in mask to one pos right
	}
	return;
}