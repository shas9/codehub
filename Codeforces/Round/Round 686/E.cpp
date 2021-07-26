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

vector < ll > g[200005];
bool vis[200005];
vector < ll > circle;
map < ll, bool > mp;

void clr(ll n)
{
	for(ll i = 1; i <= n; i++) vis[i] = 0;
}

ll dfs(ll node, ll par)
{
	if(vis[node]) return node;

	vis[node] = 1;

	for(auto it: g[node])
	{
		if(it != par)
		{
			ll x = dfs(it,node);

			if(x) return x;
		}
	}

	return 0;
}

bool make_circle(ll node, ll par)
{
	if(vis[node]) return 1;

	vis[node] = 1;

	bool ret = 0;

	for(auto it: g[node])
	{
		if(it != par) ret |= make_circle(it, node);
	}

	if(ret)
	{
		 circle.push_back(node);
		 mp[node] = 1;
	}

	return ret;
}

ll cnt(ll node, ll par)
{
	ll ret = 1;

	for(auto it: g[node])
	{
		if(it != par) ret += cnt(it,node);
	}

	return ret;
}

ll solve(ll n)
{
	ll ret = 0;

	for(auto it: circle)
	{
		vis[it] = 1;
		ll tot = 1;

		for(auto jt: g[it])
		{
			if(mp.find(jt) == mp.end())
			{
				tot += cnt(jt,it);
			}
		}

		n -= tot;

		ret += (tot * (tot - 1)) / 2;
		ret += (tot * n * 2);
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

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n;

		for(ll i = 1; i <= n; i++) g[i].clear();

		clr(n);

		for(ll i = 1; i <= n; i++)
		{
			ll u, v;

			cin >> u >> v;

			if(u > v) swap(u,v);

			g[u].pb(v);
			g[v].pb(u);
		}

		ll node = dfs(1,-1);

		circle.clear();
		mp.clear();

		clr(n);

		make_circle(node,-1);

		assert(circle.size());

		ans = solve(n);

		cout << ans << "\n";
    }


}


