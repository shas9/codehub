#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

bool brute(ll n, ll m)
{
//	bug;
	if(n == 0 && m == 0) return 1;

	if(n <= 0 || m <= 0) return 0;

	bool ret = 0;

	for(ll i = 1; i <= min(n,m); i++)
	{
		ret |= brute(n - i, m - (2*i));
		ret |= brute(n - (2 * i), m - i);
	}

	return ret;
}

bool solve(ll n, ll m)
{
	while(n > 0 && m > 0)
	{
		ll lo = 1;
		ll hi = min(n,m);
		ll x = 1;

		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			if(2 * mid <= n && 2 * mid <= m)
			{
				x = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}

		if(n > m) n -= (2 * x), m -= x;
		else m -= (2 * x), n -= x;
	}

	if(n == 0 && m == 0) return 1;
	return 0;
}

bool solve1(ll n, ll m)
{
	if(n > m) swap(n,m);

	if(m > (2 * n)) return 0;

	ll lo = 0;
	ll hi = m;
	ll x = 0;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;
//
//		if(n == 16 && m == 17)
//		{
//			cout << mid << endl;
//		}

		if((n - mid) == (m - (2 * mid)))
		{
			x = mid;
			break;
		}
		else if((n - mid) < (m - (2 * mid)))
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	n -= x;
	m -= (2 * x);

	if(n % 3 || n != m) return 0;

	return 1;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	for(i = 1; i <= 30; i++)
//	{
//		if(brute(i,i)) cout << i << " " << i << endl;
//	}

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(m);

//		for(n = 1; n <= 20; n++)
//		{
//			for(m = n; m <= 20; m++)
//			{
//				cout << n << " " << m << ": " << brute(n,m) << " " << solve1(n,m) << endl;
//			}
//		}

		if(solve1(n,m) == 0) printf("NO\n");
		else printf("YES\n");
    }


}



