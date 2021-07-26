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


vector < ll > g[30];
ll col[30];

ll solve(ll node, ll par, ll root)
{
	ll ret = 0;

	for(auto it: g[node])
	{
		if(it != par)
		{
			if(it == root) ret++;
			else if(it > node)
			{
				if(col[node] == 0)
				{
					col[node] = 1;

					ret += solve(it, node, root);

					col[node] = 0;
				}
			}
		}
	}

	return ret;
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
		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			cin >> u >> v;

			g[u].pb(v);
			g[v].pb(u);
		}

		ans = 0;

		for(ll i = 1; i <= n; i++) ans += solve(i, -1, i);

		cout << ans << "\n";
    }


}



