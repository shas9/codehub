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

const ll mod = (1e9) + 7;
ll dp[5003][5003];
ll dp2[5003][5003];
ll n;
ll freq[5003];
ll arr[5003];

ll solve(ll node, ll k)
{
	if(node < 1 || node > n) return 0;

	ll &ret = dp[node][k];

	if(ret != -1) return ret;

	ret = 0;

	if(k == 0) return ret = 1;

	return ret = (solve(node - 1, k - 1) + solve(node + 1, k - 1)) % mod;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k >> q)
    {
		memset(dp,-1,sizeof dp);
		memset(freq, 0, sizeof freq);

		for(ll i = 1; i <= n; i++) solve(i,k);

		for(ll i = 1; i <= n; i++)
		{
			for(ll j = 0; j <= k; j++) dp2[i][j] = (dp[i][j] * dp[i][k - j]) % mod;
		}

		for(ll i = 1; i <= n; i++)
		{
			for(ll j = 0; j <= k; j++) freq[i] += dp2[i][j];

			freq[i] %= mod;
		}

		ans = 0;

		for(ll i = 1; i <= n; i++)
		{
			cin >> arr[i];

			ans += (arr[i] * freq[i]) % mod;
		}

		for(ll i = 1; i <= q; i++)
		{
			ll u, v;
			cin >> u >> v;

			ans -= (arr[u] * freq[u]) % mod;
			arr[u] = v;
			ans += (arr[u] * freq[u]) % mod;

			ans %= mod;

			if(ans < 0) ans += mod;

			cout << ans << "\n";
		}
    }


}




