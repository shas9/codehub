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

vector < ll > g[100005];
ll n, a, b, da, db;
ll vis[100005];

ll dist(ll x, ll y)
{
	for(ll i = 1; i <= n; i++) vis[i] = -1;

	vis[x] = 0;

	queue < ll > q;

	q.push(x);

	while(!q.empty())
	{
		ll top = q.front();
		q.pop();

		if(top == y) return vis[top];

		for(auto it: g[top])
		{
			if(vis[it] == -1)
			{
				vis[it] = vis[top] + 1;
				q.push(it);
			}
		}
	}

	assert(0);
}

pll bfs(ll st)
{
	for(ll i = 1; i <= n; i++) vis[i] = -1;

	queue < ll > q;

	vis[st] = 0;

	q.push(st);

	while(!q.empty())
	{
		ll top = q.front();
		q.pop();

		for(auto it: g[top])
		{
			if(vis[it] == -1)
			{
				vis[it] = vis[top] + 1;
				q.push(it);
			}
		}
	}

	pll ret = {st, 0};

	for(ll i = 1; i <= n; i++)
	{
		if(vis[i] > ret.second)
		{
			ret = {i, vis[i]};
		}
	}

	return ret;
}

ll diameter()
{
	pll x = bfs(1);

	pll y = bfs(x.first);
//
//	cout << x.first << " " << x.second << endl;
//	cout << y.first << " " << y.second << endl;

	return y.second;
}

bool solve()
{
	if(dist(a,b) <= da) return 1;

	if(min(db, diameter()) <= (da * 2)) return 1;

	return 0;

}
int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> a >> b >> da >> db;

		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 1; i < n; i++)
		{
			ll u, v;

			cin >> u >> v;

			g[u].pb(v);
			g[v].pb(u);
		}

		if(solve()) cout << "Alice\n";
		else cout << "Bob\n";
    }


}



