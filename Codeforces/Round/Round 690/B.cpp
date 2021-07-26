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

bool solve()
{
	string str;

	string mtr = "2020";

	ll n;

	cin >> n >> str;

	for(ll i = 0; i < 4; i++)
	{
		bool on = 1;
		for(ll ii = 0; ii <= i; ii++)
		{
			if(str[ii] != mtr[ii]) on = 0;
		}

		for(ll j = 3, jj = str.size() - 1; j > i; j--, jj--)
		{
			if(str[jj] != mtr[j]) on = 0;
		}

		if(on) return 1;
	}

	for(ll j = 3, jj = str.size() - 1; j >= 0; j--, jj--)
	{
		if(str[jj] != mtr[j]) return 0;
	}

	return 1;

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
		if(solve()) cout << "YES\n";
		else cout << "NO\n";
    }


}


