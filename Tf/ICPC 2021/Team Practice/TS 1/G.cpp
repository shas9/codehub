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

ll arr[1000006];

long double solve(long double mid, ll n, ll m)
{
	long double ret = 0;

	for(ll i = 1; i <= n; i++)
	{
		ret = max(ret, abs((long double)arr[i] - mid));

		mid += m;
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

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		long double lo = -2e16;
		long double hi = 1e16;
		long double ans = 1e17;

//		cout << ans << "++";

		ll cnt = 200;

		while(cnt--)
		{
			long double mid1 = (2.0 * lo + hi) / 3.0;
			long double mid2 = (lo + 2.0 * hi) / 3.0;

			long double ans1 = solve(mid1, n, m);
			long double ans2 = solve(mid2, n, m);

			if(ans1 < ans2)
			{
				ans = min(ans, ans1);

				hi = mid2;
			}
			else
			{
				ans = min(ans, ans2);

				lo = mid1;
			}
		}

		cout << setprecision(1) << fixed << ans << "\n";
    }


}



