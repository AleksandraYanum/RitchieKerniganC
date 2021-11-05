#include <stdio.h>
#include <stdlib.h>

/*
Loop equivalent for

for (i = 0; i < lim-1 && (ñ = getchar()) != EOF && ñ != '\n'; ++i)
 s[i] = c;

 without operators && and ||
*/

# define LIM 3

int main()
{
	char c;
	char s[LIM];
	int not_loop_exit = 1; //if 1 - not loop exit, continue

	for (int i = 0; not_loop_exit; i++)
	{
		not_loop_exit = (i < LIM - 1) && 
					((c = getchar()) != EOF) && 
					(c != '\n');
		
		if (not_loop_exit)
		{
			s[i] = c;
		}
	
	}

	return EXIT_SUCCESS;
}


