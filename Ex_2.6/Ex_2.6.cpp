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

unsigned int setbits(unsigned int target_number, int pos_from, int bit_amount, unsigned int source_number);

// ###########################################################################

int main()
{
	unsigned int target_number = 0b10110101;
	int bit_amount = 0;
	int pos_from = -1;
	unsigned int source_number = 0b11000111;
	unsigned int result_number = 0;

	setbits(target_number, pos_from, bit_amount, source_number);

	
	
	return EXIT_SUCCESS;
}


unsigned int setbits(unsigned int target_number, int pos_from, int bit_amount, unsigned int source_number)
{
	unsigned int part_before_pos = 0;

	//Mask rightmost bit_amount bits from sourse_number and move it to the pos_from in target_number
	source_number = source_number & ~(~ (unsigned) 0 << bit_amount) << (pos_from + 1 - bit_amount); 

	//Target_number can be represented as: part_before_pos + pos_from + part_after_pos
	//Mask part_before_pos
	part_before_pos = source_number & (~(unsigned)0 << (pos_from + 1));

	return 0;
}