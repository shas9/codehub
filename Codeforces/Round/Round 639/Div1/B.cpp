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

char grid[1003][1003];
bool row[1003];
bool col[1003];
set < ll > st1, st2;

bool poss(ll n, ll m)
{
	memset(row,0,sizeof row);
	memset(col,0,sizeof col);
	st1.clear();
	st2.clear();

	for(ll i = 1; i <= n; i++)
	{
		bool on = 0;
		ll cnt = 0;

		for(ll j = 1; j <= m; j++)
		{
//			cout << i << " " << j << endl;
			if(grid[i][j] == '.') cnt++;
			else
			{
				if(cnt && on) return 0;

				on = 1;
				cnt = 0;
			}
		}

		row[i] |= on;
	}

//	bug;

	for(ll i = 1; i <= m; i++)
	{
		bool on = 0;
		ll cnt = 0;

		for(ll j = 1; j <= n; j++)
		{
			if(grid[j][i] == '.') cnt++;
			else
			{
				if(cnt && on) return 0;

				on = 1;
				cnt = 0;
			}
		}

		col[i] |= on;
	}

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= m; j++)
		{
			if(grid[i][j] == '.'&& row[i] == 0 && col[j] == 0)
			{
				st1.insert(i);
				st2.insert(j);
			}

			if(grid[i][j] == '#')
			{
				st1.insert(i);
				st2.insert(j);
			}
		}
	}

	return st1.size() == n && st2.size() == m;
}

bool vis[1003][1003];

ll dx[] = {1,-1,0,0};
ll dy[] = {0,0,1,-1};

void bfs(ll sti,ll stj, ll n, ll m)
{
	queue < pll > qq;

	qq.push({sti,stj});

	vis[sti][stj] = 1;

	while(!qq.empty())
	{
		pll top = qq.front();
		qq.pop();

		for(ll i = 0; i < 4; i++)
		{
			ll x = top.first + dx[i];
			ll y = top.second + dy[i];

			if(x > n || x < 1) continue;
			if(y > m || y < 1) continue;

			if(grid[x][y] == '.') continue;
			if(vis[x][y]) continue;

			vis[x][y] = 1;

			qq.push({x,y});
		}

	}
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
		for(i = 1; i <= n; i++) scanf("%s\n", grid[i] + 1);

		if(!(poss(n,m)))
		{
			printf("-1\n");
			continue;
		}

		memset(vis,0,sizeof vis);

		ans = 0;

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				if(grid[i][j] == '#' && vis[i][j] == 0)
				{
					ans++;

					bfs(i,j,n,m);
				}
			}
		}

		printf("%lld\n", ans);
    }


}



