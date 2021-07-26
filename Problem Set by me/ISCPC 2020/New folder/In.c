#include <stdio.h>

int main()
{
    int i, j;

    int h;

    h = 100;

    int space = h - 1;
    int star = 1;

    for(i = 1; i <= h; i++)
    {
        for(j = 1; j <= space; j++)
        {
            printf(" ");
        }

        for(j = 1; j <= star; j++)
        {
            printf("*");
        }

        printf("\n");

        space--;
        star += 2;
    }

    star -= 2;
    space++;

    for(i = 1; i <= h; i++)
    {
        for(j = 1; j <= space; j++)
        {
            printf(" ");
        }

        for(j = 1; j <= star; j++)
        {
            printf("*");
        }

        printf("\n");

        space++;
        star -= 2;
    }
}
