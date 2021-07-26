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
ll n, d, t, c, p;

bool solve(ll mid)
{
	ll tot = 0;

	for(ll i = 1; i <= n; i++)
	{
		ll dff = arr[i] - arr[i - 1];

		if(dff * 2 <= mid) tot += dff;
		else
		{
			tot += dff * 2;

			ll x = mid - dff;

			tot -= x;
		}
	}

	return tot <= t;
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
		slld(d);
		slld(t);
		slld(c);
		slld(p);

		for(i = 1; i <= n; i++) slld(arr[i]);

		if(d > t)
		{
			printf("Impossible\n");
			continue;
		}

		arr[0] = 0;

		ll need = 0;

		sort(arr + 1, arr + 1 + n);

		arr[++n] = d;

		for(i = 1; i <= n; i++)
		{
			need = max(need, arr[i] - arr[i - 1]);
		}

//		cout << need << " !! ";

		ll lo = max(need,c);
		ll hi = 1e10;

		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			if(solve(mid))
			{
				need = mid;
				hi = mid - 1;
			}
			else
			{
				lo = mid + 1;
			}
		}

//		cout << need << endl;

		cout << (need - c) * p << '\n';

    }


}




