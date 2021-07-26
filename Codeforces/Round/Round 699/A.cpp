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

string s;

ll arr[4];

bool solve(ll x, ll y)
{
	if(x < 0)
	{
		if(arr[2] < abs(x)) return 0;
	}
	else
	{
		if(arr[3] < x) return 0;
	}


	if(y < 0)
	{
		if(arr[1] < abs(y)) return 0;
	}
	else
	{
		if(arr[0] < y) return 0;
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
		ll x, y;
		cin >> x >> y;
		memset(arr,0,sizeof arr);

		cin >> s;

		for(auto it: s)
		{
			if(it == 'U') arr[0]++;
			else if(it == 'D') arr[1]++;
			else if(it == 'L') arr[2]++;
			else arr[3]++;
		}

		if(solve(x,y)) cout << "YES\n";
		else cout << "NO\n";
    }


}


