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

vector < ll > g[5003];
vector < pll > v1;
vector < bool > vis;

ll solve(ll n)
{
	vis.assign(n,0);
	ll ret = 0;

	for(ll i = 0; i < n; i++)
	{
		for(auto it: g[v1[i].second])
		{
			if(vis[it] == 0)
			{
				ret += v1[i].first;
			}
		}

		vis[v1[i].second] = 1;
	}

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		v1.resize(n);

		for(auto &it: v1) cin >> it.first;

		for(ll i = 0; i <= n; i++) g[i].clear();
		for(ll i = 0; i < n; i++) v1[i].second = i;

		for(ll i = 0; i < m; i++)
		{
			ll u, v;

			cin >> u >> v;

			u--;
			v--;

			g[u].pb(v);
			g[v].pb(u);
		}

		sort(v1.begin(),v1.end());

		ans = solve(n);

		cout << ans << "\n";
    }


}


