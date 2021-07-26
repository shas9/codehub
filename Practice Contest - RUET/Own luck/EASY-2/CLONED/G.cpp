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
    ll input, flag, tag, ans;

    slld(testcase);

    double r1, r2, r3;
    double h1, h2, h3, area;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slf(r1);
        slf(r2);

        slf(h1);
        slf(h2);

        h3 = (h1 * r2) / (r1 - r2);

        r3 = (r2 / h3) * (h2 + h3);

        area = pi * h2 * (r2*r2 + r2*r3 + r3*r3);

        area /= 3;

        printcase(cs,area);
    }


}


