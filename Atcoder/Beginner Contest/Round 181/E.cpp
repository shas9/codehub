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

ll hh[200005];
ll ww[200005];
ll sumlft[200005];
ll sumrgt[200005];

ll fnd(ll x, ll n)
{
	ll hi = n;
	ll lo = 1;
	ll ret = hi;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(hh[mid] >= x)
		{
			hi = mid - 1;
			ret = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}

	return ret;
}
ll solve(ll n, ll m)
{
	for(ll i = 2; i <= n; i += 2)
	{
		sumlft[i] = hh[i] - hh[i - 1] + sumlft[i - 2];
	}

	sumrgt[n + 1] = 0;

	for(ll i = n - 1; i >= 1; i -= 2)
	{
		sumrgt[i] = hh[i + 1] - hh[i] + sumrgt[i + 2];
	}

	ll ret = mxlld;

	for(ll i = 1; i <= m; i++)
	{
		ll pos = fnd(ww[i], n);
		ll sum = 0;

		if(pos & 1)
		{
			sum = sumlft[pos - 1] + sumrgt[pos + 1] + abs(hh[pos] - ww[i]);
		}
		else
		{
			sum = sumlft[pos - 2] + sumrgt[pos] + abs(ww[i] - hh[pos - 1]);
		}

//		cout << i << ": " << sum << " " << pos << endl;
//
		ret = min(ret, sum);
	}

	assert(ret >= 0);

	return ret;

}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++) cin >> hh[i];
		for(ll i = 1; i <= m; i++) cin >> ww[i];

		sort(hh + 1, hh + 1 + n);

		ans = solve(n,m);

		cout << ans << "\n";
    }


}



