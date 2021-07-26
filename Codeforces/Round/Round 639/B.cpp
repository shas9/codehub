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

void gen()
{
	ll i = 2;
	ll j = 1;
	ll inc = 5;

	for(; j <= 1000000; j++, inc += 3)
	{
		i += inc;

		if(j == 1000 || j == 10000 || j == 100000 || j == 1000000) cout << i << endl;
	}
}

ll card[1000006];

void precalc()
{
	card[1] = 2;

	ll inc = 5;

	for(ll i = 2; i <= 1000000; i++, inc += 3)
	{
		card[i] = card[i - 1] + inc;
	}
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	gen();

	precalc();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		ans = 0;

		while(n >= 2)
		{
			ll lo = 1;
			ll hi = 1000000;

			ans++;

			ll idx = hi;

			while(lo <= hi)
			{
				ll mid = (lo + hi) / 2;

				if(card[mid] <= n)
				{
					idx = mid;
					lo = mid + 1;
				}
				else
				{
					hi = mid - 1;
				}
			}

			n -= card[idx];
		}

		printf("%lld\n", ans);
    }


}

