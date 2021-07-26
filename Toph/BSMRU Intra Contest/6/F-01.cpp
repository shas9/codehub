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

ll arr[100005];

ll calc(ll idx, ll mid, ll n)
{
	ll a = arr[idx];
	ll b = arr[mid] - arr[idx];
	ll c = arr[n] - arr[mid];

	return (a - b) * (a - b) + (b - c) * (b - c);
}

ll solve(ll idx, ll n)
{
	ll lo = idx + 1;
	ll hi = n - 1;

	ll ret = mxlld;

	while(lo <= hi)
	{
		ll mid1 = (lo + (hi - lo) / 3);
		ll mid2 = (hi - (hi - lo) / 3);

		ll ans1 = calc(idx,mid1,n);
		ll ans2 = calc(idx,mid2,n);

//		cout << idx << " " << mid1 << " = " << ans1 << " " << mid2 << " = " << ans2 << '\n';

		if(ans1 < ans2) ret = min(ret,ans1), hi = mid2 - 1;
		else lo = mid1 + 1, ret = min(ret,ans2);
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
		slld(n);

		for(i = 1; i <= n; i++) slld(arr[i]), arr[i] += arr[i - 1];

		ans = mxlld;

		for(i = 1; i <= n - 2; i++)
		{
			ans = min(ans, solve(i,n));

//			cout << i << " " << solve(i,n) << '\n';
		}

		cout << ans << '\n';
    }


}


