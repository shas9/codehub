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

vector < pair < double, double > > vec;

double sq(ll x)
{
	double lo = 0;
	double hi = x;
	ll cnt = 1000;

	while(cnt--)
	{
		double mid = (lo + hi) / 2;

		if(mid * mid < x)
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}

	return (lo + hi) / 2;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		if(n == 0) return 0;

		vec.resize(n);

		for(auto &it: vec) cin >> it.first >> it.second;

		double ans = mxlld;

		for(ll i = 0; i < n; i++)
		{
			for(ll j = i + 1; j < n; j++)
			{
				double dist = ((vec[i].first - vec[j].first) * (vec[i].first - vec[j].first)) + ((vec[i].second - vec[j].second) * (vec[i].second - vec[j].second));

				if(dist < ans) ans = dist;
			}
		}

		if(ans >= 100000000) cout << "INFINITY\n";
		else
		{
			double x = sqrt(ans);

			printf("%.4lf\n", x);
		}
    }


}



