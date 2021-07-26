#include <stdio.h>

int main()
{
    int testcase;

    scanf("%d", &testcase);

    int i, j, k, l, m, count;

    int n;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d", &n);

        j = 5;
        count = 0;

        while(count <= n)
        {
            k = j / 5;

            count++;

            if(k % 5 == 0)
            {
                m = k;
                for(l = 5; l <= m; l= l + 5)
                {
                    count++;
                }
            }
            if(count >= n)
            {
                break;
            }

            j = j + 5;
        }

        if(n == 0)
        {
            j = 1;
            count = 0;
        }

        if(count > n)
        {
            printf("Case %d: impossible\n", i);
        }
        else
        {
            printf("Case %d: %d\n", i, j);
        }

    }
    return 0;
}
