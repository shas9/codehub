#include <stdio.h>

int main()
{
    int n;

    long long int a =0, b = 1, c;

    int i;

    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)
        {
            c = 0;
            printf("The Fibonacci number for %d is %lld\n", n, c);
        }
        else if(n == 1)
        {
            c = 1;
            printf("The Fibonacci number for %d is %lld\n", n, c);
        }
        else
        {
            a =0, b = 1;
            for(i = 2; i <= n; i++)
            {
                c = a + b;
                a = b;
                b = c;
            }
            printf("The Fibonacci number for %d is %lld\n", n, c);
        }
    }


    return 0;
}
