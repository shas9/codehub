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

#define mod 10000007

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

const ll phi = 9988440;

ll eq(ll n, ll p)
{
	ll x = (power(n,p+1,mod) - 1);
	if(x < 0) x += mod;
	ll y = n - 1;

//	if(n == 5) cout << x << " " << y << endl;

	return (x * power(y,phi - 1, mod)) % mod;
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
		ans = 0;

		slld(n);

		ll nn = n;

		slld(m);

		ll xx = n;

		for(i = 1; i <= m; i++) xx *= 10;

		ll sum = 0;

		for(i = 2; i <= xx; i += 2) if(xx % i == 0) sum += i;

		cout << sum << endl;

		ll pw2 = m;
		ll pw5 = m;
		ll p3 = 1;

		for(i = 2; i <= n; i++)
		{
			if(n % i == 0)
			{
				ll cnt = 0;

				while(n % i == 0) n /= i, cnt++;

				if(i == 2) pw2 += cnt;
				else if(i == 5) pw5++;
				else p3 = i;
			}
		}

		if(n > 1)
		{
			if(n == 2) pw2++;
			else if(n == 5) pw5++;
			else p3 = n;
		}

		ll x = eq(2,pw2);
		ll y = eq(5,pw5);
		ll z = 1;

//		cout << pw2 << " " << pw5 << " " << p3 << endl;

		if(p3 != 1) z += p3;
		if(nn == 9) z += (p3 * p3);

//		cout << x << " " << y << " " << z << endl;

		ans = (x * y) % mod;
		ans = (ans * z) % mod;

		ans = (((ans - (y * z)) % mod) + mod) % mod;

		printf("%lld\n", ans);
    }


}


