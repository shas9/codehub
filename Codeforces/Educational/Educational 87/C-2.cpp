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

struct pt{
	double x, y;

	pt(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
};

double angle;
ll n;

pt rot(pt a, pt b, double an)
{
	pt p = pt(a.x - b.x, a.y - b.y);

	pt ret = pt(0,0);

	an = (acos(-1.0) * an) / 180;

	ret.x = p.x*cos(an) - p.y*sin(an);
	ret.y = p.x*sin(an) + p.y*cos(an);

	ret.x += b.x;
	ret.y += b.y;

	return ret;
}

double solve(pt a, pt b)
{
	double mxx = max(a.x,b.x), mnx = min(a.x,b.x), mxy = max(a.y,b.y) ,mny = min(a.y,b.y);

	for(ll i = 1; i <= (n - 2); i++)
	{
		pt c = rot(b,a,angle);
		b = a;
		a = c;

		mxx = max(mxx, a.x);
		mnx = min(mnx, a.x);
		mxy = max(mxy, a.y);
		mny = min(mny, a.y);
	}

	return max(mxx - mnx, mxy - mny);
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		n *= 2;

		pt a = pt(0,0), b(0,1);

		double lo = 0;

		double ans = 0;

		angle = (n - 2) * 180.00 / n;

		m = 100;

		ans = 1000000000;

		double hi = (180 - angle);
		while(m--)
		{
//			cout << lo << " " << hi << endl;
			double mid1 = (lo + (hi - lo) / 3);
			double mid2 = (hi - (hi - lo) / 3);

			pt nb = rot(b,a,mid1);

			double ans1 = solve(a,nb);

			nb = rot(b,a,mid2);

			double ans2 = solve(a,nb);

			if(ans1 < ans2) ans = min(ans,ans1), hi = mid2;
			else lo = mid1, ans = min(ans,ans2);
		}

		printf("%.10f\n", ans);
    }


}



