#include <stdio.h>

int main()
{
    int u, v;

    int testcase;

    scanf("%d", &testcase);
    int n;

    int i, j, k, l;

    int a[30000];

    int max;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d", &n);

        max = 0;

        for(k = 0; k < 25000; k++)
        {
            a[k] = 0;
        }

        for(j = 1; j <= n; j++)
        {
            scanf("%d%d", &u, &v);

            a[u] = a[u] + 1;
            a[v] = a[v] + 1;
        }

        for(k = 0; k <= 20010; k++)
        {
            if(a[k] == 1)
            {
                //printf("k = %d\n", k);
                max = max + 1;
            }
        }
        printf("Case %d: %d\n", i, max);


    }
    return 0;
}
