// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dp[103][103];
vector < pll > g[103];
ll n, m;

ll solve(ll lft, ll rgt)
{
	if(lft > rgt) return 0;

	ll &ret = dp[lft][rgt];

	if(ret != -1) return ret;

	ret = 0;

	for(ll i = lft; i <= rgt; i++)
	{
		ll cnt = 0;

		for(auto it: g[i])
		{
			if(lft <= it.first && it.second <= rgt) cnt++;
		}

		ll ans = (cnt * cnt) + solve(lft, i - 1) + solve(i + 1, rgt);

//		cout << lft << " " << rgt << " " << i << " " << ans << " " << cnt << endl;

		ret = max(ret, ans);
	}

	return ret;
}
int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= m; i++) g[i].clear();

		for(ll i = 1; i <= n; i++)
		{
			slld(input);

			for(ll j = 1; j <= input; j++)
			{
				slld(l);
				slld(r);

				for(ll k = l; k <= r; k++) g[k].pb({l,r});
			}
		}

//		for(ll i = 1; i <= m; i++)
//		{
//			cout << i << ": ";
//			for(auto it: g[i])
//			{
//				cout << it.first << " " << it.second << ", ";
//			}
//			cout << endl;
//		}

		memset(dp,-1,sizeof dp);

		ans = solve(1,m);

		printf("%lld\n", ans);
    }


}


