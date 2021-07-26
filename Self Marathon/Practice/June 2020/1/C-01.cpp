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

vector < ll > g[200005];
ll dist[200005];

pll bfs(ll st, ll n)
{
	memset(dist,-1,sizeof dist);

	dist[st] = 0;

	queue < ll > qq;

	qq.push(st);

	while(!qq.empty())
	{
		ll top = qq.front();
		qq.pop();

		for(auto it: g[top])
		{
			if(dist[it] == -1)
			{
				dist[it] = dist[top] + 1;
				qq.push(it);
			}
		}
	}

	pll ret = {0,0};

	for(ll i = 1; i <= n; i++)
	{
		if(dist[i] > ret.second)
		{
			ret = {i, dist[i]};
		}
	}

	return ret;
}

ll diam(ll n)
{
	pll x = bfs(1,n);
	x = bfs(x.first,n);

	return x.second;
}

ll col[200005];
ll solve(ll n)
{
	queue < ll > qq;

	qq.push(1);
	memset(col,-1,sizeof col);
	col[1] = 0;

	while(!qq.empty())
	{
		ll top = qq.front();
		qq.pop();

		for(auto it: g[top])
		{
			if(col[it] == -1)
			{
				col[it] = col[top] ^ 1;
				qq.push(it);
			}
			else assert(col[it] != col[top]);
		}
	}

	ll cnt = 0;

	for(ll i = 1; i <= n; i++)
	{
		assert(col[i] != -1);

		cnt += col[i];
	}

	return min(cnt, n - cnt) - 1;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 1; i < n; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			g[u].pb(v);
			g[v].pb(u);
		}

		ans = solve(n);

		printf("%lld\n", ans);
    }


}



