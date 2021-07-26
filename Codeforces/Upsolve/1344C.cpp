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

vector < ll > forw[200005];
vector < ll > rev[200005];

char ans[200005];
bool cycle;
ll vis[200005];

vector < ll > torder;

void dfs(ll node)
{
	vis[node] = 1;

	for(auto it: forw[node])
	{
		if(vis[it] == 1) cycle = 1;
		if(vis[it] == 0) dfs(it);
	}

	torder.push_back(node);

	vis[node] = 2;
}

ll dp[2][200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	while(cin >> n >> m)
	{
		for(i = 1; i <= n; i++) forw[i].clear(), rev[i].clear();

		for(i = 1; i <= m; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			forw[u].pb(v);
			rev[v].pb(u);
		}

		cycle = 0;
		memset(vis,0,sizeof vis);
		torder.clear();

		for(i = 1; i <= n; i++) ans[i] = 'E';
		ans[i] = '\0';

		for(i = 1; i <= n; i++)
		{
			dp[0][i] = dp[1][i] = i;

			if(vis[i] == 0) dfs(i);
		}

		if(cycle) printf("-1\n");
		else
		{
			for(auto it: torder)
			{
				for(auto jt: rev[it]) dp[0][jt] = min(dp[0][it],dp[0][jt]);
			}

			reverse(torder.begin(),torder.end());

			for(auto it: torder)
			{
				for(auto jt: forw[it]) dp[1][jt] = min(dp[1][it],dp[1][jt]);
			}


			ll cnt = 0;

			for(i = 1; i <= n; i++)
			{
//				cout << i << ": " << dp[0][i] << " " << dp[1][i] << endl;
				if(dp[0][i] == dp[1][i] && dp[1][i] == i) cnt++, ans[i] = 'A';
			}

			cout << cnt << " " << ans + 1 << "\n";
		}
	}


}


