#include <stdio.h>
/* print F and C temperature*/

int main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    fahr = lower;
    step = 20;

    printf("Fahreinheit-Celsius temprature\n\n");
    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("\t%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}