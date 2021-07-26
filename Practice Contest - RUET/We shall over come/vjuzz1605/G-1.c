#include <stdio.h>

long long int abs(long long int n)
{
    if(n < 0)
    {
        n = -n;
    }
    else
    {
        n = n;
    }

    return n;
}
int main()
{
    long long int input[1000];

    long long int i, j, k = 1;

    long long int ln;

    long long int res, resov, ans;
    long long int min;

    while(1)
    {
        for(i = 0; i < 1000; i++)
        {
            scanf("%lld", &input[i]);

            if(input[i] == 0)
            {
                break;
            }
        }

        ln = i;

        if(input[0] == 0)
        {
            return 0;
        }

        min = abs(input[0]);

        for(i = 0; i < ln; i++)
        {
            if(abs(input[i]) > min)
            {
                min = abs(input[i]);
            }
        }

        for(i = min; i >= 2; i--)
        {
            resov = input[0] % i;
            if(resov < 0)
            {
                resov = resov + i;
            }
            for(j = 1; j < ln; j++)
            {
                res = input[j] % i;

                if(res < 0)
                {
                    res = res + i;
                }
                if(res != resov)
                {
                    break;
                }
            }
            if(j == ln)
            {
                ans = i;
                break;
            }
        }
        if(i == 1)
        {
            ans = 1;
        }

        if(ln == 2)
        {
            if((input[0] < 0 && input[1] > 0) || (input[1] < 0 && input[0] > 0))
            {
                ans = abs(input[0]) + abs(input[1]);
            }
        }

        printf("%lld\n", ans);
    }
}
