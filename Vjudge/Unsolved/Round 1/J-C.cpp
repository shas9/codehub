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

ll dp[2003][3003];
ll f[2003];
const ll mod = 10007;

ll solve(ll n, ll k, ll lim = -1)
{
//	cout << n << " " << k << endl;
	if(k == 0) return 1;

	if(n == 1) return 0;

//	bug;

	ll &ret = dp[n][k];

	if(ret != -1) return ret;

	ret = solve(n - 1, k);

	if(lim != -1)
	{
		if(k >= lim) ret += solve(n, k - 1, lim);
	}
	else
	{
		ret += solve(n, k - 1, max(0LL, k - n));
	}

	return ret %= mod;
}

void test()
{
	ll cnt = 0;

	for(ll i = 1; i <= 2000; i++)
	{
		for(ll j = 1; j <= 3000; j++) cnt += min(i,j);
	}

	cout << cnt << endl;
}

void calc()
{
	ll n = 2000;
	ll k = 3000;

	memset(dp, 0, sizeof dp);

	for(ll i = 1; i <= n; i++) dp[i][0] = 1;

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= k; j++)
		{
			dp[i][j] = dp[i - 1][j];

			if(j >= i) dp[i][j] -= dp[i - 1][j - i];

			dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
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

	fastio;

	f[0] = 1;
	for(ll i = 1; i <= 2000; i++) f[i] = (f[i - 1] * i) % mod;

	memset(dp,-1,sizeof dp);

	calc();

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
		ans = 0;

		cin >> n >> k;

		if(k) ans = dp[n][k - 1];

		ans = (f[n] - ans) % mod;
		if(ans < 0) ans += mod;

		cout << "Case " << cs << ": " << ans << "\n";
    }


}


