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

long double calc(ll k, ll n, ll m)
{
	long double ret = (k * n + k * m - m) / (long double)(2.0 * k - 1);

	return ret;
}

void brute(ll n, ll m, ll k)
{
	for(int i = 1; i <= 15; i++)
	{
		cout << calc(i,n,m) << " ";
	}

	cout << endl;
}

ll solve(ll n, ll m, ll k)
{
	long double av = (n + m) / 2.0;

	if(k >= n) return 1;

	if((long double)k <= av) return 2;

	long double lo = 2;
	long double hi = 1e15;

	ll ret = 2;


	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

//		cout << lo << " " << hi << " " << mid << " & " << calc(mid,n,m) << endl;

		if(calc(mid,n,m) >= k)
		{
//			bug;
			lo = mid + 1;
			ret = mid;
		}
		else
		{
//			bug;
			hi = mid - 1;
		}

//		cout << lo << " " << hi << endl;
	}

	long double x1 = calc(ret,n,m);
	long double x2 = calc(ret - 1,n,m);
	long double x3 = calc(ret + 1, n, m);

//	printf("%.10f %.10f %.10f %lld\n", x1, x2, x3, k);

	x1 = abs(x1 - (long double)k);
	x2 = abs(x2 - (long double)k);
	x3 = abs(x3 - (long double)k);

//	printf("%.10f %.10f %.10f %lld\n", x1, x2, x3, k);

	if(x2 <= x1 && x2 <= x3) return (ret - 1) * 2 - 1;

	if(x1 <= x2 && x1 <= x3) return (ret) * 2 - 1;

	return (ret + 1) * 2 - 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> m >> k;

//		brute(n,m,k);
		ans = solve(n,m,k);

		printf("%lld\n", ans);
    }


}



