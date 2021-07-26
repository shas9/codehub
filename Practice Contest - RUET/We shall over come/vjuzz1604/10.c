#include <stdio.h>
#include <math.h>

int main()
{
    double r, x, a, pi;

    pi = 2  * acos(0.0);

    int tc, i;
    scanf("%d", &tc);

    for(i = 1; i <= tc; i++)
    {
        scanf("%lf", &r);

    //r = x / (2 * pi);

    a = 2 * r;

    double res;

    double sq, cir;

    sq = (a * a);

    cir = (pi * r * r);

    res = sq - cir;

    printf("Case %d: %.2lf\n", i, res);
    }

    return 0;
}
