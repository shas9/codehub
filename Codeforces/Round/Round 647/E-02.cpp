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

vector < ll > vec;

ll p[1000000];

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
		vec.clear();

		slld(n);
		slld(m);

		p[0] = 1;

		for(i = 1; i <= 50; i++)
		{
			p[i] = p[i - 1] * m;

			if(p[i] >= (1e8)) p[i] = 1e8;
		}

		for(i = 0; i < n; i++)
		{
			slld(input);

			vec.push_back(input);
		}

		if(m == 1)
		{
			if(n & 1) printf("1\n");
			else printf("0\n");
			continue;
		}

		sort(vec.rbegin(),vec.rend());

		ll sum1 = 0;
		ll sum2 = 0;
		ll last = 0;
		ll rem = 0;

		for(i = 0; i < vec.size(); i++)
		{
			if(sum2 == 0) sum2 = (sum2 + power(m,vec[i],mod)), last = i, rem = 1;
			else
			{
				ll dff = vec[i - 1] - vec[i];
				if(dff >= 50) rem = 1e8;
				else rem = (rem * p[dff]);

				rem--;

				if(rem) sum1 = (sum1 + power(m,vec[i],mod)) % mod;
				else sum1 = sum2 = 0;
			}
		}

		ans = (sum2 - sum1 + mod) % mod;

		printf("%lld\n", ans);

    }


}

/*

if(same(last,i)) sum1 = 0, sum2 = 0;
			else sum1 = (sum1 + power(m,vec[i],mod)) % mod;

*/
