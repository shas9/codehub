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
	for(ll i = 3; i <= 10000000; i += 2)
	{
		ll a = i * i;
		ll b = (a - 1) / 2;
		ll c = a - b;

		if(c * c != a + b * b)
		{
			cout << i << " : " << a << " " << b << " " << c << endl;
		}

		if(!((i <= b && b <= c)))
		{
			cout << i << " : " << a << " " << b << " " << c << endl;
		}

		assert(c * c == a + b * b);
		assert(i <= b && b <= c);
	}

//	cout << "DONE" << endl;
}

ll bs(ll n)
{
	ll x = (n - 1) / 2;
	ll lo = 1;
	ll hi = x;

	ll ret = 0;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;
		ll a = (mid * 2 + 1) * (mid * 2 + 1);
		ll b = (a - 1) / 2;
		ll c = a - b;

		if(c <= n)
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
		cin >> n;

		ans = bs(n);

		cout << ans << "\n";
    }


}


