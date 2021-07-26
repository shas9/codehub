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

    ll blue, yellow;

    ll rblue;
    ll ryellow;

    slld(yellow);
    slld(blue);

    slld(i);
    slld(j);
    slld(k);

    rblue = (j * 1) + (k * 3);
    ryellow = (i * 2) + (j * 1);

    ll ans1, ans2;

    ans1 = rblue - blue;

    if(ans1 < 0)
    {
        ans1 = 0;
    }

    ans2 = ryellow -yellow;

    if(ans2 < 0)
    {
        ans2 = 0;
    }

    ans = ans1 + ans2;

    cout << ans << endl;




}

