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

char grid[1003][1003];
ll dp[1003][1003];
ll dp2[1003][1003];
const ll mod = (1e9) + 7;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	cout << -1 % 100 << "\n";
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		memset(dp,-1,sizeof dp);
		memset(dp2,0,sizeof dp2);

		dp[0][1] = 0;
		dp2[0][1] = 1;

		cin >> n;

		for(ll i = 1; i <= n; i++) cin >> grid[i] + 1;

		for(ll i = 1; i <= n; i++)
		{
			for(ll j = 1; j <= n; j++)
			{
				if(grid[i][j] == 'r') continue;

				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

				if(dp[i][j] == dp[i - 1][j]) dp2[i][j] += dp2[i - 1][j];
				if(dp[i][j] == dp[i][j - 1]) dp2[i][j] += dp2[i][j - 1];

				if(grid[i][j] == 'f' && dp[i][j] >= 0) dp[i][j]++;

				dp2[i][j] %= mod;
				dp[i][j] %= mod;

//				cout << i << " " << j << " " << dp[i][j] << " " << dp2[i][j] << "\n";
			}
		}

		if(dp[n][n] == -1) cout << -1 << "\n";
		else cout << dp[n][n] << " " << dp2[n][n] << "\n";
    }


}



