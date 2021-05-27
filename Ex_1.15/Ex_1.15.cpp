#include <stdio.h>
/* print C and F temperature (C = from 0 to 50 with step=10)*/

int cels2fahr(int celsius);

int main()

{
    int celsius;
    int lower, upper, step;

    lower = 0;
    upper = 50;
    celsius = lower;
    step = 10;

    printf("Celsius-Fahreinheit temprature\n\n");
    while (celsius <= upper)
    {
        //fahr = 9 * (celsius + 32) / 5;

        printf("\t%d\t%d\n", celsius, cels2fahr (celsius));
        celsius = celsius + step;
    }
}

int cels2fahr (int celsius)
{
    int result = 0;
    result = 9 * (celsius + 32) / 5;
    return result;
}