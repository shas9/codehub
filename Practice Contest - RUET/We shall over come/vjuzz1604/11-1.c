#include <stdio.h>

int main()
{
    int testcase;
    scanf("%d", &testcase);

    long long int n, m;
    int i;
    long long int sum1, sum2, sum, res1, res2, res3, res;
    for(i = 1; i <= testcase; i++)
    {
        scanf("%lld%lld", &n, &m);

        /*int j = m + m;

        sum1 = m * (m + 1) / 2;
        sum2 = ((j * (j + 1) / 2) -  sum1) - (2 * sum1);

        sum1 = - sum1;

        printf("sum1 = %d, sum2 = %d\n", sum1, sum2);*/

        sum = m * m * 2;

        int j = m + m;

        sum1 = m * (m + 1) / 2;
        sum2 = ((j * (j + 1) / 2) -  sum1);
        //printf("sum1 = %lld, sum2 = %lld\n", sum1, sum2);

        res1 = n / (2 * m);

        res1 = res1 - 1;

        long long int k;

        for(k = 1; k <= res1; k++)
        {
            sum1 = (2 * sum1) + sum;
            sum2 = (2 * sum2) + sum;
        }

        //printf("DBUG sum = %lld, sum1 = %lld, sum 2 = %lld\nres1 = %lld, res2 = %lld, res3 = %lld\n", sum, sum1, sum2, res1, res2, res3);

        res = sum2 - sum1;

        printf("Case %d: %lld\n", i, res);

    }
    return 0;
}
