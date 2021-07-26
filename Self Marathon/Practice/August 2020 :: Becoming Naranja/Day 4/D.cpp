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

ll dp[2003];
ll arr[2003];

bool solve(ll mid, ll n, ll k)
{
	for(ll i = 1; i <= n; i++) dp[i] = i - 1;

	for(ll i = 2; i <= n; i++)
	{
		for(ll j = i - 1; j >= 1; j--)
		{
			if(abs(arr[j] - arr[i]) <= (i - j) * mid)
			{
				dp[i] = min(dp[i], (i - j - 1) + dp[j]);
			}
		}
	}

	ll mn = n;

	for(ll i = 1; i <= n; i++)
	{
		mn = min(mn, dp[i] + (n - i));
	}

	return mn <= k;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		for(ll i = 1; i <= n; i++) cin >> arr[i];

		ll lo = 0;
		ll hi = 3e9;

		ans = 3e9;

		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			if(solve(mid,n,k))
			{
				ans = mid;
				hi = mid - 1;
			}
			else
			{
				lo = mid + 1;
			}
		}

		cout << ans << "\n";
    }


}


