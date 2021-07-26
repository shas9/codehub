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
map < pll, bool > mp;

bool vis[100005];

void bfs()
{
	memset(vis,0,sizeof vis);

	vis[0] = 1;

	queue < ll > q;

	q.push(0);

	while(!q.empty())
	{
		ll top = q.front();
		q.pop();

		for(auto it: g[top])
		{
			if(vis[it] == 0)
			{
				q.push(it);
				mp[{it, top}] = 1;
				mp[{top, it}] = 1;

				vis[it] = 1;
			}
		}
	}

	return;
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
		mp.clear();

		cin >> n >> m;

		for(ll i = 0; i <= n; i++) g[i].clear();

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			g[u].pb(v);
			g[v].pb(u);
		}

		for(ll i = 0; i <= n; i++) sort(g[i].begin(), g[i].end());

		bfs();

		cin >> m;

		printf("Case %lld:\n", cs);

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			if(mp.find({u,v}) == mp.end()) printf("No\n");
			else printf("Yes\n");
		}
    }


}




