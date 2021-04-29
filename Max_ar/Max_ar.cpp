#include <stdio.h>

# define SIZE 5

int main()
{
    int i, max, k;
    max = k = 0;
    int ar[SIZE];
    for (i = 0; i < SIZE; i++)
    {
        ar[i] = 0;
    }

    //printf("Write numbers: ");
          
    for (i = 0; i < SIZE; i++)
    {
        printf("Write %d number: ", i+1);
        scanf_s ("%d", &ar[i]);
    }
    
   
    for (i = 0; i < SIZE; i++)
    {
        if (ar[i] >= max)
        {
            max = ar[i];
            k = i + 1;
        }
    }
     
    printf("Max number = %d, index = %d", max, k);

   return 0;
}
