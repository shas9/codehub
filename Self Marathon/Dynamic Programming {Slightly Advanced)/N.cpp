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

ll dp[2][15001];
ll csum[2][15001];

ll solve(ll n, ll k, ll s)
{
	memset(dp,0,sizeof dp);
	memset(csum,0,sizeof csum);

	for(ll j = 1; j <= s; j++) dp[1][j] = (j <= k), csum[1][j] = csum[1][j - 1] + dp[1][j];

	for(ll i = 2; i <= n; i++)
	{
		for(ll j = 1; j <= s; j++)
		{
			dp[i % 2][j] = ((csum[(i - 1) % 2][j - 1] - csum[(i - 1) % 2][max(0,j - k - 1)]) % mod + mod) % mod;
			csum[i % 2][j] = (csum[i % 2][j - 1] + dp[i % 2][j]) % mod;

//			if(abs(i - j) <= 3) cout << i << " " << j << ":: " << dp[i][j] << " " << csum[i][j] << " " << csum[i][j - 1] << endl;
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
		slld(n);
		slld(k);
		slld(m);

		ans = solve(n,k,m);

		printf("Case %d: %d\n", cs, ans);
    }


}



