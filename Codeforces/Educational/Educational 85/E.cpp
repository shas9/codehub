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


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll fact[300005];
ll inv[300005];

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

ll add(ll a, ll b)
{
	return ((a % mod) + (b % mod)) % mod;
}

ll mul(ll a, ll b)
{
	return ((a % mod) * (b % mod)) % mod;
}

vector < ll > pr;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);
	ll d;
    slld(d);

    for(i = 2; i * i <= d; i++)
    {
		if(d % i) continue;

//		cout << i << endl;

		pr.push_back(i);

		while(d % i == 0) d /= i;
    }

    if(d > 1) pr.push_back(d);

    fact[0] = 1;

    for(i = 1; i <= 300000; i++)
    {
		fact[i] = mul(fact[i - 1], i);
    }

    inv[300000] = power(fact[300000], mod - 2, mod);

    for(i = 300000 - 1; i >= 1; i--)
    {
		inv[i] = mul(inv[i + 1], (i + 1));
    }

    slld(n);

    while(n--)
    {
		ll a, b;
		slld(a);
		slld(b);

		vector < ll > dva, dvb;

		for(auto it: pr)
		{
			ll cnt = 0;

//			cout << it << " " << a << " " << b << endl;

			while(a % it == 0) a /= it, cnt++;
			while(b % it == 0) b /= it, cnt--;

//			cout << cnt <<  " !! " << endl;

			if(cnt < 0) dvb.push_back(-cnt);

			if(cnt > 0) dva.push_back(cnt);
		}

		ans = 1;
		ans = mul(ans,fact[accumulate(dva.begin(),dva.end(),0)]);
		for(auto it: dva) ans = mul(ans, inv[it]);

		ans = mul(ans,fact[accumulate(dvb.begin(),dvb.end(),0)]);
		for(auto it: dvb) ans = mul(ans, inv[it]);

		printf("%lld\n", ans);
    }


}


