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

ll a[1003][1003];
ll b[1003][1003];

char aa[1003][1003];
char bb[1003][1003];


bool solve(ll n)
{
	for(ll i = 1; i <= n; i++)
	{
		if(a[i][1] == b[i][1]) continue;

		for(ll j = 1; j <= n; j++) a[i][j] ^= 1;
	}

	for(ll j = 1; j <= n; j++)
	{
		if(a[1][j] == b[1][j]) continue;

		for(ll i = 1; i <= n; i++) a[i][j] ^= 1;
	}

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= n; j++) if(a[i][j] != b[i][j]) return 0;
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
		cin >> n;

		for(ll i = 1; i <= n; i++)
		{
			cin >> aa[i] + 1;
			for(ll j = 1; j <= n; j++) a[i][j] = aa[i][j] - '0';
		}

		for(ll i = 1; i <= n; i++)
		{
			cin >> bb[i] + 1;
			for(ll j = 1; j <= n; j++) b[i][j] = bb[i][j] - '0';
		}

		if(solve(n)) cout << "YES\n";
		else cout << "NO\n";
    }


}


