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

void test(ll n)
{
	ll cnt = 0;

	for(ll i = 0; i <= n; i++)
	{
		for(ll j = i; j <= n; j++)
		{
			for(ll k = j; k <= n; k++)
			{
				cnt++;
			}
		}
	}

	cout << cnt << " " << (n + 3) * (n + 1) * (n + 2) / 6 << endl;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


//	test(25);

	ll a, b, c;

    while(cin >> a >> b >> c >> l)
    {
		ans = ((l + 3) * (l + 1) * (l + 2)) / 6;

//		cout << ans << "\n";

		for(ll i = 0; i <= l; i++)
		{
			ll x = min(+ a - b - c + i, l - i);
			ll y = min(- a + b - c + i, l - i);
			ll z = min(- a - b + c + i, l - i);

			x = max(x,-1LL);
			y = max(y,-1LL);
			z = max(z,-1LL);

			ans -= ((x + 2) * (x + 1)) / 2;
			ans -= ((y + 2) * (y + 1)) / 2;
			ans -= ((z + 2) * (z + 1)) / 2;
		}

		cout << ans << "\n";
    }

}


