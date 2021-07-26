 // God put a smile upon your face <3

#include <bits/stdc++.h>

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

vector < pll > g[300005];
ll ww[300005];
ll ans;

ll dfs(ll node, ll par)
{
	ll mx1 = 0;
	ll mx2 = 0;

	for(auto it: g[node])
	{
		if(it.first != par)
		{
			ll x = dfs(it.first, node) - it.second;

			if(x > mx1)
			{
				mx2 = mx1;
				mx1 = x;
			}
			else if(x > mx2)
			{
				mx2 = x;
			}
		}
	}

	ans = max(ans, mx1 + mx2 + ww[node]);

	return mx1 + ww[node];
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		ans = 0;

		for(ll i = 1; i <= n; i++)
		{
			slld(ww[i]);

			ans = max(ans, ww[i]);

			g[i].clear();
		}

		for(ll i = 1; i < n; i++)
		{
			ll u, v, c;

			cin >> u >> v >> c;

			g[u].pb({v,c});
			g[v].pb({u,c});

		}

		ans = max(ans, dfs(1,-1));

		cout << ans << "\n";
    }


}


