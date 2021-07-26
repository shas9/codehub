// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld 1e18
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

ll arr[103][103];
ll brr[103][103];

ll dp[103][103];

ll solve(ll n, ll m)
{
	for(ll i = 0; i <= n; i++) for(ll j = 0; j <= m; j++) dp[i][j] = mxlld;

	for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) brr[i][j] = brr[0][0] + i + j;

	dp[1][1] = arr[1][1] - brr[1][1];

	if(dp[1][1] < 0) return mxlld;

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= m; j++)
		{
			if(arr[i][j] < brr[i][j]) continue;

			dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]) + (arr[i][j] - brr[i][j]));
		}
	}

	return dp[n][m];
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(m);

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++) slld(arr[i][j]);
		}

		ans = mxlld;
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				brr[0][0] = arr[i][j] - i - j;

				ans = min(ans, solve(n,m));
			}
		}

		printf("%lld\n", ans);
    }


}



