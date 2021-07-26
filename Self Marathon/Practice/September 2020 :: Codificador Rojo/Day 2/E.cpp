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

ll dp[2][100005];
ll arr[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(ll i = 1; i <= n; i++) cin >> arr[i];

		memset(dp,0,sizeof dp);

		ans = 1;

		dp[0][1] = 1;

		for(ll i = 2; i <= n; i++)
		{
			if(arr[i - 1] < arr[i]) dp[0][i] = 1 + dp[0][i - 1];
			else dp[0][i] = 1;

			ans = max(ans, dp[0][i] + 1);
		}

		dp[1][n] = 1;

		for(ll i = n - 1; i >= 1; i--)
		{
			if(arr[i] < arr[i + 1]) dp[1][i] = 1 + dp[1][i + 1];
			else dp[1][i] = 1;

			ans = max(ans, dp[1][i] + 1);
		}

		for(ll i = 2; i < n; i++)
		{
			if((arr[i + 1] - arr[i - 1]) >= 2)
			{
				ans = max(ans, 1 + dp[0][i - 1] + dp[1][i + 1]);
			}
		}

		ans = min(ans, n);

		cout << ans << "\n";
    }


}



