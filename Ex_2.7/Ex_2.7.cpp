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

// ###########################################################################

int main()
{
	char target_number_arr[MAXSIZE];
	unsigned int target_number = 0; 

	printf("\nInput target number in binary view (0 and 1 only):\n");
	getline(target_number_arr, MAXSIZE);
	

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
