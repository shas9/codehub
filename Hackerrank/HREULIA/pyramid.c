#include<stdio.h>

int main()
{
    int i, k, j, row, m;

    read:

    scanf("%d", &k);

    printf("\n\n\n\n");

    row = k - 1;


    for(i = 1; i <= k; i++)
    {
        for(j = row; j >= i; j--)
        {
            printf(" ");
        }
        for(m = 1; m <= ((i * 2) - 1) ; m++)
        {
            printf("*");
        }
        printf("\n");
    }
    goto read;

    return 0;
}
