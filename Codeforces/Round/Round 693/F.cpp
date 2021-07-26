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

vector < ll > g1[200005], g2[200005];
ll dist[200005];
ll ans[200005];

void dfs(ll node, ll d)
{
	if(dist[node] != -1) return;

	dist[node] = d;

	for(auto it: g1[node])
	{
		dfs(it, d + 1);
	}
}

struct info
{
	ll node, par;
};

void bfs(ll n)
{
	queue < info > qq;
	qq.push({1,1});

	ans[1] = 0;

	while(!qq.empty())
	{
		info top = qq.front();
		qq.pop();

		cout << top.node << " " << top.par << " " << top.spar << "\n";

		for(auto it: g2[top.node])
		{
			if(ans[it] != -1) continue;

			ll par =

		}
	}

	for(ll i = 1; i <= n; i++)
	{
		if(ans[i] == -1) ans[i] = dist[i];
	}

	return;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> m;

		for(ll i = 1; i <= n; i++)
		{
			g1[i].clear();
			g2[i].clear();

			dist[i] = -1;
		}

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			cin >> u >> v;

			g1[u].pb(v);
			g2[v].pb(u);
		}

		dfs(1,0);

		for(ll i = 1; i <= n; i++) ans[i] = -1;

		bfs(n);

		for(ll i = 1; i <= n; i++) cout << ans[i] << " ";

		cout << "\n";
    }


}


