// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 998244353

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

const ll sz = 200000;

ll fact[sz];

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

    ll z = ((power(fact[r], mod - 2, mod)) * (power(fact[n - r], mod - 2, mod))) % mod;
    return (fact[n] * z) % mod;
}

void precalc()
{
    fact[0] = 1;

    for(ll i = 1; i <= sz; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	precalc();
    while(cin >> n >> k)
    {
		if(k >= n)
		{
			printf("0\n");
			continue;
		}
		ll c = (n - k);

		ans = 0;

		for(i = 0; i < c; i++)
		{
			ans = (ans + (power(-1,i,mod) * nCr(c,i) * power(c - i, n, mod)) % mod);

			ans = (ans + mod) % mod;
		}

		ans = (ans * nCr(n,n-k)) % mod;

		if(k > 0) ans = (ans * 2) % mod;

		printf("%lld\n", ans);
    }


}



