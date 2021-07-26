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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll dp[22][1005][3];
ll n, m;
ll seal[22];
ll cost[22][22];
ll power[22][22];

ll solve(ll badge, ll mon, ll on)
{
    if(badge > n) return 0;

    ll &res = dp[badge][mon][on];
    if(res != -1) return res;

    ll way1, way2;

    way1 = solve(badge + 1, mon, 0);

    way2 = 0;

    if(on == 0 && seal[badge] <= mon)
    {
        mon -= seal[badge];

        for(ll i = 1; i <= m; i++)
        {
            if(mon >= cost[badge][i])
            way2 = max(way2, solve(badge, mon - cost[badge][i], 1) + power[badge][i]);
        }
    }
    else if(on)
    {
        for(ll i = 1; i <= m; i++)
        {
            if(mon >= cost[badge][i])
            way2 = max(way2, solve(badge, mon - cost[badge][i], 1) + power[badge][i]);
        }
    }

    return res = max(way1,way2);
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
        memset(dp,-1,sizeof dp);

        slld(n);
        slld(m);
        slld(k);

        for(i = 1; i <= n; i++) slld(seal[i]);

        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                slld(cost[i][j]);

        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                slld(power[i][j]);

        ans = solve(1,k,0);

        plld(ans);


    }


}


