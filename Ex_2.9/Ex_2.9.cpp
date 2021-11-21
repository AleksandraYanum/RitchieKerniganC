#include <stdio.h>
#include <stdlib.h>

//Program counts the number of l-bits in its integer argument

//###########################################################################
// functions
// ###########################################################################

int bitcount(unsigned number);

// ###########################################################################

int main()
{
	unsigned bit_number = 0b1110;
	int bit_count = bitcount(bit_number);
	printf("Number of 1-bits is %d", bit_count);
	
	return EXIT_SUCCESS;
}

int bitcount(unsigned number)
{
	int count = 0;
	for (; number != 0; number &= (number - 1))
	{
		count++;
	}
	return count;
}