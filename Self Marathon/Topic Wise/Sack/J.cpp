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

const ll tot_nodes = 1e6 + 5;

ll col[tot_nodes];
vector < ll > g[tot_nodes];
ll cnt[tot_nodes];
ll bigchild[tot_nodes];
bool big[tot_nodes];

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
ll ans[tot_nodes];
ll idx;
ll mx;

void add(ll node, ll par, ll depth = 0)
{
	if(depth >= dq.size()) dq.push_back(0);

	dq[depth]++;

	if(dq[depth] > mx)
	{
		mx = dq[depth];
		idx = depth;
	}
	else if(dq[depth] == mx)
	{
		idx = min(idx,depth);
	}

	for(auto it: g[node])
	{
		if(it != par && big[it] == 0)
		{
			add(it, node, depth + 1);
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

	dq.push_front(0);
	idx++;

	add(node, par);

	ans[node] = idx;

	if(bigchild[node] != -1)
	{
		big[bigchild[node]] = 0;
	}

	if(keep == 0)
	{
		dq.clear();
		idx = -1;
		mx = 0;
	}
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	fastio;

    while(cin >> n)
    {
		idx = -1;
		mx = 0;

		for(ll i = 1; i < n; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			g[u].pb(v);
			g[v].pb(u);
		}

		memset(bigchild,-1,sizeof bigchild);

		big_dsu(1,-1);

		dfs(1,-1);

		for(ll i = 1; i <= n; i++)
		{
			printf("%lld\n", ans[i]);
		}
    }


}


