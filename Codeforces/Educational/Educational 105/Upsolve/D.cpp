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

ll par[300005];
vector < pair < ll, pll > > costs;
vector < pll > edge;

ll fnd(ll node)
{
	if(par[node] == node) return node;

	return par[node] = fnd(par[node]);
}

ll arr[300005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(ll i = 1; i <= n * n; i++) par[i] = i;

		ll node = 0;

		costs.clear();
		edge.clear();

		for(ll i = 1; i <= n; i++)
		{
			for(ll j = 1; j <= n; j++)
			{
				ll in;

				cin >> in;

				if(i == j)
				{
					arr[++node] = in;
				}
				else if(i < j)
				{
					costs.pb({in, {i,j}});
				}
			}
		}

		sort(costs.begin(), costs.end());


		for(auto it: costs)
		{
			ll u = fnd(it.second.first);
			ll v = fnd(it.second.second);

			if(u == v) continue;

			if(arr[u] == it.first)
			{
				edge.push_back({it.second.second, u});
				par[it.second.second] = u;
			}
			else if(arr[v] == it.first)
			{
				edge.push_back({it.second.first, v});
				par[it.second.first] = v;
			}
			else
			{
				edge.push_back({v, ++node});
				edge.push_back({u, node});
				arr[node] = it.first;

				par[v] = node;
				par[u] = node;
			}

		}

		cout << node << "\n";

		for(ll i = 1; i <= node; i++) cout << arr[i] << " ";

		cout << "\n";

		cout << node << "\n";

		for(auto it: edge)
		{
			cout << it.first << " " << it.second << "\n";
		}
    }


}


