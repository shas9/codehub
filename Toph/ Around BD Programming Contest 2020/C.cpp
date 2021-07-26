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

#define ld long double

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
		ld x, y;

		cin >> x >> y;

		ld r = sqrt(x * x + y * y);

		ld thita = asin(y / r) * 2;

		ld segment = ((r * r * thita) / 2) - (x * y);

		ld side = y + y;

		ld p = (side + side + side) / 2;

		ld tarea = sqrt(p * (p - side) * (p - side) * (p - side));

		ld area = tarea - segment;
		area /= 2.7056023824;

		cout << setprecision(20) << fixed << area<< "\n";
    }


}



