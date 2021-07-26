#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    int i;

    int x, y, z, sum;

    int count = 0;

    for(i = 0; i < n; i++)
    {
        scanf("%d%d%d", &x, &y, &z);

        sum = x + y + z;

        //printf("DBUG SUM = %d\n", sum);

        if(sum >= 2)
        {
            count = count + 1;
            //printf("DBUG COUNT %d\n", count);
        }
    }

    printf("%d\n", count);

    return 0;
}
