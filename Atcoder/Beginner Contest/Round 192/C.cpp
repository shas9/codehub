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

ll g1(ll x)
{
	string str = "";

	while(x)
	{
		str += (x % 10) + '0';
		x /= 10;
	}

	sort(str.begin(),str.end());

	x = 0;

	for(auto it: str)
	{
		x *= 10;
		x += it - '0';
	}

	return x;
}

ll g2(ll x)
{
	string str = "";

	while(x)
	{
		str += (x % 10) + '0';
		x /= 10;
	}

	sort(str.rbegin(),str.rend());

	x = 0;

	for(auto it: str)
	{
		x *= 10;
		x += it - '0';
	}

	return x;
}

ll f(ll x)
{
	return g2(x) - g1(x);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		for(ll i = 1; i <= k; i++)
		{
			n = f(n);
		}

		cout << n << "\n";
    }


}



