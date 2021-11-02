#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

//

int main()
{
	printf("Ranges of data types from standart headers: \n\n");

	printf("Signed char: min %d, max %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Unsigned char: min %d, max %u\n", 0, UCHAR_MAX);

	printf("Signed int: min %d, max %d\n", INT_MIN, INT_MAX);
	printf("Unsigned int: min %d, max %u\n", 0, UINT_MAX);

	return EXIT_SUCCESS;
}

