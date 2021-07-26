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

string s;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    precalc();

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;
        cin >> s;

        ll group = 0;
        ll zero = 0;

        for(ll i = 0; i < s.size(); i++)
        {
            if(s[i] == '0') zero++;
            else if(i + 1 < s.size())
            {
                if(s[i + 1] == '1') group++, i++;
            }
        }

        ans = nCr(group + zero, group);

        cout << ans << "\n";

    }


}

