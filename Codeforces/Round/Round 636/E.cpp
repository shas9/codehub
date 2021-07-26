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
ll cost[200005];
ll a, b, c;
ll n, m;
ll dist[5][200005];

void bfs(ll st, ll ff)
{
	queue < ll > qq;

	qq.push(st);

	for(ll i = 1; i <= n; i++) dist[ff][i] = -1;

	dist[ff][st] = 0;

	while(!qq.empty())
	{
		ll top = qq.front();
		qq.pop();

		for(auto it: graph[top])
		{
			if(dist[ff][it] != -1) continue;

			dist[ff][it] = dist[ff][top] + 1;

			qq.push(it);
		}
	}

}
ll solve()
{
	bfs(a,1);
	bfs(b,2);
	bfs(c,3);

	for(ll i = 1; i <= m; i++) cost[i] += cost[i - 1];

	ll ret = mxlld;

	for(ll i = 1; i <= n; i++)
	{
		ll aci = dist[1][i] + dist[3][i];

		ll bi = dist[2][i] + aci;

		if(bi > m) continue;

//		cout << bi << " " << cost[bi] << " " << cost[dist[2][i]] << endl;

		ret = min(ret, cost[bi] + cost[dist[2][i]]);
	}

	return ret;
}

void inp()
{
	cin >> n >> m >> a >> b >> c;

	for(ll i = 1; i <= n; i++) graph[i].clear();

	for(ll i = 1; i <= m; i++) slld(cost[i]);

	for(ll i = 1; i <= m; i++)
	{
		ll u, v;
		slld(u);
		slld(v);

		graph[u].pb(v);
		graph[v].pb(u);
	}

	sort(cost + 1, cost + 1 + m);
}
int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		inp();

		ans = solve();

		printf("%lld\n", ans);
    }


}


