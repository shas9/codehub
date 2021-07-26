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

vector < ll > graph[200005];
bool vis[200005];
char ans[200005];
ll deg[200005];

bool dfs(ll node, ll par = 0)
{
	vis[node] = 1;
	bool ret = 1;

	for(auto it: graph[node])
	{
		if(it == par) continue;

//		cout << node << " " << it << " " << vis[it] << endl;

		if(vis[it]) return 0;

		ret &= dfs(it,node);
	}

	vis[node] = 0;

	return ret;
}

bool isposs(ll n)
{
	for(ll i = 1; i <= n; i++)
	{
		if(vis[i] == 0)
		{
			bool x = dfs(i);

//			cout << x << endl;

			if(x == 0) return 0;
		}
	}

	return 1;
}

ll solve(ll n)
{
	ll ret = 0;

	for(ll i = 1; i <= n; i++)
	{
		if(deg[i]) ans[i] = 'E';
		else
		{
			ans[i] = 'A';
			ret++;
		}
	}

	ans[n + 1] = '\0';

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(i = 1; i <= n; i++)
		{
			graph[i].clear();
			vis[i] = 0;
			deg[i] = 0;
		}

		for(i = 1; i <= m; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			graph[u].pb(v);

			deg[v]++;
		}

		if(isposs(n) == 0)
		{
			printf("-1\n");
			continue;
		}

		ll z = solve(n);

		printf("%lld\n%s\n", z, ans + 1);
    }


}



