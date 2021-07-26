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

bool solve()
{
	ll k, l, r, t, x, y;

	cin >> k >> l >> r >> t >> x >> y;

	k -= l;
	r -= l;

	if(k + y <= r) k == y;

	if(x >= y)
	{
		ll diff = x - y;

		return diff * (t - 1) + x <= k;
	}
	else
	{
		map < ll, bool > mp;

		ll now = k;

		for(ll i = 1; i <= min(x,t); i++)
		{
			if(mp[now % x]) return 1;

			mp[now % x] = 1;

			if(now + y <= r) now += y;

			now -= x;

			if(now < 0) return 0;
		}

		return 1;
	}
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(1)
    {
		if(solve()) cout << "Yes\n";
		else cout << "No\n";
    }


}

