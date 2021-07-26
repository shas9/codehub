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

vector < ll > stones;

int main()
{
    ll i, j, k, l, m, n, o, r, p;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    ll mx;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(r);
        slld(p);

        stones.clear();

        mx = -100;

        flag = 0;

        for(i = 1; i <= n; i++)
        {
            slld(input);

            stones.pb(input);
        }

        stones.pb(r);

        sort(stones.begin(), stones.end());

        mx = max(mx, stones[0]);

        for(i = 1; i <= n; i++)
        {
            mx = max(mx, stones[i] - stones[i-1]);
        }

        ans = max(0LL, mx - p);

        cout << ans << endl;
    }


}


