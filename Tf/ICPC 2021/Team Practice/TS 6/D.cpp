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
pll arr[200005];
ll dp[200005];

ll solve(ll node, ll par)
{
	ll ret = arr[node].first;

	if(par != -1) ret = max(arr[node].first, dp[par]);

	ret -= arr[node].second;

	dp[node] = ret;

	for(auto it: g[node])
	{
		if(it != par)
		{
			ret = min(ret, solve(it, node));
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
		arr[0] = {m,0};

		for(ll i = 1; i <= n; i++)
		{
			ll u, v, c;

			cin >> u >> v >> c;

			arr[i] = {v,c};

			g[u].pb(i);
			g[i].pb(u);
		}

		ans = solve(0,-1);

		cout << ans << "\n";
    }


}



