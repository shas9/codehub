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

long double n, p1, p2, v1, v2;

bool calc1(long double x)
{
	long double dist1 = x * v1;
	long double dist2 = x * v2;

	long double dist = dist1 + dist2 - p1 - (n - p2);

	if(dist1 < p1)
	{
		return dist2 >= (n - p2) + n;
	}

	if(dist2 < (n - p2))
	{
		return dist1 >= (n + p1);
	}

	return dist >= n;
}

bool calc2(long double x)
{
	long double dist1 = x * v1;
	long double dist2 = x * v2;

	long double dist = dist1 + dist2 - (p2 - p1);

	if(dist1 < (n - p1))
	{
		return dist2 >= p2 + n;
	}

	if(dist2 < p2)
	{
		return dist1 >= (n + (n - p1));
	}

	return dist >= n;

}

bool calc3(long double x)
{
	long double dist1 = x * v1;
	long double dist2 = x * v2;

	long double dist = dist1 + dist2 - ((n - p2) + p1);

	return dist >= ((p2 - p1) * 2) && dist1 >= p1 && dist2 >= (n - p2);

}

bool calc(long double x)
{
	long double dist1 = x * v1;
	long double dist2 = x * v2;

	long double p1opt = p1 + max(dist1 - (2 * p1), (dist1 - p1) / 2);
	long double p2opt = (n - p2) + max(dist2 - (2 * (n - p2)), (dist2 - (n - p2)) / 2);

	if(p1opt < p1) p1opt = 0;
	if(p2opt < (n - p2)) p2opt = 0;

	return p1opt + p2opt >= n;
}

long double solve()
{
	if(p1 > p2)
	{
		swap(p1,p2);
		swap(v1,v2);
	}

	long double ret = 1e12;
	long double lo = 0;
	long double hi = ret;

	ll cnt = 1000;

	while(cnt--)
	{
		long double mid = (lo + hi) / 2;

		if(calc1(mid) || calc2(mid) || calc3(mid))
		{
			ret = mid;
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}

	return ret;
}

int main()
{
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> p1 >> v1 >> p2 >> v2;

		long double ans = solve();

		cout << setprecision(10) << fixed << ans << "\n";
    }


}



