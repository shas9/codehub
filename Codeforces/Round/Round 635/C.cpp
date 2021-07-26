#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

pll depth[200005];
vector < ll > graph[200005];
ll subnode[200005];

void dfs(ll node, ll par, ll lev)
{
	depth[node] = {lev,node};
	subnode[node] = 0;

	for(auto it: graph[node])
	{
		if(it == par) continue;

		dfs(it,node,lev + 1);

		subnode[node] += subnode[it];
	}

	subnode[node]++;
}

bool comp(pll a, pll b)
{
	return (a.first - subnode[a.second] + 1) > (b.first - subnode[b.second] + 1);
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	while(cin >> n >> k)
	{
		for(i = 1; i <= n; i++)
		{
			graph[i].clear();
			depth[i] = {-1,i};
		}

		for(i = 1; i < n; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			graph[u].pb(v);
			graph[v].pb(u);
		}

		dfs(1, 0, 0);

		sort(depth + 1, depth + 1 + n, comp);

		ans = 0;

		for(i = 1; i <= k; i++)
		{
			ans += depth[i].first - subnode[depth[i].second] + 1;
		}

		printf("%lld\n", ans);
	}


}



