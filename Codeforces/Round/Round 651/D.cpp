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

ll arr[200005];

bool solve1(ll bar, ll n, ll k)
{
	ll took = 0;

	for(ll i = 1; i <= n; i++)
	{
		if(took & 1)
		{
			if(arr[i] <= bar) took++;
		}
		else took++;

		if(took == k) return 1;
	}

	return 0;
}

bool solve2(ll bar, ll n, ll k)
{
	ll took = 0;

	for(ll i = 1; i <= n; i++)
	{
		if(!(took & 1))
		{
			if(arr[i] <= bar) took++;
		}
		else took++;

		if(took == k) return 1;
	}

	return 0;
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
		ll lo = mxlld;
		ll hi = 0;

		for(i = 1; i <= n; i++) slld(arr[i]), lo = min(lo,arr[i]), hi = max(hi,arr[i]);

		ans = hi;

		while(lo <= hi)
		{
			ll bar = (lo + hi) / 2;

			bool lft = solve1(bar, n, k);
			bool rgt = solve2(bar, n, k);

			if(lft || rgt)
			{
				ans = bar;
				hi = bar - 1;
			}
			else
			{
				lo = bar + 1;
			}
		}

		cout << ans << '\n';

    }


}




