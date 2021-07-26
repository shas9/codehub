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

vector < pll > g[5003];
ll mnw;
ll dist[2][5005];

ll solve(ll n)
{
	priority_queue < pll  > pq;

	for(ll j = 0; j < 2; j++) for(ll i = 1; i <= n; i++) dist[j][i] = mxlld;

	dist[0][1] = 0;
	pq.push({0,1});

	while(!pq.empty())
	{
		pll top = pq.top();
		pq.pop();

		for(auto it: g[top.second])
		{
			if(dist[0][it.first] > it.second - top.first)
			{
				dist[1][it.first] = dist[0][it.first];
				dist[0][it.first] = it.second - top.first;

				pq.push({-(it.second - top.first), it.first});
			}
			else if(dist[1][it.first] > (it.second - top.first) && it.second - top.first > dist[0][it.first])
			{
				dist[1][it.first] = it.second - top.first;
				pq.push({-(it.second - top.first), it.first});
			}
		}
	}

	return dist[1][n];
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

		for(i = 1; i <= n; i++) g[i].clear();
		mnw = mxlld;

		for(i = 1; i <= m; i++)
		{
			ll u, v, w;

			slld(u);
			slld(v);
			slld(w);

			if(u == n || v == n) mnw = min(mnw,w);

			g[u].pb({v,w});
			g[v].pb({u,w});
		}

		ans = solve(n);

		printf("Case %lld: %lld\n", cs, ans);
    }


}



