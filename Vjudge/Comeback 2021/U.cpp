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

vector < ll > g[150004];
vector < bool > vis;

vector < ll > v;

void dfs(ll node)
{
	if(vis[node] == 1) return;

	v.push_back(node);

	vis[node] = 1;

	for(auto it: g[node])
	{
		dfs(it);
	}
}

bool check(ll x)
{
	if(vis[x] == 1) return 1;

	v.clear();

	dfs(x);

	for(auto it: v)
	{
		if(g[it].size() != (v.size() - 1)) return 0;
	}

	return 1;
}

bool solve(ll n)
{
	vis.assign(n + 5,0);

	for(ll i = 1; i <= n; i++)
	{
		if(check(i) == 0) return 0;
	}

	return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++)
		{
			g[i].clear();
		}

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			cin >> u >> v;

			g[u].pb(v);
			g[v].pb(u);
		}

		if(solve(n)) cout << "YES\n";
		else cout << "NO\n";
    }


}


