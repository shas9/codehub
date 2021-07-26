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

ll mat[1003][1003];

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

		for(ll i = 1; i  <= n; i++) mat[i][i] = i;

		if(n % 2 == 0)
		{
			cout << -1 << "\n";
			continue;
		}

//		cout << n << endl;

		for(ll i = 3, now = 2; i <= n; i += 2, now++)
		{
			ll x = 1, y = i;

			while(y >= 1)
			{
				mat[x][y] = now;
				x++;
				y--;
			}
		}

//		cout << n << endl;

		for(ll i = 2, now = (n + 1) / 2 + 1; i <= n; i += 2, now++)
		{
			ll x = i, y = 1;

			while(x >= 1)
			{
				mat[x][y] = now;
				x--;
				y++;
			}
		}

		for(ll i = 2, now = 1; i <= n; i += 2, now++)
		{
			ll x = n, y = i;

			while(y <= n)
			{
				mat[x][y] = now;
				x--;
				y++;
			}
		}

		for(ll i = 3, now = (n + 1) / 2 + 1; i <= n; i += 2, now++)
		{
			ll x = i, y = n;

			while(x <= n)
			{
				mat[x][y] = now;
				x++;
				y--;
			}
		}


//		cout << n << endl;

		for(ll i = 1; i <= n; i++)
		{
			for(ll j = 1; j <= n; j++) cout << mat[i][j] << " ";
			cout << "\n";
		}
    }


}

