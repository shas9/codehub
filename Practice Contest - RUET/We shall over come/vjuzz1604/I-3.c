#include <stdio.h>

int main()
{
    int testcase;

    int n;

    int u, v;

    int vam[30000];

    int lyk[30000];

    int i, j;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        for(j = 0; j < 25000; j++)
        {
            vam[j] = 0;
            lyk[j] = 0;
        }

        scanf("%d", &n);


        for(j = 1; j <= n; j++)
        {
            scanf("%d%d", &u, &v);
        }


    }
}
