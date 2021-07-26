#include <stdio.h>

int main()
{
    long long int m, n;

    int testcase;

    int i, j, k, l;
    long long int sum = 0, sum1;

    int r = 0;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%lld%lld", &n, &m);
        sum = 0;
        j = 1;

        while(j <= n)
        {
            l = j + m - 1;
            r = r + 1;
            sum1 = 0;
            //printf("r = %d\n", r);
            if(r % 2 == 0)
            {
                sum1 = ((l * (l + 1)) - (j * (j - 1))) / 2;
                j = l;
                //printf("DBUG = sum1 = %d\n", sum1);
            }
            else
            {
                sum1 = ((l * (l + 1)) - (j * (j - 1))) / 2;
                j = l;
                sum1 = - sum1;
                //printf("DBUG = sum1 = %d\n", sum1);
            }

            sum = sum + sum1;
            //printf("sum = %d\n", sum);

        }
        printf("Case %d: %lld\n", i, sum);
    }
    return 0;
}
