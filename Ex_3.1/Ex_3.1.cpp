#include <stdio.h>
#include <stdlib.h>


//binsearch: find 'number' in array and return its pos else -1

# define SIZE 11

int binsearch(int number, int array[], int amount);


int main()
{
	int pos = 0;
	int number = 6;
	int array[SIZE] = { 1, 3, 6, 8, 10, 12, 15, 16, 18, 20, 21 };

	pos = binsearch(number, array, SIZE);
	printf("Number position is %d", pos);

	return EXIT_SUCCESS;
}


int binsearch(int number, int array[], int amount)
{
	int low_pos = 0;
	int high_pos = amount - 1;
	int mid = 0;
	int number_pos = -1;

	while ((low_pos <= high_pos) && (number_pos == -1))
	{
		mid = (low_pos + high_pos) / 2;
		if (number < array[mid])
		{
			high_pos = mid - 1;
		}
		else if (number > array[mid])
		{
			low_pos = mid + 1;
		}
		else
		{
			number_pos = mid;
		}
	}

	return number_pos;
}