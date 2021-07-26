#include <stdio.h>

int main()
{
    long long int year, res, i = 0, flag;

    scanf("%lld",&year);

    if(year < 10)
    {
        res = 1;
    }
    else
    {
        flag = year;
        while(flag >= 10)
        {
            flag = flag / 10;
            i = i + 1;
        }

        flag = flag + 1;

        while(i != 0)
        {
            flag = flag * 10;
            i = i - 1;
        }

        res = flag - year;
    }

    printf("%lld\n", res);

    return 0;
}
