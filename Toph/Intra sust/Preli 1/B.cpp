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

long double sqrt(ll x)
{
	long double lo = 0;
	long double hi = x;

	long double ret = 0;

	ll cnt = 1000;

	while(cnt--)
	{
		long double mid = (lo + hi) / 2;

		if(mid * mid > x)
		{
			hi = mid;
		}
		else
		{
			ret = mid;
			lo = mid;
		}
	}

	return ret;
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
		ll w;
		ll h;

		cin >> m >> w >> n;

		h = w;

		for(ll i = m; i > n; i--)
		{
			w *= 2;

			swap(h,w);
		}

		long double ans;

		if((m - n) % 2 == 0) ans = w + h * sqrt(2);
		else ans = w * sqrt(2) + h;

		cout << setprecision(4) << fixed << ans << "\n";

    }


}



