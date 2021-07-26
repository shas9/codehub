#include <stdio.h>

int main()
{
    long long int fib[5500];

    long long int a = 0, b = 1;

    int i;

    fib[0] = a;
    fib[1] = b;
    for(i = 2; i < 5500; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    int num;

    printf("%lld\n", fib[91] + fib[92]);

     while(scanf("%d", &num) != EOF)
     {
         printf("%lld\n", fib[num]);
     }

     return 0;


}
