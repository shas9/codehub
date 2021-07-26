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
ll cnt[tot_nodes];
ll bigchild[tot_nodes];
bool big[tot_nodes];
ll mark[tot_nodes];
vector < pll > vec[tot_nodes];
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

void add(ll node, ll par)
{
	cnt[col[node]]++;

	mark[cnt[col[node]]]++;

	for(auto it: g[node])
	{
		if(it != par && big[it] == 0)
		{
			add(it, node);
		}
	}
}

void rem(ll node, ll par)
{
	mark[cnt[col[node]]]--;
	cnt[col[node]]--;

	for(auto it: g[node])
	{
		if(it != par && big[it] == 0)
		{
			rem(it, node);
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

	add(node, par);

	for(auto it: vec[node])
	{
//		cout << node << " " << it.second << " " << it.first << " " << mark[it.first] << endl;
		ans[it.second] = mark[it.first];
	}

	if(bigchild[node] != -1)
	{
		big[bigchild[node]] = 0;
	}

	if(keep == 0) rem(node,par);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

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
		ll v, p;

		slld(v);
		slld(p);

		vec[v].pb({p,i});
    }

    memset(bigchild,-1,sizeof bigchild);

    big_dsu(1,-1);

    dfs(1,-1);

    for(ll i = 1; i <= m; i++) printf("%lld\n", ans[i]);


}


