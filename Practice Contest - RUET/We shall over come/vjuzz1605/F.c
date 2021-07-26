#include <stdio.h>

int main()
{
    int n;

    long long int g = 0;

    int i, j;

    int a, b, c;

    while(1)
    {
        scanf("%d", &n);
        g = 0;
        if(n == 0)
        {
            return 0;
        }
        for(i = 1; i < n; i++)
        {
            for(j = i + 1; j <= n; j++)
            {
                a = i;
                b = j;
                while ( a!= 0)
                    {
                        c = b;
                        b = a;
                        a = c % a;
                    }
                g = g + b;
            }
        }

    printf("%lld\n", g);
    }

    return 0;
}
