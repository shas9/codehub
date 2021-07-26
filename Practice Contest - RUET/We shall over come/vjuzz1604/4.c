
#include <stdio.h>

int main()
{
    long long int a, b, c;

    long long int res;

    //read:

    scanf("%lld%lld%lld", &a, &b, &c);

    if(c > (a + b))
    {
        res = ((a + b) * 2);
    }
    else if(c <= (a + b))
    {
        if(b > (a + c))
        {
            res = ((a + c) * 2);
        }
        else if(a > (b + c))
        {
            res = ((b + c) * 2);
        }
        else
        {
            res = a + b + c;
        }
    }

    printf("%lld\n", res);

    //goto read;

    return 0;

}
