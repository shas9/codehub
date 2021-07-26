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

struct SCC
{
    ll n;
    ll comp;

    vector < vector < ll > > g, rg;
    vector < ll > compno;
    vector < bool > vis;
    vector < ll > nodes;
    vector < ll > out, in;

    void init(ll _n)
    {
		n = _n;
		g.assign(n + 10, {});
		rg.assign(n + 10, {});
		comp = 0;
		compno.assign(n + 10, 0);
		vis.assign(n + 10, 0);
		nodes.clear();
		out.assign(n + 10, 0);
		in.assign(n + 10, 0);
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

    ll solve()
    {
		if(comp == 1) return 0;
//		cout << comp << endl;
		for(ll i = 1; i <= n; i++)
		{
			for(auto it: g[i])
			{
				ll u = compno[i];
				ll v = compno[it];
				if(u == v) continue;

				out[u]++;
				in[v]++;
			}
		}

		ll x = 0, y = 0;

		for(ll i = 1; i <= comp; i++)
		{
			if(out[i] == 0) x++;
			if(in[i] == 0) y++;
		}

		return max(x,y);
    }
};

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(m);

		SCC scc;

		scc.init(n);

		for(i = 1; i <= m; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			scc.addedge(u,v);
		}

		scc.start();

		ans = scc.solve();

		printf("Case %lld: %lld\n", cs, ans);
    }

}



