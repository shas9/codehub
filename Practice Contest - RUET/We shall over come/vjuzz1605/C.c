#include <stdio.h>

int main()
{
    int n;

    long long int a =0, b = 1, c;

    int i;

    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
            c = 1;
        }
        else
        {
            a =0, b = 1;
            for(i = 1; i <= n; i++)
            {
                c = a + b;
                a = b;
                b = c;
            }
        }
        printf("%lld\n", c);
    }


    return 0;
}

