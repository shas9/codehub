#include <stdio.h>

int main()
{
    int testcase;

    long long int w;

    scanf("%d", &testcase);

    long long int n, m, x;

    int i;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%lld", &w);

        if(w % 2 != 0)
        {
            printf("Case %d: Impossible\n", i);
        }
        else
        {
            m = 2;
            while(1)
            {
                if(w % m == 0)
                {
                    x = w / m;
                    if(x % 2 != 0)
                    {
                        n = x;
                        printf("Case %d: %lld %lld\n", i, n, m);
                        break;
                    }
                    else
                    {
                        m = m + 2;
                    }

                }
                else
                {
                    m = m + 2;
                }

                if(m >= (w / 2))
                {
                    printf("Case %d: Impossible\n", i);
                    break;

                }
            }
        }


    }

    return 0;
}
