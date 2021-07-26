#include <stdio.h>

int main()
{
    int testcase;
    long long int input, i, j, k, l;
    long long int prime;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%lld", &input);

        prime = 0;

        for(j = 1; j <= (input / j); j++)
        {
            if(input % j == 0)
            {
                long long int a, b;

                a = j;
                b = input / j;

                int x, y;

                x = 1, y = 1;

                for(k = 2; k <= (a / k); k++)
                {
                    if(a % k == 0)
                    {
                        x = 0;
                    }
                }
                for(l = 2; l <= (b / l); l++)
                {
                    if(b % l == 0)
                    {
                        y = 0;
                    }
                }
                if(x) prime = prime < a ? a : prime;
                if(y) prime = prime < b ? b : prime;
            }
        }
        printf("%lld\n", prime);
    }

    return 0;

}
