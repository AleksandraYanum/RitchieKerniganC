#include <stdio.h>
int main()

/* count spaces, tabs and enters*/
{
    int sp, tab, ent, c;
    sp = tab = ent = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ent++;
        }
        if (c == '\t')
        {
            tab++;
        }
        if (c == ' ')
        {
            sp++;
        }
    }

    printf("Number of enters = %d\n", ent);
    printf("Number of spaces = %d\n", sp);
    printf("Number of tabs = %d\n", tab);

    return 0;
}