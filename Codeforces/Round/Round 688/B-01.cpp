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

ll change1(ll n)
{
	ll ret = 0;
	ll cs = 0;

	for(ll i = 3; i <= n; i++)
	{
		ll curr = arr[i] + cs;

		ll diff = (arr[2] - curr);

		ret += abs(diff);

		cs += diff;
	}

	return ret;
}

ll change2(ll n)
{
	ll ret = 0;
	ll cs = 0;

	for(ll i = 3; i <= n; i++)
	{
		ll curr = arr[i] + cs;

		ll diff = (arr[1] - curr);

		ret += abs(diff);

		cs += diff;
	}

	return ret;
}

ll change(ll n)
{
	ll ret = 0;
	ll cs = 0;
	ll mx = 0;
	ll pos = 2;

	arr[n + 1] = 0;

	for(ll i = 2; i <= n; i++)
	{
		ll sum = abs(arr[i - 1] - arr[i]) + abs(arr[i + 1] - arr[i]);

		if(sum > mx) mx = sum, pos = i;
	}

	arr[pos] = arr[pos - 1];

//	cout << mx << " -- " << pos << endl;

	for(ll i = 2; i <= n; i++)
	{
		ll curr = arr[i] + cs;

		ll diff = (arr[1] - curr);

		ret += abs(diff);

		cs += diff;
	}

	cout << ret << " " << pos << endl;
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

		for(ll i = 1; i <= n; i++) slld(arr[i]);

//		cout << change1(n) << " " << change2(n) << endl;
		ans = min(change1(n), change2(n));
		ans = min(ans, change(n));

		cout << ans << "\n";
    }


}
