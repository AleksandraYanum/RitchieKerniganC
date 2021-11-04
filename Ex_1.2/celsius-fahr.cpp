#include <stdio.h>
/* print C and F temperature (C = from 0 to 50 with step=10)*/
int main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 60;
    celsius = lower;
    step = 10;

    printf("Celsius-Fahreinheit temprature\n\n");
    while (celsius <= upper)
    {
        fahr = 9 * (celsius + 32) / 5;
        printf("\t%d\t%d\n", celsius, fahr);
        celsius = celsius + step;
}
    {
