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


vector < pll > edge;

struct SCC
{
    ll n;
    ll comp;

    vector < vector < ll > > g, rg;
    vector < ll > compno;
    vector < bool > vis;
    vector < ll > nodes;

    void init(ll _n)
    {
		n = _n;
		g.assign(n + 10, {});
		rg.assign(n + 10, {});
		comp = 0;
		compno.assign(n + 10, 0);
		vis.assign(n + 10, 0);
		nodes.clear();
    }

    void dfs1(ll node)
    {
		vis[node] = 1;

		for(auto it: g[node])
		{
			if(vis[it] == 0) dfs1(it);
		}

		nodes.push_back(node);
    }

    void dfs2(ll node)
    {
		compno[node] = comp;

		for(auto it: rg[node])
		{
			if(compno[it] == 0) dfs2(it);
		}
    }

    void addedge(ll u, ll v)
    {
		g[u].push_back(v);
		rg[v].push_back(u);
    }

    void start()
    {
		for(ll i = 1; i <= n; i++)
		{
			if(vis[i] == 0) dfs1(i);
		}

		reverse(nodes.begin(),nodes.end());

		for(auto it: nodes)
		{
			if(compno[it] == 0)
			{
				comp++;

				dfs2(it);
			}
		}
    }

    void solve()
    {
		start();

		if(comp != n)
		{
			cout << "NO\n";
			return;
		}

		cout << "YES" << "\n";

		for(ll i = 1; i <= n; i++)
		{
			for(auto it: g[i]) cout << i << " " << it << "\n";
		}

		for(auto it: edge)
		{
			if(compno[it.first] < compno[it.second]) cout << it.first << " " << it.second << "\n";
			else cout << it.second << " " << it.first << "\n";
		}
    }

};

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;

	cin >> testcase;

    while(testcase--)
    {
		cin >> n >> m;
		SCC scc;

		scc.init(n);
		edge.clear();

		for(ll i = 1; i <= m; i++)
		{
			ll t, u, v;

			cin >> t >> u >> v;

			if(t == 1) scc.addedge(u,v);
			else edge.push_back({u,v});
		}

		scc.solve();
    }


}



