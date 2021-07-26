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

ll dist[2][100005][55];
vector < pll > g[100005];

void solve()
{
	priority_queue < pair < pll, pll > > pq;

	dist[0][1][0] = 0;

	pq.push({{0,1},{0,0}}); //dist, node, state, prvnode

	while(!pq.empty())
	{
		auto it = pq.top();
		pq.pop();

		it.first.first *= -1;

//		cout << it.first.first << " " << it.first.second << " " << it.second.first << " " << it.second.second << "\n";

//		if(dist[it.second.first][it.first.second][it.second.second] != it.first.first) continue;

//		bug;

		for(auto jt: g[it.first.second])
		{
			if(it.second.first == 1)
			{
				ll add = it.first.first + jt.second * jt.second + 2 * jt.second * it.second.second;

				if(dist[0][jt.first][0] > add)
				{
					dist[0][jt.first][0] = add;
					pq.push({{-add, jt.first}, {0, 0}});
				}
			}
			else
			{
				ll add = it.first.first + jt.second * jt.second;

				if(dist[1][jt.first][jt.second] > add)
				{
					dist[1][jt.first][jt.second] = add;
					pq.push({{-add, jt.first}, {1, jt.second}});
				}
			}
		}
	}

	for(ll i = 1; i <= 100000; i++) if(dist[0][i][0] == mxlld) dist[0][i][0] = -1;

	return;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++)
		for(ll j = 0; j <= 50; j++) dist[0][i][j] = dist[1][i][j] = mxlld;

		for(ll i = 1; i <= n; i++)
		{
			g[i].clear();
		}

		for(ll i = 1; i <= m; i++)
		{
			ll u, v, c;

			cin >> u >> v >> c;

			g[u].pb({v,c});
			g[v].pb({u,c});
		}

		solve();

		for(ll i = 1; i <= n; i++) cout << dist[0][i][0] << " ";

		cout << "\n";
    }


}
