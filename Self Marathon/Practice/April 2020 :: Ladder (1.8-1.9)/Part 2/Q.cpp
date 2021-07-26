#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dp[5005][5005];
vector < ll > portals[5003];
ll a[5003], b[5003], c[5003];
ll last[5003];
ll n, m, k;

ll solve(ll castle, ll soldiers)
{
	if(castle > n) return 0;
	if(soldiers < a[castle]) return mnlld;

	ll &ret = dp[castle][soldiers];

	if(ret != - 1) return ret;

	ret = 0;

	soldiers += b[castle];

	ret = solve(castle + 1, soldiers);

	ll prof = 0;
	ll cnt = 0;
	for(auto it: portals[castle])
	{
		prof += it, cnt++;

		if(soldiers < cnt) break;
		ret = max(ret,solve(castle + 1, soldiers - cnt) + prof);
	}

	return ret;
}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		for(i = 1; i <= n; i++)
		{
			slld(a[i]);
			slld(b[i]);
			slld(c[i]);
			last[i] = i;
		}

		for(i = 1; i <= n; i++) portals[i].clear();

		for(i = 1; i <= m; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			last[v] = max(last[v], u);
		}

		memset(dp,-1,sizeof dp);

		for(i = 1; i <= n; i++) portals[last[i]].pb(c[i]);

		for(i = 1; i <= n; i++)
		{
			sort(portals[i].rbegin(),portals[i].rend());
//			reverse(portals[i].begin(),portals[i].end());
		}

		ans = solve(1,k);

		ans = max(-1LL,ans);

		printf("%lld\n", ans);
    }


}


