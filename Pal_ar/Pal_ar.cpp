#include <stdio.h>

# define SIZE 5
# define YES 1
#define NO 0

int main()
{
    int i, p;
    p = NO;
    int ar[SIZE];
    for (i = 0; i < SIZE; i++)
    {
        ar[i] = 0;
    }

    //printf("Write numbers: ");

    for (i = 0; i < SIZE; i++)
    {
        printf("Write %d number: ", i + 1);
        scanf_s("%d", &ar[i]);
    }


    for (i = 0; i < (SIZE / 2); i++)
    {
        if (ar[i] == ar[SIZE - i - 1])
        {
            p = YES;
        }
        else (p = NO);
    }
    if (p == YES)
    {
        printf ("This string is a palindrom");
    }
    else
    {
        printf ("This string is not a palindrom");
    }

   

    return 0;
}