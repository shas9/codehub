#include <stdio.h>
#include <math.h>

int binary(int x)
{
    int base = 2;
    int nigga = 0;
    int res = 0;

    int a;

    while(x != 0)
    {
        a = x % 10;
        res = res + (a * pow(base, nigga));
        x = x / 10;
        nigga++;
    }
    return res;
}

int main()
{
    long long int a, b, c, d, a1, b1, c1, d1;

    long long int w, x, y, z;

    int testcase;

    scanf("%d", &testcase);

    int i;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%lld.%lld.%lld.%lld", &a, &b, &c, &d);
        scanf("%lld.%lld.%lld.%lld", &w, &x, &y, &z);

        a1 = binary(w);
        b1 = binary(x);
        c1 = binary(y);
        d1 = binary(z);

        if((a == a1) && (b == b1) && (c == c1) && (d == d1))
        {
            printf("Case %d: Yes\n", i);
        }
        else
        {
            printf("Case %d: No\n", i);
        }
    }

    return 0;
}
