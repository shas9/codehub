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

const ll tot_nodes = 1e5 + 5;

ll col[tot_nodes];
vector < ll > g[tot_nodes];
ll bigchild[tot_nodes];
bool big[tot_nodes];
vector < pll > qq[tot_nodes];
ll ans[tot_nodes];

ll big_dsu(ll node, ll par)
{
	ll cn = 1, x, mx = 0, bigc = -1;

	for(auto it: g[node])
	{
		if(it != par)
		{
			x = big_dsu(it,node);

			cn += x;

			if(x > mx)
			{
				bigc = it;
				mx = x;
			}
		}
	}

	bigchild[node] = bigc;

	return cn;
}

deque < ll > dq;

void add(ll node, ll par, ll d = 0)
{
	if(dq.size() <= d) dq.push_back((1LL << 60) - 1);

	dq[d] = dq[d] & col[node];

	for(auto it: g[node])
	{
		if(it != par && big[it] == 0)
		{
			add(it, node, d + 1);
		}
	}
}

void dfs(ll node, ll par, bool keep = 1)
{
	for(auto it: g[node])
	{
		if(it != par && it != bigchild[node])
		{
			dfs(it, node, 0);
		}
	}

	if(bigchild[node] != -1)
	{
		dfs(bigchild[node], node, 1);
		big[bigchild[node]] = 1;
	}

	dq.push_front((1LL << 60) - 1);
	add(node, par);

//	cout << node << " ~ " << dq.size() << endl;

	for(auto it: qq[node])
	{
		if(it.first >= dq.size()) ans[it.second] = -1;
		else ans[it.second] = dq[it.first];
	}

	if(bigchild[node] != -1)
	{
		big[bigchild[node]] = 0;
	}

	if(keep == 0)
	{
		dq.clear();
	}
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
		slld(n);
		slld(m);
		slld(r);

		for(i = 0; i <= n; i++) g[i].clear();
		for(i = 0; i <= n; i++) qq[i].clear();
		dq.clear();

		for(ll i = 1; i <= n; i++) slld(col[i]);

		for(ll i = 1; i < n; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			g[u].pb(v);
			g[v].pb(u);
		}

		for(ll i = 1; i <= m; i++)
		{
			ll u, k;

			slld(u);
			slld(k);

			qq[u].push_back({k,i});
		}

		memset(bigchild, -1, sizeof bigchild);

		big_dsu(r,-1);

		dfs(r,-1);

		for(ll i = 1; i <= m; i++) printf("%lld\n", ans[i]);
    }


}



