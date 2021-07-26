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

vector < pll > g[100005], g1[100005];

void process(ll idx)
{
	map < ll, ll > mp;

	priority_queue < pair < pll, ll > > pq;

	pq.push({{0,1},0});

//	bug;

	while(!pq.empty())
	{
		auto top = pq.top();
		pq.pop();
		top.first.first *= -1;

//		cout << pq.size() << endl;

		if(top.second == 2)
		{
			mp[top.second] = min(mp[top.second], top.first.first);
			continue;
		}

		for(auto it: g[top.first.second])
		{
			pq.push({{ - top.first.first - it.second, it.first }, top.second + 1});
		}
	}

	for(auto it: mp)
	{
		if(it.first != idx)
		{
			g1[idx].push_back({it.first, it.second});
		}
	}

	return;
}

ll dist[100005];

void solve()
{
	for(ll i = 1; i <= 100000; i++) dist[i] = mxlld;

	priority_queue < pll > pq;

	pq.push({0,1});

	dist[1] = 0;

	while(!pq.empty())
	{
		pll top = pq.top();
		pq.pop();

		top.first *= -1;

		if(dist[top.second] != top.first) continue;

		for(auto it: g1[top.second])
		{
			if(dist[it.first] > dist[top.second] + (it.second * it.second))
			{
				dist[it.first] = dist[top.second] + (it.second * it.second);
				pq.push({-dist[it.first], it.first});
			}
		}
	}

	for(ll i = 1; i <= 100000; i++)
	{
		if(dist[i] == mxlld) dist[i] = -1;
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

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++)
		{
			g[i].clear();
			g1[i].clear();
		}

		for(ll i = 1; i <= m; i++)
		{
			ll u, v, c;

			cin >> u >> v >> c;

			g[u].pb({v,c});
		}

		for(ll i = 1; i <= n; i++) process(i);


		solve();

		for(ll i = 1; i <= n; i++) cout << dist[i] << " ";

		cout << "\n";
    }



}



