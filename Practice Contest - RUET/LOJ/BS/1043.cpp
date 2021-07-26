#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %.8lf\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;


double ab, ac, bc, rat;

double calc(double x)
{
    double r = x / ab;
    double y = r * ac;
    double z = r * bc;

    double s = (x + y + z) / 2;

    return (double)sqrt(s * (s - x) * (s - y) * (s - z));
}

double bs()
{
    double lo = 0;
    double hi = ab;
    double mid = (lo + hi) / 2;

    double s = ab + bc + ac;
    s /= 2;

    double big = s * (s - ab) * (s - bc) * (s - ac);
    big = (double)sqrt(big);

    double small = (rat/(rat + 1)) * big;

    ll cnt = 10000;

    while(cnt--)
    {
        mid = (lo + hi) / 2;
        if(calc(mid) < small)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }

    return mid;

}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        scanf("%lf%lf%lf%lf", &ab, &ac, &bc, &rat);

        double x = bs();

        printf("Case %lld: %.8f\n", cs, x);
    }


}


