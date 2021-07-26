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

char grid[103][103];

int main()
{
    ll i, j, k, l, am, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) grid[i][j] = 'S';

		for(ll i = 1; i <= n && k; i++)
		{
			for(ll j = 1; j <= n && k; j++)
			{
				if((i + j) % 2 == 0)
				{
					grid[i][j] = 'L';
					k--;
				}
			}
		}

		if(k)
		{
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";

		for(ll i = 1; i <= n; i++) cout << grid[i] + 1 << "\n";
    }


}



