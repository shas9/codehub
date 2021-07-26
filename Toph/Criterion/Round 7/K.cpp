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

const ll mx = 500000 + 10;

vector < pll > g[mx];
ll dp[mx];
ll ww[mx];
ll bb[mx];
bool col[mx];
bool vis[mx];

void solve(ll n)
{
	queue < ll > pq;

	for(ll i = 1; i <= n; i++) dp[i] = ww[i] = bb[i] = mxlld, col[i] = vis[i] = 0;

	dp[n] = ww[n] = bb[n] = 0;

	pq.push(n);

	vis[n] = 1;

	while(!pq.empty())
	{
		ll top = pq.front();
		pq.pop();

		for(pll it: g[top])
		{
			if(vis[it.first]) continue;

			if(it.second == 0)
			{
				ww[it.first] = dp[top] + 1;
			}
			else
			{
				bb[it.first] = dp[top] + 1;
			}

			if(ww[it.first] < bb[it.first]) col[it.first] = 1;

			dp[it.first] = max(ww[it.first], bb[it.first]);

			if(dp[it.first] != mxlld)
			{
				vis[it.first] = 1;
				pq.push(it.first);
			}
		}
	}

	if(dp[1] == mxlld) dp[1] = -1;

	return;
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
		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 1; i <= m; i++)
		{
			ll u, v, c;

			cin >> v >> u >> c;

			g[u].pb({v,c});
		}

		solve(n);

		cout << dp[1] << "\n";

		for(ll i = 1; i <= n; i++) cout << col[i];

		cout << "\n";
    }


}



