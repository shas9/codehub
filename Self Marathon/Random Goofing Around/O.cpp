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

vector < pll > g[103];
ll dist[103];

void solve()
{
	priority_queue < pll > pq;
	pq.push({0,1});
	dist[1] = 0;

	while(!pq.empty())
	{
		pll top = pq.top();
		pq.pop();

		for(auto it: g[top.second])
		{
			if(dist[it.first] > it.second + top.first)
			{
				dist[it.first] = it.second + top.first;
				pq.push({dist[it.first], it.first});
			}
		}
	}
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
		slld(n);
		slld(m);

		for(i = 1; i <= n; i++) g[i].clear(), dist[i] = mxlld;

		for(i = 1; i <= m; i++)
		{
			ll u, v, w;
			slld(u);
			slld(v);
			slld(w);

			g[u].pb({v,w});
			g[v].pb({u,w});
		}

		solve();

		if(dist[n] == mxlld) printf("Case %lld: Impossible\n", cs);
		else printf("Case %lld: %lld\n", cs, dist[n]);
    }


}



