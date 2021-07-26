#include <stdio.h>

int main()
{
    int testcase;

    long long int g, l;

    long long int a, b;

    scanf("%d", &testcase);

    int i;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%lld%lld", &g, &l);

        if(g == 1)
        {
            printf("%lld %lld\n", g, l);
        }
        else if(l % g != 0)
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld %lld\n", g, l);
        }

    }

    return 0;
}
