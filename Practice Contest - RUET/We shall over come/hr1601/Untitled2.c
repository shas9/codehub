#include <stdio.h>

int main()
{
    long long int x, y;

    scanf("%lld%lld", &x, &y);

    long long int even, odd, p,;

    for(; x <= y; x++)
    {
        if(x % 2 == 0)
        {
            even = even + x;
        }
        else
        {
            odd = odd + x;
        }
    }

    p = even - odd;

    printf("%lld", p);

    return 0;
}
