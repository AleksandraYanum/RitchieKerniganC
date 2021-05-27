#include <stdio.h>

/* New function "power" (raises "base" to a degree "n"*/
#define N 5

int power (int base, int n)
{
	int i, result;
	result = 1;
	for (i = 1; i <= n; i++)
	{
		result = result * base;
	}
	return result;
}

int main()
	{
		int i;
		for (i = 1; i <= N; i++)
			{ 
				printf("%d %d %d\n", i, power(2, i), power(4, i));
			}
		return 0;
	}

