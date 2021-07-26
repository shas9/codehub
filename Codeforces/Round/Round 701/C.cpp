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

void test()
{
	ll x = 15;

	for(ll i = 1; i <= 100; i++)
	{
		ll ans = 0;

		for(ll j = 2; j <= x; j++)
		{
			ll k = j + 1;
			ll cnt = j - 1;
			ll ans1 = 0;

			while(k <= i && cnt--) ans++, ans1++, k += (j + 1);

			cout << j << " = " << ans1 << endl;
		}

		cout << i << ": " << ans << endl;
	}
}

ll bs(ll x, ll y)
{
	ll lo = 3;
	ll hi = x;
	ll ret = lo;

	if(y < 3 || x < 3) return 2;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		ll top = mid * (mid - 2);

		if(top <= y)
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
//	test();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		ll x, y;

		cin >> x >> y;

		swap(x,y);

		x++;

		ll lim = bs(x,y);

//		cout << lim << endl;

		ans = (lim - 2);

		ans = (ans * (ans + 1)) / 2;

		ll last = lim;

		for(ll i = lim - 2; i >= 1; i--)
		{
			ll nxt = (y / i);

			if(nxt >= x)
			{
				ans += (x - last) * i;
				break;
			}

			ans += (nxt - last) * i;

			last = nxt;
		}

		cout << ans << "\n";
    }


}


