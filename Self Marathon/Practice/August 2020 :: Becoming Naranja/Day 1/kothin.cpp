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

vector < ll > g[200005];
ll par[200005];
ll col[200005];

ll fnd(ll node)
{
	if(par[node] == node) return node;

	return par[node] = fnd(par[node]);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++) g[i].clear(), par[i] = i;

		ll ans = 0;

		for(ll i = 1; i <= n; i++)
		{
			cin >> col[i];

			if(i > 1) ans += (col[i] != col[i - 1]);

			g[col[i]].pb(i);
		}

		cout << ans << "\n";

		for(ll i = 1; i < m; i++)
		{
			ll u, v;

			cin >> u >> v;

			ll pu = fnd(u);
			ll pv = fnd(v);

			if(g[pu].size() < g[pv].size())
			{
				swap(u,v);
				swap(pu,pv);
			}


			for(auto it: g[pv])
			{
				if(it > 1 && fnd(col[it - 1]) == pu) ans--;
				if(it < n && fnd(col[it + 1]) == pu) ans--;

				g[pu].push_back(it);
			}

			par[pv] = pu;

			cout << ans << "\n";

		}
    }


}


