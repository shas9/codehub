// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")
#define bug2 printf("BUG2\n")

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

ll dp[100005][2];
ll cost[100005];
vector < string > vec;

ll solve(ll n)
{
	dp[1][0] = 0;
	dp[1][1] = cost[1];

	ll mx = 1e16;

	for(ll i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i][1] = mx;

		string prv = vec[i - 1];
		string now = vec[i];
		string rprv = prv;
		string rnow = now;

		reverse(rprv.begin(), rprv.end());
		reverse(rnow.begin(), rnow.end());

		if(prv <= now)
		{
			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		}

		if(prv <= rnow)
		{
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + cost[i]);
		}

		if(rprv <= now)
		{
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		}

		if(rprv <= rnow)
		{
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + cost[i]);
		}

		if(dp[i][1] >= mx && dp[i][0] >= mx)
		{
			return -1;
		}
	}

	return min(dp[n][0], dp[n][1]);
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
    while(cin >> n)
    {
		vec.resize(n + 1);

		for(ll i = 1; i <= n; i++) cin >> cost[i];

		for(ll i = 1; i <= n; i++) cin >> vec[i];

		ans = solve(n);

		cout << ans << "\n";
    }


}


