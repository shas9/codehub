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

vector < ll > vec;
		ll x, y;
		ll a, b;
		ll k;

bool solve(ll target)
{
	ll coll = 0;
	ll idx = 0;
	ll n = target;

//	cout << n << " ";

	ll both = a * b / __gcd(a,b);

	for(ll i = both; i <= n; i += both)
	{
		coll += vec[idx++] * (x + y);
	}

//	cout << coll << " ";

	if(x > y)
	{
		for(ll i = a; i <= n; i += a)
		{
			if(i % b == 0) continue;

			coll += vec[idx++] * x;
		}

//		cout << coll << " ";

		for(ll i = b; i <= n; i += b)
		{
			if(i % a == 0) continue;

			coll += vec[idx++] * y;
		}

//		cout << coll << " ";
	}
	else
	{
		for(ll i = b; i <= n; i += b)
		{
			if(i % a == 0) continue;

			coll += vec[idx++] * y;
		}


//		cout << coll << " ";

		for(ll i = a; i <= n; i += a)
		{
			if(i % b == 0) continue;

			coll += vec[idx++] * x;
		}


//		cout << coll << " ";
	}

//	cout << endl;

	return coll >= k;
}
int main()
{
    ll i, j, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		vec.clear();

		slld(n);

		for(i = 0; i < n; i++)
		{
			slld(input);

			input /= 100;

			vec.pb(input);
		}

		slld(x);
		slld(a);

		slld(y);
		slld(b);

		slld(k);

		ll lo = 1;
		ll hi = n;

		ans = -1;

		sort(vec.rbegin(),vec.rend());

		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			if(solve(mid))
			{
				ans = mid;
				hi = mid - 1;
			}
			else
			{
				lo = mid + 1;
			}
		}

		printf("%lld\n", ans);
    }


}



