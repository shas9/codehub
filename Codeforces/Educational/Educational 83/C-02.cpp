#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000007


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll nCr(ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

//    ll result = n;
//    for( int i = 2; i <= k; ++i ) {
//        result *= (n-i+1);
//        result /= i;
//    }
//
//    return result;

    ll x = 1, y = 1;

    for(ll i = n - k + 1; i <= n; i++) x *= i, x %= mod;
    for(ll i = 1; i <= k; i++) y *= i, y %= mod;

    return (x / y) % mod;
}

ll fact[3000005];

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


ll _nCr(ll n, ll r)
{
    if(r > n) return 0;

    ll z = ((power(fact[r], mod - 2, mod)) * (power(fact[n - r], mod - 2, mod))) % mod;
    return (fact[n] * z) % mod;
}

void precalc()
{
    fact[0] = 1;

    for(ll i = 1; i <= 3000000; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }
}

ll l, r, n;

ll solve(ll num)
{
    ll sum = 0;

    ll ret = 0;

    for(ll i = 0; i <= n; i++)
    {
        sum = (i * l) + ((n - i) * r);

        if(num == sum)
        {
            ret = _nCr(n,i) % mod;
            break;
        }
    }

//    cout << num << " " << ret << endl;

    return ret;
}

ll gen(ll num)
{
    ll ret = 0;

    if(num > (r * n)) return 0;

    ret = gen(num * 10 + l) + gen(num * 10 + r);

    ret += solve(num);

    return ret % mod;
}



int main()
{
    ll i, j, k, q;
    ll testcase;
    ll input, flag, tag;
    ll ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    precalc();

    while(cin >> l >> r >> n)
    {
        ans = 0;

        ans = gen(l);
        ans += gen(r);

        cout << ans % mod << endl;
    }


}


