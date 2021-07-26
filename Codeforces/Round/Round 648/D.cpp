// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

char grid[55][55];
vector < pll > g, b;
ll dx[] = {-1,1,0,0};
ll dy[] = {0,0,1,-1};
bool vis[55][55];

bool solve(ll n, ll m)
{
	g.clear();
	b.clear();

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(grid[i][j] == 'G') g.push_back({i,j});
			if(grid[i][j] == 'B') b.push_back({i,j});
		}

	if(g.empty()) return 1;

	for(auto it: b)
	{
		for(int i = 0; i < 4; i++)
		{
			ll x = it.first + dx[i];
			ll y = it.second + dy[i];

			if(x < 1 || x > n) continue;
			if(y < 1 || y > m) continue;

			if(grid[x][y] == 'G') return 0;

			if(grid[x][y] == 'B') continue;

			grid[x][y] = '#';
		}
	}

	if(grid[n][m] == '#') return 0;

	memset(vis,0,sizeof vis);

	queue < pll > qq;

	qq.push({n,m});

	vis[n][m] = 1;

	while(!qq.empty())
	{
		pll top = qq.front();
		qq.pop();

		for(int i = 0; i < 4; i++)
		{
			ll x = top.first + dx[i];
			ll y = top.second + dy[i];

			if(x < 1 || x > n) continue;
			if(y < 1 || y > m) continue;

			if(grid[x][y] == '#') continue;

			if(vis[x][y]) continue;

			vis[x][y] = 1;

			qq.push({x,y});
		}
	}

	for(auto it: g)
	{
		if(vis[it.first][it.second] == 0) return 0;
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
		slld(n);
		slld(m);

		for(i = 1; i <= n; i++) scanf("%s", grid[i] + 1);

		if(solve(n,m)) printf("Yes\n");
		else printf("No\n");
    }


}



