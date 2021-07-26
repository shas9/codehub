#include <stdio.h>

int main()
{
    long long int x, y, even, odd, result, diff;

    scanf("%lld%lld", &x, &y);

    if((x % 2 != 0 && y % 2 == 0) || (x % 2 == 0 && y % 2 != 0))
    {
            result = ((y - x) + 1) / 2;
    }
    else if((x % 2 == 0 && y % 2 == 0))
    {
        result = (y + x) / 2;
    }
    else if((x % 2 != 0 && y % 2 != 0))
    {
        result = (y + x) / 2;
    }

    printf("%lld", result);

    return 0;
}

