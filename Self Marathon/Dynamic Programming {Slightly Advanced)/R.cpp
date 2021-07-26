// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

#define mod 1000000007

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

ll n, m, k;
ll fact[1003];

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


ll ncr[1001][1001];

ll nCr(ll n, ll r)
{
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
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fact[0] = 1;

	for(i = 1; i <= 1000; i++) fact[i] = (fact[i - 1] * i) % mod;
	memset(ncr,-1,sizeof ncr);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(m);
		slld(k);

		ans = fact[n - k];

//		cout << ans << " ";

		for(i = 1; i <= (m - k); i++)
		{
			if(i & 1) ans -= nCr(m - k, i) * fact[n - k - i];
			else ans += nCr(m - k, i) * fact[n - k - i];

			ans = ((ans % mod) + mod) % mod;

//			cout << ans << " ";
		}

		ans = (ans * nCr(m,k)) % mod;
		printf("Case %lld: %lld\n", cs, ans);

    }


}



