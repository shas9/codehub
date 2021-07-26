// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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


    ll n;
    ll comp;

    vector < vector < ll > > g, rg;
    vector < ll > compno;
    vector < bool > vis1;
    vector < ll > nodes;

    void init(ll _n)
    {
		n = _n;
		g.assign(n + 10, {});
		rg.assign(n + 10, {});
		comp = 0;
		compno.assign(n + 10, 0);
		vis1.assign(n + 10, 0);
		nodes.clear();
    }

    void dfs1(ll node)
    {
		vis1[node] = 1;

		for(auto it: g[node])
		{
			if(vis1[it] == 0) dfs1(it);
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
			if(vis1[i] == 0) dfs1(i);
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

int main()
{
    ll i, j, k, l, m, nn, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(nn);
		slld(m);

		init(nn);

		for(i = 1; i <= m; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			addedge(u,v);
		}

		vector < ll > a, b;

		start();

//		for(i = 1; i <= n; i++) cout << Scc.compno[i] << " ";
//		cout << endl;

		if(comp == 1) printf("No\n");
		else
		{
			printf("Yes\n");

			for(ll i = 1; i <= n; i++)
			{
				if(compno[i] == comp) a.push_back(i);
				else b.push_back(i);
			}

			cout << a.size() << " " << b.size() << "\n";

			for(auto it: a) cout << it << " ";
			cout << "\n";

			for(auto it: b) cout << it << " ";
			cout << "\n";
		}
    }


}


