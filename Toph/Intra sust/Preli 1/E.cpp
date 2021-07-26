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
ll cost[100005];
vector < ll > vec;

ll calc(ll node, ll par)
{
	for(auto it: g[node])
	{
		if(it != par)
		{
			return calc(it, node) | cost[node];
		}
	}

	return cost[node];
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
    while(cin >> n)
    {
		vec.clear();

		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 1; i < n; i++)
		{
			ll u, v;

			cin >> u >> v;

			g[u].pb(v);
			g[v].pb(u);
		}

		for(ll i = 1; i <= n; i++) cin >> cost[i];

		if(n == 1)
		{
			cout << cost[1] << "\n";
			continue;
		}

		for(auto it: g[1])
		{
			ll sum = calc(it,1) | cost[1];

			vec.push_back(sum);
		}

		vec.erase(unique(vec.begin(),vec.end()),vec.end());

		ll ans = 0;

		for(auto it: vec)
		{
			for(auto jt: vec)
			{
				ans = max(ans, it | jt);
			}
		}

		cout << ans << "\n";
    }


}



