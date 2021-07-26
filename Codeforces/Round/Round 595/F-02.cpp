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

vector < ll > graph[203];
ll arr[203];
ll dp[203][203];
ll n, k;

void dfs(ll node, ll par = 0)
{
	for(auto it: graph[node])
	{
		if(it == par) continue;

		dfs(it,node);
	}

	for(ll d = 0; d <= n; d++)
	{
		if(d == 0)
		{
			dp[node][d] = arr[node];
			for(auto it: graph[node])
			{
				if(it == par) continue;

				dp[node][d] += dp[it][k - 1];
			}
		}
		else
		{
			for(auto it: graph[node])
			{
				if(it == par) continue;

				ll x = dp[it][d - 1];

				for(auto jt: graph[node])
				{
					if(jt == par) continue;
					if(it == jt) continue;

					x += dp[jt][max(d - 1,k - d - 1)];
				}

				dp[node][d] = max(dp[node][d], x);
			}
		}
	}

//	for(ll i = 0; i <= n; i++)
//	{
//		if(dp[node][i]) cout << node << " " << i << ": " << dp[node][i] << endl;
//	}

	for(ll i = n - 1; i >= 0; i--)
	{
		dp[node][i] = max(dp[node][i], dp[node][i + 1]);
	}
}
int main()
{
    ll i, j, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		for(i = 1; i <= n; i++) graph[i].clear();

		k++; /// strictly greater than equal k

		memset(dp,0,sizeof dp);

		for(i = 1; i <= n; i++) slld(arr[i]);

		for(i = 1; i < n; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			graph[u].pb(v);
			graph[v].pb(u);
		}

		dfs(1);

		printf("%lld\n", dp[1][0]);
    }


}



