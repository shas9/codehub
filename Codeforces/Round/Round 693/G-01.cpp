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

vector < ll > g[200005], g1[200005], g2[200005];
ll d[200005];
vector < pll > ed;
ll ans[200005];

void dfs(ll node, ll dist)
{
	queue < ll > q;
	q.push(1);
	d[1] = 0;

	while(!q.empty())
	{
		ll top = q.front();
		q.pop();


		for(auto it: g[top])
		{
			if(d[it] == -1)
			{
				q.push(it);
				d[it] = d[top] + 1;
			}
		}
	}

	return;
}

void process()
{
	for(auto it: ed)
	{
		if(d[it.first] < d[it.second]) g1[it.first].pb(it.second);
		else g2[it.first].pb(it.second);
	}
}

ll solve(ll node)
{
	if(ans[node] != mxlld) return ans[node];

	ans[node] = d[node];

	for(auto it: g2[node])
	{
		ans[node] = min(ans[node], d[it]);
	}

	for(auto it: g1[node])
	{
		ans[node] = min(ans[node], solve(it));
	}

	return ans[node];
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
			g[i].clear();
			g1[i].clear();
			g2[i].clear();
			d[i] = -1;
			ans[i] = mxlld;
			ed.clear();
		}

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;
			cin >> u >> v;
			g[u].pb(v);
			ed.push_back({u,v});
		}

		dfs(1,0);
		process();

//		for(auto it: g1[3]) cout << it << " * ";
//		cout << " = " << g2[3].size() << "\n";
//
//		cout << d[3] << " " << d[4] << '\n';

		for(ll i = 1; i <= n; i++) cout << solve(i) << " ";

		cout << "\n";
    }


}



