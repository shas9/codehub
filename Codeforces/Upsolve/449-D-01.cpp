// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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

#define mod 1000000007

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
ll dp[2000006][22];
ll freq[2000005];

void solve()
{
//	for(ll i = 0; i < 20; i++)
//	{
//		for(ll j = 0; j < (1 << 20); j++)
//		{
//			if(check(j,i)) dp[j] += dp[j ^ (1 << i)];
//		}
//	}
//
//	for(ll i = 20 - 1; i >= 0; i--)
//	{
//		for(ll j = 0; j < (1 << 20); j++)
//		{
//			if(check(j,i) == 0) dp[j] += dp[j + (1 << i)];
//		}
//	}


	for(ll mask = (1 << 20) - 1; mask >= 0; mask--)
	{
		dp[mask][0] = freq[mask];

		for(ll i = 0; i < 20; i++)
		{
			if(check(mask,i) == 0) dp[mask][i + 1] = dp[mask][i] + dp[mask ^ (1 << i)][i];
			else dp[mask][i + 1] = dp[mask][i];
		}
	}

}

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		memset(dp,0,sizeof dp);

		for(i = 1; i <= n; i++)
		{
			slld(input);
			freq[input]++;
		}

		solve();

		ans = 0;

		for(i = 0; i < (1 << 20); i++)
		{
			ll one = __builtin_popcount(i);

			if(one & 1) ans -= power(2,dp[i][20],mod);
			else ans += power(2,dp[i][20],mod);

			ans = (ans % mod);

			if(ans < 0) ans = (ans + mod) % mod;
		}

		cout << ans << "\n";

    }


}


