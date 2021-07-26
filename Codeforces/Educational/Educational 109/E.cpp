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

ll sum[50004][22];
const ll mod = 998244353;

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

ll fact[25];

ll ncr[1001][1001];

ll nCr(ll n, ll r)
{
    if(r > n) return 0;
	if(r == 0) return 1;
	if(r == 1) return n;
	if(n == r) return 1;

	ll &ret = ncr[n][r];

	if(ret != -1) return ret;

	ret = nCr(n - 1,r) + nCr(n - 1, r - 1);

	return ret = (ret % mod);
}

// when mod is prime


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        memset(sum,0,sizeof sum);
        memset(ncr,-1,sizeof ncr);

        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++)
            {
                cin >> in;
                sum[j][in]++;
            }
        }

        fact[0] = 1;

        for(ll i = 1; i <= 20; i++) fact[i] = (fact[i - 1] * i) % mod;

        ans = 0;

        for(ll i = 1; i <= m; i++)
        {
            ll khali = 0;
            ll add = 1;

            for(ll j = 1; j <= (n + 1); j++)
            {
                if(sum[i][j])
                {
                    add = (add * nCr(khali, sum[i][j])) % mod;
                    add = (add * fact[sum[i][j]]) % mod;

                    khali -= sum[i][j];
                }

                khali++;
            }

            add = (fact[n] - add + mod + mod) % mod;

            ans = (ans + add) % mod;
        }

        ans = (ans * power(fact[n], mod - 2, mod)) % mod;

        cout << ans << "\n";
    }


}

