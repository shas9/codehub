#include <stdio.h>

int main()
{
    long long int m, n, a;

    scanf("%lld%lld%lld", &m, &n, &a);

    long long int sum1, sum2, sum, x, y;

    x = m % a;
    y = n % a;

    sum1 = m / a;
    sum2 = n / a;

    if(x != 0 && y != 0)
    {
        sum1++;
        sum2++;
    }
    else if(x == 0 && y == 0)
    {
        sum1 = sum1;
        sum2 = sum2;
    }
    else if(x == 0)
    {
        //sum1++;
        sum2++;
    }
    else if(y == 0)
    {
        sum1++;
        //sum2++;
    }


    sum = sum1 * sum2;

    printf("%lld\n", sum);

    return 0;
}
