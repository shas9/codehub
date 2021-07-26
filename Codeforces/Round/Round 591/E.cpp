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

vector < pll > graph[500005];
ll dp[500005][2];
ll n, k;

ll solve(ll node, ll par)
{
	vector < ll > diff;

	ll sum = 0;

	for(auto it: graph[node])
	{
		if(it.second == par) continue;

		sum += solve(it.second, node);

		diff.push_back(dp[it.second][1] + it.first - dp[it.second][0]);
	}

	sort(diff.rbegin(),diff.rend());

	for(ll i = 0; i < min(k,(long long)diff.size()); i++)
	{
		if(diff[i] > 0) sum += diff[i];
	}

	dp[node][0] = dp[node][1] = sum;

	if(k <= diff.size() && diff[k - 1] > 0) dp[node][1] -= diff[k - 1];

	return dp[node][0];
}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(k);

		for(i = 1; i <= n; i++)
		{
			graph[i].clear();

			for(j = 0; j <= 1;  j++) dp[i][j] = -1;
		}

		for(i = 1; i < n; i++)
		{
			ll u, v, c;

			slld(u);
			slld(v);
			slld(c);

			graph[u].pb({c,v});
			graph[v].pb({c,u});
		}

//		for(i = 1; i <= n; i++) sort(g[i].rbegin(),g[i].rend());

		ans = solve(1,0);

		cout << ans << "\n";
    }


}



