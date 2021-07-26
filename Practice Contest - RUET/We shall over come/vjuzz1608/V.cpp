
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

double calc(double b, double c)
{
    double a, a1, ans;

    a = ((c * c) + (b * b)) / b;
    a1 = asin((c * 2 * b)/((c * c) + (b * b)));

    ans = a * a1;

    return ans;
}

double binary(double c, double L1)
{
    double high, low, mid;

    ll i, j, k , l;

    i = 1;

    low = 0;

    high = L1;

    while(low <= high && i <= 300)
    {
        mid = (high + low) / 2;

        double cal = calc(mid,c);

        //printlf(mid);

        if(cal == L1)
        {
            return mid;
        }
        else if(cal < L1)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }

        i++;
    }

    return mid;
}

int main()
{
    ll i, j, k, l, m, o;
    ll testcase;

    double rad, c, b, angle, L, L1, C, n;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlf(L);
        scanlf(n);
        scanlf(C);

        c = L / 2;

        L1 = L * (1 + (n * C));

        //printlf(L1);
        //bug;

        b = binary(c,L1);

        printf("Case %lld: %lf\n", i, b);
    }


}

