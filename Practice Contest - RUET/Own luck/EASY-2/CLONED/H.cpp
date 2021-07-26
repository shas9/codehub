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

#define printcase(indexing,ans,ans2) printf("Case %lld: %.9lf %.9lf\n", indexing, ans, ans2)

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

    double v1, v2, v3, a1, a2, t1,t2, s1, s2, d1, d2;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slf(v1);
        slf(v2);
        slf(v3);
        slf(a1);
        slf(a2);

        t1 = v1 / a1;
        t2 = v2 / a2;

        s1 = (v1 * t1) - (a1*t1*t1)/2;
        s2 = (v2 * t2) - (a2*t2*t2)/2;

        d1 = s1 + s2;

        d2 = v3 * max(t1,t2);

        printcase(cs,d1,d2);
    }


}


