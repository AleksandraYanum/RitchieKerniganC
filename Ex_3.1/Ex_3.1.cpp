#include <stdio.h>
#include <stdlib.h>

//binsearch: find 'number' in array and return its pos else -1

int binsearch(int number, int array[], int amount);


int main()
{
	int pos = 0;
	int number = 6;
	int array[] = { 1, 3, 6, 8, 10, 12, 15, 14, 15, 20, 21 };
	int amount = 11;

	pos = binsearch(number, array, amount);

	return EXIT_SUCCESS;
}


int binsearch(int number, int array[], int amount)
{
	int low_pos = 0;
	int high_pos = amount - 1;
	int mid = 0;

	return 0;
}