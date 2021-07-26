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

ll csum[2][200005];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


	while(cin >> n >> m >> k)
	{
		for(i = 1; i <= n; i++) slld(csum[0][i]), csum[0][i] += csum[0][i - 1];

		for(i = 1; i <= m; i++) slld(csum[1][i]), csum[1][i] += csum[1][i - 1];

		ans = 0;

		for(i = 1; i <= n && csum[0][i] <= k; i++)
		{
			ll lft = k - csum[0][i];

			ll pabo = 0;
			ll lo = 1;
			ll hi = m;

			while(lo <= hi)
			{
				ll mid = (lo + hi) / 2;

				if(csum[1][mid] <= lft)
				{
					pabo = mid;
					lo = mid + 1;
				}
				else
				{
					hi = mid - 1;
				}
			}

			cout << i << " " << pabo << " " << lft << endl;

			ans = max(ans, pabo + i);
		}

		for(i = 1; i <= m && csum[1][i] <= k; i++)
		{
			ll lft = k - csum[1][i];

			ll pabo = 0;
			ll lo = 1;
			ll hi = n;

			while(lo <= hi)
			{
				ll mid = (lo + hi) / 2;

				if(csum[0][mid] <= lft)
				{
					pabo = mid;
					lo = mid + 1;
				}
				else
				{
					hi = mid - 1;
				}
			}

			ans = max(ans, pabo + i);
		}

		cout << ans << '\n';
	}


}




