#include <stdio.h>

int main()
{
    int i, j, k, l, m;
    int sum;

    for(i = 1; i <= 20; i++)
    {
        sum = i;
        for(j = 1; j <= 10; j++)
        {
            printf("%d X %d = %d\n", i, j, sum);
            sum = sum + i;
        }

        printf("\n");
    }

    return 0;
}
