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

ll ask(ll l, ll r)
{
	cout << "? " << l << " " << r << endl;
	ll ret;
	cin >> ret;

	return ret;
}

ll solve(ll smx, ll lo, ll hi)
{
	if(lo == hi) return lo;

	if(smx == -1) smx = ask(lo, hi);

	if((hi - lo) == 1)
	{
		if(lo == smx) return hi;
		if(hi == smx) return lo;

		assert(0);
	}

	ll mid = (lo + hi) / 2;

	if(smx <= mid)
	{
		if((mid - lo) == 1)
		{
			assert(0);
		}

		ll v1 = ask(lo, mid);

		if(v1 == smx) return solve(smx, lo, mid);
		else return solve(-1,mid + 1, hi);
	}
	else
	{
		if((hi - mid) == 1) return solve(-1,lo,mid);
		else
		{
			ll v2 = ask(mid + 1, hi);

			if(v2 == smx) return solve(smx, mid + 1, hi);
			else return solve(-1,lo,mid);
		}
	}
	assert(0);

}

ll calc1(ll lo, ll hi)
{
	ll lim = hi;
	hi--;

	ll ret = lo;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(ask(mid, lim) == lim)
		{
			ret = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	return ret;
}

ll calc2(ll lo, ll hi)
{
	ll lim = lo;
	lo++;

	ll ret = hi;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(ask(lim, mid) == lim)
		{
			ret = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	return ret;
}

ll solve1(ll v, ll lo, ll hi)
{
	v = ask(lo, hi);

	if(1 < v && ask(1,v) == v) return calc1(1,v);
	else if(v < hi && ask(v, hi) == v) return calc2(v,hi);

	assert(0);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> n;

    ans = solve1(-1,1,n);

    cout << "! " << ans << endl;


}



