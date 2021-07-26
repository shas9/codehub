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

ll ax, ay, bx, by, cx, cy, dx, dy;

double calc(double mid)
{
	double dist = sqrt((ax - bx) * (ax - bx) + (ay - by)*(ay - by));

	double x1 = (((ax * (dist - mid)) + (bx * mid)) / (dist));
	double y1 = (((ay * (dist - mid)) + (by * mid)) / (dist));

	double x2 = (((cx * (dist - mid)) + (dx * mid)) / (dist));
	double y2 = (((cy * (dist - mid)) + (dy * mid)) / (dist));

	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

}
double solve()
{
	double dist = sqrt((ax - bx) * (ax - bx) + (ay - by)*(ay - by));

	double lo = 0;
	double hi = dist;

	ll cnt = 1000;

	double ret = 0;

	while(cnt--)
	{
		double mid1 = (lo + (hi - lo) / 3);
		double mid2 = (hi - (hi - lo) / 3);

		double x = calc(mid1);
		double y = calc(mid2);

//		cout << mid1 << " " << x << " " << mid2 << " " << y << endl;

		if(x <= y) hi = mid2, ret = x;
		else lo = mid1, ret = y;

		if(abs(lo - hi) <= 0.000000001) break;
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

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(ax);
		slld(ay);
		slld(bx);
		slld(by);
		slld(cx);
		slld(cy);
		slld(dx);
		slld(dy);

		double ans = solve();

		printf("Case %lld: %.10f\n", cs, ans);
    }


}


