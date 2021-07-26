#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanlf(longvalue) scanf("%lf", &longvalue)
#define printlf(longvalue) printf("%lf\n", longvalue)

#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")


using namespace std;

double calc(double d, double x, double y)
{
    double a, b, c, e, result;

    a = sqrt((y*y) - (d*d));
    b = sqrt((x*x) - (d*d));

    c = a * b;
    e = a + b;

    result = c / e;

    return result;
}

double binary(double x, double y, double h)
{
    double high, low, mid;

    high = x;
    low = 0;

    ll i = 1;

    while(low <= high && i <= 100)
    {
        mid = (high + low) / 2;
        i++;

        //printlf(mid);

        if(calc(mid, x, y) == h)
        {
            return mid;
        }
        else if(calc(mid, x, y) > h)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    return mid;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;

    scanlld(testcase);

    double x, y, c, ans;

    for(i = 1; i <= testcase; i++)
    {
        scanlf(x);
        scanlf(y);
        scanlf(c);

        ans = binary(x,y,c);

        printf("Case %lld: %lf\n", i, ans);
    }

    return 0;
}

