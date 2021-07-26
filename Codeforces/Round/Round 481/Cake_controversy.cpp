#include <stdio.h>
#include <math.h>
#define slld(a) scanf("%ld",&a)
int main()
{
    long int t, tt, a, b, c;
    slld(t);
    while(t--)
    {
        slld(tt);
        slld(a);
        slld(b);
        slld(c);
        double ans;
        if(tt == 1 || tt == 4) ans = sqrt(a*a + c*c - b*b);
        else if(tt == 2) ans = sqrt(a*a + b*b - c*c);
        else ans = sqrt(b*b + c*c - a*a);
        printf("%.4lf\n", ans);
    }


}


