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

#define mod 958585860497

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

ll hh[10004];
ll cc[10004];
ll n;

ll solve(ll mid)
{
	ll ret = 0;

	for(ll i = 1; i <= n; i++)
	{
		ret += (abs(mid - hh[i]) * cc[i]);
	}

//	cout << mid << " " << ret << endl;
	return ret;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		for(i = 1; i <= n; i++)
		{
			slld(hh[i]);
		}

		for(i = 1; i <= n; i++)
		{
			slld(cc[i]);
		}


		ans = 0;

		ll hi = 10000;
		ll lo = 1;

		while(lo <= hi)
		{
			ll mid1 = (lo + (hi - lo) / 3);
			ll mid2 = (hi - (hi - lo) / 3);

			ll lf = solve(mid1);
			ll rf = solve(mid2);

			if(lf <= rf) hi = mid2 - 1, ans = lf;
			else lo = mid1 + 1, ans = rf;
		}

		printf("%lld\n", ans);


    }


}


