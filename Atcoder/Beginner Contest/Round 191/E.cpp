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

bool vis[2000];
vector < pair < pll, ll > > g[2003];
ll dist[2005];

void test()
{
	priority_queue < pll > pq;

	pq.push({1,10});
	pq.push({2,10});
	pq.push({3,10});
	pq.push({1,5});
	pq.push({10,50});

	while(!pq.empty())
	{
		pll top = pq.top();
		pq.pop();

		cout << top.first << " " << top.second << endl;
	}

	return;
}

ll solve(ll node)
{
	memset(vis,0,sizeof vis);

	for(ll i = 1; i <= 2000; i++) dist[i] = mxlld;

	priority_queue < pll > pq;

	pq.push({0,node});

	while(!pq.empty())
	{
		pll top = pq.top();
		pq.pop();

//		cout << top.first << " " << top.second << endl;

		top.first *= -1;

		for(auto it: g[top.second])
		{
			if(vis[it.second]) continue;

			vis[it.second] = 1;

			if(dist[it.first.first] > top.first + it.first.second)
			{
				dist[it.first.first] = top.first + it.first.second;
				pq.push({-(top.first + it.first.second), it.first.first});
			}
		}
	}

	if(dist[node] == mxlld) return -1;

	return dist[node];
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	test();

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 0; i < m; i++)
		{
			ll u, v, c;
			cin >> u >> v >> c;

			g[u].pb({{v,c}, i});
		}

		for(ll i = 1; i <= n; i++)
		{
			cout << solve(i) << "\n";
		}
    }


}


