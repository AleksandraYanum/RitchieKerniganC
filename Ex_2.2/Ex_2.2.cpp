#include <stdio.h>
#include <stdlib.h>

/*
Loop equivalent for

for (i = 0; i < lim-1 && (ñ = getchar()) != EOF && ñ != '\n'; ++i)
 s[i] = c;

 without operators && and ||
*/

# define LIM 10

int main()
{
	char c;
	char s[LIM];

	for (int i = 0; i < LIM - 1; i++)
	{
		if ((c = getchar()) != EOF)
		{
			if (c != '\n')
			{
				s[i] = c;
			}
		}

	}

	return EXIT_SUCCESS;
}


