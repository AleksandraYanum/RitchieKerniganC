#include <stdio.h>

/* replace tab with "\t", space with "\b", backslash with "\\" */

int main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            printf("\\t");
        }
        else
        {
            if (c == ' ')
            {
                printf("\\b");
            }
            else
            {
                if (c == '\\')
                {
                    printf("\\\\");
                }
                else
                {
                    putchar(c);
                }
            }
        }
    }
    return 0;
}
