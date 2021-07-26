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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

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

    ll v1, v2, v3, v4;

    flag = 0;

    slld(v1);
    slld(v2);
    slld(v3);
    slld(v4);

    ll c3 = max(v4, v3);
    if (c3 > 2 * v3 or c3 > 2 * v4)
    {
        cout << -1 << endl;
        return 0;
    }

    ll c2 = max(c3 + 1, max(2 * v4 + 1, v2));
    if (c2 > 2 * v2)
    {
        cout << -1 << endl;
        return 0;
    }

    ll c1 = max(c2 + 1, max(2 * v4 + 1, v1));
    if (c1 > 2 * v1)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << c1 << endl << c2 << endl << c3 << endl;


}


