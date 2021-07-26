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

#define mod 100000007

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

ll dp[2][15003];
ll pref[2][15003];
ll tsum[15003];

ll solve(ll n, ll k, ll s)
{
	for(ll i = 1; i <= s; i++)
	{
		if(i <= k) dp[1][i] = i;
		pref[1][i] = (dp[1][i] + pref[1][i - 1]) %mod;
	}

	for(ll i = 2; i <= n; i++)
	{
		memset(dp[i % 2], 0, sizeof dp[i % 2]);
		memset(pref[i % 2], 0, sizeof pref[i % 2]);
		memset(tsum, 0, sizeof tsum);

		tsum[i] = pref[(i - 1) % 2][i - 1];

		for(ll j = i; j <= s; j++)
		{
			dp[i % 2][j] = ((tsum[j] - (k * pref[(i - 1) % 2][max(j - k - 1, 0LL)]) % mod - tsum[max(j - k, 0LL)]) % mod + mod) % mod;
			pref[i % 2][j] = (pref[i % 2][j - 1] + dp[i % 2][j]) % mod;

			tsum[j + 1] = (tsum[j] + pref[(i - 1) % 2][j]) % mod;
		}
	}

	return dp[n % 2][s];

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
		memset(pref,0,sizeof pref);
		memset(dp,0,sizeof dp);

		slld(n);
		slld(m);
		slld(k);

		ans = solve(n,m,k);

		printf("Case %lld: %lld\n", cs, ans);
    }


}



