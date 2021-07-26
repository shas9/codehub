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

#define eps 1e-12

bool yes(ll x, ll y, long double xx, long double yy, long double r)
{
	long double dist = (x - xx) * (x - xx) + (y - yy) * (y - yy);

	return dist <= (r * r) + eps;
}

ll calc1(ll yy, ll lim, long double x, long double y, long double r)
{
	ll hi = lim;
	ll lo = -1e10;
	ll ret = hi + 1;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(yes(mid, yy, x, y, r))
		{
			ret = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	return lim - ret + 1;
}

ll calc2(ll yy, ll lim, long double x, long double y, long double r)
{
	ll hi = 1e10;
	ll lo = lim;
	ll ret = lo - 1;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(yes(mid, yy, x, y, r))
		{
			ret = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	return ret - lim + 1;
}

void solve(ll &ans)
{
	long double x, y, r;

	cin >> x >> y >> r;

	ll up = y - r - 5;
	ll down = y + r + 5;

	ans = 0;

//	cout << up << " " << down << endl;

	for(ll i = up; i <= down; i++)
	{
		ans += calc1(i,floor(x), x, y, r) + calc2(i,floor(x) + 1, x, y, r);

//		cout << ans << " " << calc2(i,x + 1, x, y, r) << endl;
	}

	return;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    while(1)
    {
		solve(ans);
		cout << ans << "\n";
    }


}


