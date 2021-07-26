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

//ll fact[100005];
const ll mod = (1e9) + 7;
const ll sz = 300000;
//const ll mod = 998244353;

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

vector < ll > v;

ll solve()
{
    ll sum = 0;
    map < ll, ll > mp;

    for(auto it: v) sum += it, mp[it]++;

    ll source = 0;
    ll sink = 0;
    ll n = v.size();

    if(sum % n) return 0;

    sum /= n;

    for(auto it: v)
    {
        if(it > sum) source++;
        else if(it < sum) sink++;
    }

    if(source <= 1 || sink <= 1)
    {
        ll ret = fact[n];

        for(auto it: mp)
        {
            ret = (ret * invfact[it.second]) % mod;
        }

        return ret;
    }

    ll ret1 = fact[sink];
    ll ret2 = fact[source];

    for(auto it: mp)
    {
        if(it.first < sum)
        {
            ret1 = (ret1 * invfact[it.second]) % mod;
        }
        else if(it.first > sum)
        {
            ret2 = (ret2 * invfact[it.second]) % mod;
        }
    }

    ll same = (n - (sink + source));

    ll ret3 = (fact[n] * invfact[same]) % mod;
    ret3 = (ret3 * invfact[n - same]) % mod;

    ret3 = (ret3 * ret1) % mod;

    return (ret3 * ret2 * 2) % mod;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    precalc();

    while(cin >> n)
    {
        v.resize(n);

        for(auto &it: v)
        {
            cin >> it;
        }

        ans = solve();

        cout << ans << "\n";
    }


}

