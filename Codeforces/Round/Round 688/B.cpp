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

ll changen(ll n)
{
	ll ret = 0;
	ll cs = 0;

	arr[n] = arr[n - 1];

	for(ll i = 2; i <= n; i++)
	{
		ll curr = arr[i] + cs;

		ll diff = (arr[1] - curr);

		ret += abs(diff);

		cs += diff;
	}

	return ret;
}

ll solve(ll n)
{
	ll cs = 0;
	ll ret = mxlld;
	ll cost = 0;


	for(ll i = 2; i <= n; i++)
	{
		ll curr = arr[i] + cs;
		ll diff = (arr[1] - curr);
		cost += abs(diff);
		cs += diff;
	}

	cs = 0;

	for(ll i = 2; i < n; i++)
	{
		ll curr = arr[i] + cs;
		ll curr2 = arr[i + 1] + cs;

		ll diff = (arr[1] - curr);
		ll diff2 = (arr[1] - curr2);

		ll curr3 = arr[i + 1] + cs + diff;
		ll diff3 = (arr[1] - curr3);

		cost -= abs(diff);
		cost -= abs(diff3);
		cost += abs(diff2);

		ret = min(ret, cost);

//		cout << i << " " << cost << " " << curr << " " << curr2 << " " << curr3 << endl;

		cost += abs(diff);
		cost += abs(diff3);
		cost -= abs(diff2);

		cs += diff;
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

		for(ll i = 1; i <= n; i++) slld(arr[i]);

		ans = min(change1(n), change2(n));
		ans = min(ans, solve(n));
		ans = min(ans, changen(n));

		cout << ans << "\n";
    }


}


