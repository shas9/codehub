#include <stdio.h>

int main()
{
    int testcase;

    scanf("%d", &testcase);

    long long int i, count;

    long long int a, b;

    for(i = 1; i <= testcase; i++)
    {
        count = 0;
        scanf("%lld%lld", &a, &b);


        if((a == 1) && (b == 1))
        {
            count = 0;
        }
        else if(a == b)
        {
            if(a % 3 == 0 || (a + 1) % 3 == 0)
            {
                count = 1;
            }
            else
            {
                count = 0;
            }
        }

        else if(a < 3 && b < 3)
        {
            count = 1;
        }
        else if((a % 3 == 0) && (b % 3 == 0))
        {
            count = (((b - a) / 3) * 2) + 1;
        }
        else if((a % 3 == 0) && ((b + 1) % 3 == 0))
        {
            count = (((b + 1 - a) / 3) * 2);
        }
        else if(((a + 1) % 3 == 0) && (b % 3 == 0))
        {
            count = (((b - a + 1) / 3) * 2) + 2;
        }
        else if(((a + 1) % 3 == 0) && ((b + 1) % 3 == 0))
        {
            count = (((b - a) / 3) * 2) + 1;
        }
        else if(b % 3 == 0)
        {
            a = a + 1;
            count = (((b - a + 1) / 3) * 2) + 2;
        }
        else if(a % 3 == 0)
        {
            b = b - 1;
            count = (((b - a) / 3) * 2) + 1;
        }
        else if((b + 1) % 3 == 0)
        {
            a = a + 1;
            count = (((b - a) / 3) * 2) + 1;
        }
        else if((a + 1) % 3 == 0)
        {
            b = b - 1;
            count = (((b - a + 1) / 3) * 2) + 2;
        }
        else
        {
            a = a + 1;
            b = b - 1;

            count = (((b - a + 1) / 3) * 2) + 2;
        }

        printf("Case %lld: %lld\n", i, count);
    }
    return 0;
}
