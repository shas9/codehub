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

vector < ll > graph[200005];
bool vis[200005];
ll u[500005], v[500005];

ll dfs(ll node)
{
	vis[node] = 1;

	ll ret = 0;
	for(auto it:graph[node])
	{
		if(vis[it] == 0) ret += dfs(it);
	}

	return ret + 1;
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
		ll a, b;

		cin >> n >> m >> a >> b;

		for(i = 1; i <= m; i++)
		{
			slld(u[i]);
			slld(v[i]);
		}

		ans = 1;

		for(i = 1; i <= n; i++) vis[i] = 0, graph[i].clear();

		for(i = 1; i <= m; i++)
		{
			if(u[i] == a || v[i] == a) continue;

			graph[u[i]].pb(v[i]);
			graph[v[i]].pb(u[i]);
		}

		ans *= n - dfs(b) - 1;

		for(i = 1; i <= n; i++) vis[i] = 0, graph[i].clear();

		for(i = 1; i <= m; i++)
		{
			if(u[i] == b || v[i] == b) continue;

			graph[u[i]].pb(v[i]);
			graph[v[i]].pb(u[i]);
		}

		ans *= n - dfs(a) - 1;

		printf("%lld\n", ans);
    }


}



