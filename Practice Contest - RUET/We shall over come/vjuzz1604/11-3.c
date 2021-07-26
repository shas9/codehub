#include <stdio.h>

int main()
{
    int testcase;

    long long int n, m, res, sq, div;

    int i;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%lld%lld", &n, &m);

        sq = m * m;

        div = n / (2 * m);

        res = div * sq;

        printf("Case %d: %lld\n", i, res);

    }

    return 0;
}
