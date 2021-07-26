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

ll dp[(1 << 22)];


ll power(ll y)
{
	ll x = 2;
    ll res = 1;      // Initialize result

    x = x % mod;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % mod;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % mod;
    }
    return res;
}

void solve()
{
	for(ll i = 0; i < 21; i++)
	{
		for(ll mask = (1 << 21) - 1; mask >= 0; mask--)
		{
			if(check(mask,i) == 0)
			{
				dp[mask] = (dp[mask] + dp[mask ^ (1 << i)]) % mod;
			}
		}
	}
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
			dp[input]++;
		}

		solve();

		ans = 0;

		for(i = 0; i < (1 << 20); i++)
		{
//			cout << i << " " << dp[i] << endl;
			ll one = __builtin_popcount(i);

			if(one & 1) ans -= power(dp[i]);
			else ans += power(dp[i]);

			ans %= mod;

			if(ans < 0) ans += mod;
		}

		printf("%lld\n", ans);
    }


}


