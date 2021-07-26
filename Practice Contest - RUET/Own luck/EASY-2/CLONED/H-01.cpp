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

#define printcase(indexing,ans) printf("Case %lld: %.9lf\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    slld(testcase);

    double v, d, s1, s2, t, ans = 0;

    slf(d);
    for(ll cs = 1; cs <= testcase; cs++)
    {

        v = 2;

        double v1 = 0.5;
        double v2 = 1;
        double a1 = 0.25;
        double a2 = 0.5;

        t = d / v;



        ans += d;

        s1 = (v1 * t) - (a1*t*t)/2;
        s2 = (v2 * t) - (a2*t*t)/2;

        d = s1 + s2;

        printcase(cs,d);

        printcase(cs,ans);
    }


}



