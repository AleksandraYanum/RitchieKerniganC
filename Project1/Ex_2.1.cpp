#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

//

int main()
{
	printf("Ranges of data types from standart headers: \n\n");

	printf("Signed char: min %d, max %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Unsigned char: min %d, max %d\n", 0, UCHAR_MAX);
	return EXIT_SUCCESS;
}

