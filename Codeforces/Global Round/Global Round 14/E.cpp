 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

// when mod is not prime

ll mod = -1;

ll ncr[1001][1001];

ll nCr(ll n, ll r)
{
	if(r == 0) return 1;
	if(r == 1) return n;
	if(n == r) return 1;

	ll &ret = ncr[n][r];

	if(ret != -1) return ret;

	ret = nCr(n - 1,r) + nCr(n - 1, r - 1);

	return ret = (ret % mod);
}

ll dp[500][500];
ll n;

ll pw2[500];

int main()
{
    ll i, j, k, l, m, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> mod)
    {
        memset(dp,0,sizeof dp);
        memset(ncr,-1,sizeof ncr);
        dp[0][0] = 1;

        pw2[0] = 1;
        for(ll i = 1; i <= 450; i++) pw2[i] = (2LL * pw2[i - 1]) % mod;

        for(ll i = 0; i <= n; i++)
        {
            for(ll j = 0; j <= i; j++)
            {
                for(ll k = 1; k + i <= n; k++)
                {
                    dp[i + k + 1][j + k] = (dp[i + k + 1][j + k] + (((dp[i][j] * pw2[k - 1]) % mod * nCr(j + k, k)) % mod)) % mod;
                }
            }
        }

        ans = 0;

        for(ll i = 1; i <= n; i++) ans += dp[n + 1][i];

        cout << ans % mod << "\n";
    }


}

