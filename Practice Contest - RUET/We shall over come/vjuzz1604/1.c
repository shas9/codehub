#include <stdio.h>

int main()
{
    int x;

    scanf("%d", &x);

    int i = 1, j;

    while(i <= x)
    {
        read:
        printf("I hate");

        j = i + 1;

        if(j <= x)
        {
            printf(" that I love");
            i = j + 1;

            if(i <= x)
            {
                printf(" that ");
                goto read;
            }
        }
        else
        {
            printf(" it\n");
            return 0;
        }
    }
    printf(" it\n");
    return 0;
}
