// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

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

const ll sz = 300000;
const ll mod = 998244353;

ll fact[sz + 10];
ll invfact[sz + 10];

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


ll nCr(ll n, ll r)
{
    if(r > n) return 0;

    if(n < mod)
    {
        ll z = (invfact[r] * invfact[n - r]) % mod;
        return (fact[n] * z) % mod;
    }

    /// Lucas Theorem
    vector < ll > N, K;

    while(n) N.push_back(n % mod), n /= mod;

    while(r) K.push_back(r % mod), r /= mod;

    ll ret = 1;

    for(ll i = 0; i < K.size(); i++)
    {
        ret = (ret * nCr(N[i],K[i])) % mod;
    }

    return ret;
}

void precalc()
{
    fact[0] = 1;

    for(ll i = 1; i <= sz; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }

    invfact[sz] = power(fact[sz], mod - 2, mod);

    for(ll i = sz - 1; i >= 0; i--)
    {
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
    }

    return;
}

ll dp[5005][13];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    precalc();

    while(cin >> n >> m)
    {
        memset(dp,0,sizeof dp);

        for(ll i = 0; i <= n; i += 2)
        {
            dp[i][0] = nCr(n, i);
        }

        for(ll i = 1; i < 13; i++)
        {
            for(ll j = 0; j <= n; j += 2)
            {
                ll add = (j * (1LL << i));

                for(ll k = add; k <= m; k++)
                {
                    dp[k][i] += (dp[k - add][i - 1] * nCr(n,j)) % mod;
                    dp[k][i] %= mod;
                }
            }
        }

        cout << dp[m][12] << "\n";
    }


}

