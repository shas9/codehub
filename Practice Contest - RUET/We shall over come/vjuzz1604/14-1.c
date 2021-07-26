#include <stdio.h>

int main()
{
    long long int tc, i;

    scanf("%lld", &tc);

    long long int m, n, res, d, x;

    for(i = 1; i <= tc; i++)
    {
        scanf("%lld%lld", &m, &n);

        res = m * n;

        if(m == 1)
        {
            d = n;
        }
        else if(n == 1)
        {
            d = m;
        }
        else if(res <= 4)
        {
            d = res;
        }
        else if(res == 6)
        {
            d = 4;
        }
        else if(m == 2)
        {
            x = n;

            if(x % 4 == 0)
            {
                d = x;
            }
            else if(x % 2 == 0)
            {
                x = x + 2;
                d = x;
            }
            else if((x + 1) % 2 == 0)
            {
                x = x - 1;

                if(x % 4 == 0)
                {
                    d = (x) + 2;
                }
                if(x % 2 == 0)
                {
                    x = x + 2;
                    d = x;
                }
            }
            else if((x - 1) % 4 == 0)
            {
                x = x - 1;

                d = x + 2;
            }
        }
        else if(n == 2)
        {
            x = m;

            if(x % 4 == 0)
            {
                d = x;
            }
            else if(x % 2 == 0)
            {
                x = x + 2;
                d = x;
            }
            else if((x + 1) % 2 == 0)
            {
                x = x - 1;

                if(x % 4 == 0)
                {
                    d = (x) + 2;
                }
                if(x % 2 == 0)
                {
                    x = x + 2;
                    d = x;
                }
            }
            else if((x - 1) % 4 == 0)
            {
                x = x - 1;

                d = x + 2;
            }
        }
        else
        {
            d = res / 2;

            if(res % 2 != 0)
            {
                d = d + 1;
            }
        }



        printf("Case %lld: %lld\n", i, d);

    }

    return 0;


}
