#include <stdio.h>
#include <stdlib.h>

/*
Program returns target_number with the bit_amount bits that begin at position pos_from set to the 
rightmost bot_amount bits of source_number, leaving the otherbits unchanged: 
setbits(target_number, pos_from, bit_amount, source_number)
*/

//###########################################################################
// functions
// ###########################################################################

unsigned int setbits(unsigned int target_number, int pos_from, int bit_amount, unsigned int source_number);

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

	return 0;
}