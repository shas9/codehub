#include <stdio.h>

int main()
{
    int testcase, i;

    scanf("%d", &testcase);

    int m, n;

    int res, D;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d%d", &m, &n);

        res = m * n;

        if(m == 1)
        {
            D = n;
        }
        else if(n == 1)
        {
            D = m;
        }
        else if(res <= 4)
        {
            D = res;
        }
        else if(res = 6)
        {
            D = 4;
        }

        else if(res % 2 == 0)
        {
            D = res / 2;
        }
        else
        {
            D = (res / 2) + 1;
        }

        printf("Case %d: %d\n", i, D);
    }
    return 0;
}
