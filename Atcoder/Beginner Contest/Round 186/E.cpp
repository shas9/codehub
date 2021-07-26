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


ll calphi(ll mm)
{
	double res = mm;

	for(ll i = 2; i * i <= mm; i++)
	{
		if(mm % i == 0)
		{
			while(mm % i == 0) mm /= i;
			res *= (1.0 - (1.0 / i));
		}
	}

	if(mm > 1) res *= (1.0 - (1.0 / mm));

	return (long long)res;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> m >> k;

		ll b = (n - m);

		ll g = __gcd(b, __gcd(k,n));

		b /= g;
		k /= g;
		n /= g;

		if(__gcd(k,n) != 1) ans = -1;
		else
		{
			ans = (b * power(k, calphi(n) - 1, n)) % n;
		}

		cout << ans << "\n";
    }


}



