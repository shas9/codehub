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
		ll x, y;

		cin >> x >> y >> k;

		ll gc = __gcd(x, y);

		ll cnt = 0;

		for(ll i = 1; i * i <= gc; i++)
		{
			if(gc % i == 0) cnt += 2;
		}

		ll sq = sqrt(gc);

		if(sq * sq == gc) cnt--;

		if(cnt < k) cout << -1 << "\n";
		else if(k <= (cnt / 2))
		{
			cnt = 0;
			for(ll i = 1; i * i <= gc; i++)
			{
				if(gc % i == 0)
				{
					cnt++;

					if(cnt == k)
					{
						ans = gc / i;
						break;
					}
				}
			}

			cout << ans << "\n";
		}
		else
		{
			for(ll i = 1; i * i <= gc; i++)
			{
				if(gc % i == 0)
				{
					if(cnt == k)
					{
						ans = i;
						break;
					}

					cnt--;
				}
			}

			cout << ans << "\n";
		}

    }


}



