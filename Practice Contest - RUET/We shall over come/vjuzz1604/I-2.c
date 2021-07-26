#include <stdio.h>

int main()
{
    int testcase;

    long long int u, v, n, u1, v1;

    int vam, lyk;

    int i, j, k, l, max;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%lld", &n);

        u1 = 0;
        v1 = 0;

        vam = 1;
        lyk = 1;

        for(j = 1; j <= n; j++)
        {
            scanf("%lld%lld", &u, &v);

            if(u == u1 || u == v1)
            {
                vam = vam + 1;
                printf("DBUG vam = %d\n", vam);
            }
            else if(v == u1 || v == v1)
            {
                lyk = lyk + 1;
                printf("DBUG lyk = %d\n", lyk);
            }

            u1 = u;
            v1 = v;

        }
        if(vam >= lyk)
        {
            max = vam;
        }
        else
        {
            max = lyk;
        }

        printf("Case %d: %lld\n", i, max);
    }

    return 0;
}
