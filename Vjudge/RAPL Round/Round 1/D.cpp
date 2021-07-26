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

bool inscribed(long double x1, long double y1, long double r1, long double x2, long double y2, long double r2)
{
	long double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	if(abs(dist - r1) <= 0.00000000001) return 1;

	if(dist < r1) return 1;

	return 0;
}

bool same(long double x1, long double y1, long double r1, long double x2, long double y2, long double r2)
{
	return (abs(x1 - x2) <= 0.00000000001) && (abs(y1 - y2) <= 0.00000000001) && (abs(r1 - r2) <= 0.00000000001);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    long double x1, y1, r1, x2, y2, r2;

    while(cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2)
    {
		long double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

		if(same(x1, y1, r1, x2, y2, r2))
		{
			ans = -1;
		}
		else if(inscribed(x1, y1, r1, x2, y2, r2))
		{
			if(abs(dist + r2 - r1) <= 0.00000000001) ans = 1;
			else if(dist + r2 < r1) ans = 0;
			else ans = 2;
		}
		else if(inscribed(x2,y2,r2,x1,y1,r1))
		{
			swap(x1,x2);
			swap(y1,y2);
			swap(r1,r2);

			if(abs(dist + r2 - r1) <= 0.00000000001) ans = 1;
			else if(dist + r2 < r1) ans = 0;
			else ans = 2;
		}
		else
		{
			if(abs(dist - (r1 + r2)) <= 0.00000000001) ans = 1;
			else if(dist > (r1 + r2)) ans = 0;
			else ans = 2;
		}

		cout << ans << '\n';
    }

}



