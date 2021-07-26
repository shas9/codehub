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

ll x4, x2, x3, y4, y2, y3;

bool one()
{
	return (x4 == x2 && x2 == x3) || (y4 == y2 && y2 == y3);
}

bool two()
{
	if(x4 == x3 && y4 == y2) return 1;
	if(x4 == x2 && y4 == y3) return 1;

	if(x2 == x3 && y4 == y2) return 1;
	if(x4 == x2 && y3 == y2) return 1;

	if(x4 == x3 && y3 == y2) return 1;
	if(x3 == x2 && y4 == y3) return 1;

	if(x2 == x4)
	{
		if(max(y2,y4) <= y3 || min(y2,y4) >= y3) return 1;
	}

	if(x2 == x3)
	{
		if(max(y2,y3) <= y4 || min(y2,y3) >= y4) return 1;
	}

	if(x3 == x4)
	{
		if(max(y3,y4) <= y2 || min(y3,y4) >= y2) return 1;
	}

	swap(x4,y4);
	swap(x2,y2);
	swap(x3,y3);

	if(x2 == x4)
	{
		if(max(y2,y4) <= y3 || min(y2,y4) >= y3) return 1;
	}

	if(x2 == x3)
	{
		if(max(y2,y3) <= y4 || min(y2,y3) >= y4) return 1;
	}

	if(x3 == x4)
	{
		if(max(y3,y4) <= y2 || min(y3,y4) >= y2) return 1;
	}

	return 0;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> x4 >> y4 >> x2 >> y2 >> x3 >> y3)
    {
		if(one()) cout << 1 << "\n";
		else if(two()) cout << 2 << "\n";
		else cout << 3 << "\n";
    }


}



