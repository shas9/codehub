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

ll arr[200005];
ll csum[200005];

bool isposs(ll x, ll k, ll n)
{
	for(ll i = 1; i <= n; i++)
	{
		if(arr[i] < x) csum[i] = -1;
		else csum[i] = 1;

		csum[i] += csum[i - 1];
	}

	ll mx = mnlld;

	for(ll i = (n - k + 1), j = n; i >= 1; i--, j--)
	{
		mx = max(mx, csum[j]);

		if(csum[i - 1] < mx) return 1;
	}

	return 0;
}

ll solve(ll n, ll k)
{
	ll lo = 1;
	ll hi = n;
	ll ret = -1;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

//		cout << mid << endl;

		if(isposs(mid,k,n))
		{
//			bug;
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

    while(cin >> n >> k)
    {
		for(ll i = 1; i <= n; i++) cin >> arr[i];

		cout << solve(n,k) << "\n";
    }


}


