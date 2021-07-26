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

ll dp[200005][4];
ll mp[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		for(i = 1; i <= n; i++) slld(input), mp[input] = 1;
		for(i = 1; i <= m; i++) slld(input), mp[input] = 2;
		for(i = 1; i <= k; i++) slld(input), mp[input] = 3;

		memset(dp,0,sizeof dp);

		for(i = 1; i <= (n + m + k); i++) for(j = 1; j <= 3; j++) dp[i][j] = mxlld;

		for(i = 1; i <= (n + m + k); i++)
		{
			for(j = 1; j <= 3; j++)
			{
				ll cost = 0;

				if(j != mp[i]) cost = 1;

				if(j >= 1) dp[i][j] = min(dp[i][j], dp[i - 1][1] + cost);

				if(j >= 2) dp[i][j] = min(dp[i][j], dp[i - 1][2] + cost);

				if(j >= 3) dp[i][j] = min(dp[i][j], dp[i - 1][3] + cost);
			}
		}

		ans = min(dp[n + m + k][1], min(dp[n + m + k][2],dp[n + m + k][3]));

		printf("%lld\n", ans);
    }


}


