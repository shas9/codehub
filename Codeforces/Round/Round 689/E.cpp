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

bool solve(ll k, ll l, ll r, ll t, ll x, ll y)
{
	if(k + y <= r) k += y;

	k -= l;
	r -= l;

	if(x >= y)
	{
		if(k < x) return 0;

		ll diff = x - y;

		return (diff * (t - 1) + x <= k);
	}
	else
	{
		if(k < x) return 0;

		ll maxmod = (r - y);

		if(maxmod >= x) return 1;

		ll days = y / x;
		ll mod = y % x;

		ll totmod = k % x;

		t -= (k / x);

		for(ll i = 1; i <= x + 1; i++)
		{
			if(t <= 0) return 1;
			if(totmod >= maxmod) return 0;

			t -= days;
			totmod = (totmod + mod) % x;

		}

		return 1;
	}

	assert(0);
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> k >> l >> r >> i >> n >> m)
    {
		if(solve(k,l,r,i,n,m)) cout << "Yes\n";
		else cout << "No\n";
    }


}



