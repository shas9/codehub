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

void brute(ll n, ll m, ll k)
{
	double x = 0;

	double mn = 1e9;

	for(int i = 1; i <= 100; i++)
	{
		x = ((i * n) + (i - 1) * m) / ((i + i - 1) * 1.0);

		printf("%.6f ", x);
	}

	cout << endl;
}

ll solve1(ll n, ll m, ll k)
{
	if(k >= n) return 1;

	ll pos = 1;

	ll lo = 2;
	ll hi = 1000000000000000000;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		double x = ((mid * n) + (mid - 1) * m) / (2.0 * mid - 1);

		if(x >= k)
		{
			pos = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

//	cout << pos << " && " ;

//	if(pos == 0)
//	{
//		pos = ppos + 1;
//	}

//	cout << ppos << " && ";
	double x1 = ((pos * n) + (pos - 1) * m) / (2.0 * (pos) - 1);
	double x2 = (((pos + 1) * n) + (pos) * m) / (2.0 * (pos + 1) - 1);

	double av = (n + m) / 2.0;


	if(abs(av - k) <= (x1 - k) && abs(av - k) <= abs(x2 - k)) return 2;

	if(abs(x1 - k) <= abs(x2-k))
	{
		return pos * 2 - 1;
	}
	else return pos * 2 + 1;
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
		cin >> n >> m >> k;
//
//		brute(n,m,k);

		ans = solve1(n,m,k);

		printf("%lld\n", ans);
    }


}



