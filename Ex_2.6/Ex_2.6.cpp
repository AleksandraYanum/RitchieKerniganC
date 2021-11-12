#include <stdio.h>
#include <stdlib.h>

/*
Program returns target_number with the bit_amount bits that begin at position pos_from set to the 
rightmost bit_amount bits of source_number, leaving the otherbits unchanged: 
setbits(target_number, pos_from, bit_amount, source_number)
*/

//###########################################################################
// functions
// ###########################################################################

unsigned long setbits(unsigned long target_number, int pos_from, int bit_amount, unsigned long source_number);

// ###########################################################################

int main()
{
	unsigned long target_number = 0b10110101;
	int bit_amount = 4;
	int pos_from = 6;
	unsigned long source_number = 0b11000111;
	unsigned long result_number = 0;

	result_number = setbits(target_number, pos_from, bit_amount, source_number);
	printf("%d", result_number);
	return EXIT_SUCCESS;
}


unsigned long setbits(unsigned long target_number, int pos_from, int bit_amount, unsigned long source_number)
{
	unsigned long part_before_pos = 0;
	unsigned long part_after_pos = 0;

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