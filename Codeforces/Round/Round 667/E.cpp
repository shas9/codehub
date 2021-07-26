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

ll x[200005];
ll y[200005];
ll dp[200005];

ll bs(ll hi, ll xx)
{
	ll lo = 1;

	ll ret = 1;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(x[mid] <= xx)
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
		cin >> n >> k;

		for(ll i = 1; i <= n; i++) cin >> x[i];
		for(ll i = 1; i <= n; i++) cin >> y[i];
		for(ll i = 1; i <= n + 2; i++) dp[i] = 0;

		sort(x + 1, x + 1 + n);

		ans = 1;

		for(ll i = n; i >= 1; i--)
		{
			ll lim = x[i] + k;

			ll pos = bs(n, lim);

			ll cnt = (pos - i + 1);

			ans = max(cnt + dp[pos + 1], ans);

			dp[i] = max(cnt, dp[i + 1]);
		}

		cout << ans << "\n";
    }


}



