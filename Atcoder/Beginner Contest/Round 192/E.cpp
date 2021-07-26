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

ll dist[100005];
vector < pair < ll, pll > > g[100005];

ll solve(ll x, ll y)
{
	priority_queue < pll > pq;

	pq.push({0,x});

	dist[x] = 0;

	while(!pq.empty())
	{
		pll top = pq.top();
		pq.pop();

		top.first *= -1;

		if(dist[top.second] != top.first) continue;

//		cout << top.first << " " << top.second << "\n";

		for(auto it: g[top.second])
		{
			ll add = (top.first + it.second.second);

//			cout << "++ " << it.first << " " << add << " ";
			add += (it.second.first - (top.first % it.second.first)) % it.second.first;
//			cout << add << endl;


			if(dist[it.first] > add)
			{
				dist[it.first] = add;

				pq.push({-add, it.first});
			}
		}
	}

	if(dist[y] == mxlld) return -1;

	return dist[y];
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	ll x, y;

    while(cin >> n >> m >> x >> y)
    {
		for(ll i = 1; i <= n; i++)
		{
			g[i].clear();
			dist[i] = mxlld;
		}

		for(ll i = 1; i <= m; i++)
		{
			ll u, v, t, k;
			cin >> u >> v >> t >> k;

			g[u].pb({v,{k,t}});
			g[v].pb({u,{k,t}});
		}

		ans = solve(x,y);

		cout << ans << "\n";
    }


}




