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

ll prob[100005][10];
ll inc[2][100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++)
    {
		for(j = 1; j <= m; j++) slld(prob[i][j]);
    }

    for(i = 0; i <= 1; i++)
    {
		for(j = 1; j <= n; j++)
		{
			slld(inc[i][j]);
		}
    }

    ans = 0;

    for(i = 1; i <= n; i++)
    {
		ll tot = 0;

		for(j = 1; j <= m; j++) tot += prob[i][j];

		ll freelance = (tot * inc[1][i] * power(m * 100,mod - 2, mod)) % mod;
		ll outinc = ((m * 100 - tot) * inc[0][i] * power(m * 100,mod - 2,mod)) % mod;

//		ll freelance = 0, outinc = 0;
//		if(tot == 0) outinc = inc[0][i];
//		else freelance = inc[1][i];

		ans += (freelance + outinc) % mod;
    }

    printf("%lld\n", ans);

}



