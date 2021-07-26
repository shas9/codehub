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

char grid[13][13];

void rot(ll &n, ll &m)
{
	char grid1[13][13];

	for(ll i = 1, jj = n; i <= n, jj >= 1; i++, jj--)
	{
		for(ll j = 1, ii = 1; j <= m; j++, ii++)
		{
			grid1[ii][jj] = grid[i][j];
		}
	}

	for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) grid[i][j] = grid1[i][j];

	return;
}

ll calc(ll n, ll m)
{
	ll ret = 0;

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= m; j++)
		{
			if(grid[i][j] == '#')
			{
				if(grid[i - 1][j] == '.')
				{
					if(grid[i - 1][j - 1] == '#') ret++;
					else if(grid[i][j - 1] == '.') ret++;
				}
			}
		}
	}

	return ret;
}

ll solve(ll n, ll m)
{
	ll ret = 0;

	for(ll i = 1; i <= 4; i++)
	{
		ret += calc(n, m);
		rot(n,m);
	}

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++) cin >> grid[i] + 1;

		if(n < m)
		{
			for(ll i = n + 1; i <= max(n,m); i++)
			{
				for(ll j = 1; j <= max(n,m); j++) grid[i][j] = '.';
			}
		}
		else
		{
			for(ll i = 1; i <= max(n,m); i++)
			{
				for(ll j = m + 1; j <= max(n,m); j++) grid[i][j] = '.';
			}
		}

		n = m = max(n,m);

		cout << solve(n,m) << "\n";
    }


}


