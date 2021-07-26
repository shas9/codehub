// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

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

const ll sz = 100;
const ll mod = 1000000007;

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

ll ncr9010;
ll dp[100][(1 << 5)][(1 << 5)];
const ll assigned = (1 << 5) - 1;
string s[5];

ll solve(ll pos, ll pick, ll ban)
{
    if(pos == 100)
    {
        if(pick != assigned) return 0;
        if(ban != assigned) return 0;

        return ncr9010;
    }

    ll &ret = dp[pos][pick][ban];

    if(ret != -1) return ret;

    ret = solve(pos + 1, pick, ban);

    for(ll i = 4; i >= 0; i--)
    {
        if(check(pick,i) == 0 && s[i][pos] == '1') ret += solve(pos + 1, Set(pick,i), ban);
        if(check(ban,i) == 0) ret += solve(pos + 1, pick, Set(ban,i));
    }

    return ret %= mod;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    precalc();

    ncr9010 = (nCr(90,5) * nCr(85,5)) % mod;

    while(cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4])
    {
        memset(dp,-1,sizeof dp);

        ans = solve(0,0,0);

        cout << ans << "\n";
    }



}

