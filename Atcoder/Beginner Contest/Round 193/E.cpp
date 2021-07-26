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

struct CRT
{
    ll n;
    vector < ll > m, r;

    void init()
    {
        m.clear();
        r.clear();
    }

    pll ext_euclid(ll a, ll b)
    {
        pll ret = {0,0};

        ll x1 = 0, y1 = 1;
        ll x2 = 1, y2 = 0;

        ll r3, r0;

        for(ll r1 = b, r2 = a; r1 ; r2 = r1, r1 = r3)
        {
            r0 = r2 / r1;
            r3 = r2 % r1;

            ll x3 = (x2 - (x1 * r0));
            ll y3 = (y2 - (y1 * r0));

            x2 = x1, y2 = y1;
            x1 = x3, y1 = y3;
        }

        return {x2,y2};
    }

    ll lcm(ll a, ll b)
    {
        ll ret = a / __gcd(a,b);
        return ret * b;
    }

    ll mul(__int128 a, __int128 b, __int128 m)
    {
        __int128 ret = ((a % m) * (b % m)) % m;

        return (long long) ret;
    }

    pll start()
    {
        ll r1 = r[0], m1 = m[0];
        ll n = m.size();

        for(ll i = 1; i < n; i++)
        {
            ll r2 = r[i], m2 = m[i];
            ll g = __gcd(m1,m2);

            if(r2 % g != r1 % g) return {-1,-1};

            pll ans = ext_euclid(m1/g,m2/g);

            ll md = lcm(m1,m2);

            ll x = (mul(mul(r2,m1/g,md),ans.first,md) + mul(mul(r1,m2/g,md),ans.second,md)) % md;

            r1 = x, m1 = md;

            if(r1 < 0) r1 += md;
        }

        return {r1,m1};
    }
};

ll solve()
{
	ll p, q, x, y;

	cin >> x >> y >> p >> q;

	CRT crt;

	ll ans = mxlld;

	for(ll i = x; i < x + y; i++)
	{
		for(ll j = p; j < (p + q); j++)
		{
			crt.init();

			crt.m.push_back(2 * (x + y));
			crt.m.push_back(p + q);

			crt.r.push_back(i);
			crt.r.push_back(j);

			pll ret = crt.start();

			if(ret.second == -1) continue;

			ans = min(ans, ret.first);

		}
	}

	if(ans == mxlld) return -1;

	return ans;


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
		ans = solve();

		if(ans == -1) cout << "infinity\n";
		else cout << ans << "\n";
    }


}



