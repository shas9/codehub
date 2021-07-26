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

char grid[2003][2003];
ll dp[2003][2003];
ll dx[] = {1,-1,0,0};
ll dy[] = {0,0,1,-1};

queue < pll > qq;
ll n, m;

bool solve(pll cord)
{
	for(ll i = 0; i < 4; i++)
	{
		ll x = cord.first + dx[i];
		ll y = cord.second + dy[i];

		if(x > n || y > m) return 0;

		if(x < 1 || y < 1) return 0;

		if(grid[cord.first][cord.second] != grid[x][y]) return 0;

		if(dp[cord.first][cord.second] > dp[x][y]) return 0;
	}

	return 1;
}

bool tri(pll top)
{
	for(ll i = 0; i < 4; i++)
	{
		ll x = top.first + dx[i];
		ll y = top.second + dy[i];

		if(x < 1 || x > n) return 0;
		if(y < 1 || y > m) return 0;
		if(grid[x][y] != grid[top.first][top.second]) return 0;
	}

	return 1;
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++) cin >> grid[i] + 1;

		for(ll i = 1; i <= n; i++)
			for(ll j = 1; j <= m; j++)
			{
				if(tri({i,j}))
				{
					dp[i][j] = -1;
				}
				else
				{
					dp[i][j] = 1;
					qq.push({i,j});
				}
			}

		ans = 0;

		while(!qq.empty())
		{
			pll top = qq.front();
			qq.pop();

			ans += dp[top.first][top.second];

			for(ll i = 0; i < 4; i++)
			{
				ll nx = top.first + dx[i];
				ll ny = top.second + dy[i];

				if(grid[top.first][top.second] == grid[nx][ny] && dp[nx][ny] == -1)
				{
					qq.push({nx,ny});
					dp[nx][ny] = 1 + dp[top.first][top.second];
				}
			}
		}

		cout << ans << "\n";
    }


}


