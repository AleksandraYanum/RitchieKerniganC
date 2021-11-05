#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

/*
Program determines ranges of char, short, intand long vars, both signedand unsigned,
ranges of floating-point numbers by by printing  appropriatevalues from standard  header
*/

int main()
{
	printf("Ranges of data types from standart headers: \n\n");

	printf("Signed char: min %d, max %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Unsigned char: min %d, max %u\n", 0, UCHAR_MAX);

	printf("Signed int: min %d, max %d\n", INT_MIN, INT_MAX);
	printf("Unsigned int: min %d, max %u\n", 0, UINT_MAX);

	printf("Signed short int: min %d, max %d\n", SHRT_MIN, SHRT_MAX);
	printf("Unsigned short int: min %d, max %u\n", 0, USHRT_MAX);

	printf("Signed long int: min %ld, max %ld\n", LONG_MIN, LONG_MAX);
	printf("Unsigned long int: min %d, max %lu\n", 0, ULONG_MAX);

	printf("Float: min %e, max %e\n", FLT_MIN, FLT_MAX);
	printf("Double: min %e, max %e\n", DBL_MIN, DBL_MAX);
	printf("Long double: min %Le, max %Le\n", LDBL_MIN, LDBL_MAX);

	return EXIT_SUCCESS;
}

