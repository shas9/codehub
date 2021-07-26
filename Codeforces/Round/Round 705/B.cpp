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

bool invalid(ll x)
{
	while(x)
	{
		ll y = x % 10;
		x /= 10;

		if(y == 3 || y == 4 || y == 6 || y == 7 || y == 9) return 1;
 	}

 	return 0;
}

ll mirror(ll x)
{
	ll ret = 0;

	ll cnt = 2;

	while(cnt--)
	{
		ret *= 10;
		ll y = x % 10;
		x /= 10;

		if(y == 1) ret += 1;
		if(y == 2) ret += 5;
		if(y == 5) ret += 2;
		if(y == 8) ret += 8;
		if(y == 0) ret += 0;
	}

	return ret;
}

bool isvalid(ll hh, ll mm, ll h, ll m)
{

	if(invalid(hh)) return 0;
	if(invalid(mm)) return 0;

	hh = mirror(hh);
	mm = mirror(mm);

	swap(hh,mm);

	if(hh >= h) return 0;
	if(mm >= m) return 0;

	return 1;
}

void next(ll &hh, ll &mm, ll h, ll m)
{
	mm++;

	if(mm == m)
	{
		mm = 0;
		hh++;
	}

	if(hh == h)
	{
		hh = 0;
	}

	return;
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
		ll hh, mm, h, m;
		char c;

		cin >> h >> m >> hh >> c >> mm;

//		cout << hh << " ++++ " << mm << " " << cs << endl;

		while(isvalid(hh,mm,h,m) == 0)
		{
			next(hh,mm,h,m);
//			break;
		}

		bool on1 = 0, on2 = 0;

		if(hh < 10) on1 = 1;
		if(mm < 10) on2 = 1;

		if(on1) cout << 0;

		cout << hh << ":";

		if(on2) cout << 0;

		cout << mm << "\n";
    }


}



