#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 33 //size of array that will turned in binary numaber, 33 is to int value

/*
Program returns target_number with the bit_amount bits that begin at position pos_from inverted 
(i.e., 1 changed into 0 and vice versa), leaving the others unchanged. 
*/

//###########################################################################
// functions
// ###########################################################################

int getline(char s[], int lim);
unsigned int bintoi(char s[]);
unsigned int invert(unsigned int target_number, int pos_from, int bit_amount);

// ###########################################################################

int main()
{
	char target_number_arr[MAXSIZE];
	unsigned int target_number = 0; 
	int bit_amount = 0;
	int pos_from = -1;
	unsigned int result_number = 0;

	printf("\nInput target number in binary view (0 and 1 only):\n");
	getline(target_number_arr, MAXSIZE);
	target_number = bintoi(target_number_arr);

	printf("\nInput an amount of bits:\n");
	scanf_s("%d", &bit_amount);

	printf("\nInput the position in target number:\n");
	scanf_s("%d", &pos_from);

	result_number = invert(target_number, pos_from, bit_amount);
	
	return EXIT_SUCCESS;
}


int getline(char s[], int lim)
{
	int i;
	int end_of_line = 0;
	int c;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		s[i] = c;
		end_of_line = i + 1;
	}
	s[end_of_line] = '\0';
	return i;
}


unsigned int bintoi(char s[])
{
	int number = 0;
	for (int i = 0; s[i] >= '0' && s[i] <= '1'; i++)
	{
		number = (number << 1) + (s[i] - '0'); //(number << 1) - fast equivalent of (number * 2)
	}
	return number;
}


unsigned int invert(unsigned int target_number, int pos_from, int bit_amount)
{

	return target_number;
}