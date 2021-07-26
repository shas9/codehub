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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll product[100005];
ll cost[100005];
ll n, m;

bool solve(ll mid)
{
    ll _cost = 0;

    for(ll i = 1; i <= n; i++)
    {
        if(product[i] >= mid) continue;

        if((mid - product[i]) * cost[i] > m) return 0;

        _cost += (mid - product[i]) * cost[i];

        if(_cost > m) return 0;
    }

    return 1;
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        ll lo = mxlld;
        ll hi = 1000000000000;

        ans = 0;

        for(i = 1; i <= n; i++)
        {
            slld(product[i]);
            slld(cost[i]);

            lo = min(lo, product[i]);
        }

        ans = lo;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if(solve(mid))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        cout << ans << endl;


    }


}
