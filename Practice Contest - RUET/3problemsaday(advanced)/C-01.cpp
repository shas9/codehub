// God put a smile upon your face <3

#include <bits/stdc++.h>

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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

const ll tot_nodes = 5e5 + 5;

ll val[tot_nodes];
vector < ll > g[tot_nodes];
ll cnt[tot_nodes];
ll bigchild[tot_nodes];
bool big[tot_nodes];
ll depth[tot_nodes];
long long ans;
ll n, m;
bool vis[tot_nodes];

ll big_dsu(ll node, ll par, ll d = 0)
{
//	assert(node >= 1 && node <= n);
//
//	assert(vis[node] == 0);

	vis[node] = 1;
	ll cn = 1, x, mx = 0, bigc = -1;

	depth[node] = d;

//	cout << d << endl;

//	assert(depth[d] <= m);

	for(auto it: g[node])
	{
		if(it != par)
		{
			x = big_dsu(it,node, d + 1);

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

ll add(ll node, ll par, ll jog)
{
	ll ret = 0;
//
//	assert(node >= 1 && node <= n);
//	assert(depth[node] >= 0 && depth[node] <= m);

	cnt[depth[node]] += jog;

	if(cnt[depth[node]] == val[depth[node]] && jog == 1) ret++;

	for(auto it: g[node])
	{
//		assert(it >= 1 && it <= n);
		if(it != par && big[it] == 0)
		{
			ret += add(it, node, jog);
		}
	}

	return ret;
}

ll dfs(ll node, ll par, bool keep = 1)
{
//	assert(node >= 1 && node <= n);

	for(auto it: g[node])
	{
//		assert(it >= 1 && it <= n);
		if(it != par && it != bigchild[node])
		{
			dfs(it, node, 0);
		}
	}

	ll ret = 0;

	if(bigchild[node] != -1)
	{
//		assert(bigchild[node] >= 1 && bigchild[node] <= n);
		ret += dfs(bigchild[node], node, 1);
		big[bigchild[node]] = 1;
	}

	ret += add(node, par, 1);

	ans += ret;

	if(bigchild[node] != -1)
	{
//		assert(bigchild[node] >= 1 && bigchild[node] <= n);
		big[bigchild[node]] = 0;
	}

	if(keep == 0) add(node,par,-1);

	return ret;
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag;

    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    assert(1 <= n && n <= 500000);
    assert(0 <= m && m < n);

    for(ll i = 1; i < n; i++)
    {
		slld(input);

//		assert(input >= 0 && input < n);

		g[input].pb(i);
    }

    ans = 0;

    for(ll i = 0; i <= m; i++)
    {
		slld(val[i]);

		if(val[i] == 0) ans += n;
    }

    big_dsu(0,-1);

    bug;

    dfs(0,-1);

    printf("%lld\n", ans);
}



