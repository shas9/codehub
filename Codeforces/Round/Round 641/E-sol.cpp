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
ll dist[1003][1003];
ll adx[] = {1,-1,0,0};
ll ady[] = {0,0,1,-1};

void bfs(ll n, ll m)
{
	queue < pll > q;

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= m; j++)
		{
			for(ll k = 0; k < 4; k++)
			{
				ll x = i + adx[k];
				ll y = j + ady[k];

				if(x > n || x == 0 || y > m || y == 0) continue;

				if(grid[x][y] == grid[i][j])
				{
					q.push({i,j});
					dist[i][j] = 0;
					break;
				}
			}
		}
	}

	while(!q.empty())
	{
		pll top = q.front();
		q.pop();

		for(ll i = 0; i < 4; i++)
		{
			ll x = top.first + adx[i];
			ll y = top.second + ady[i];

			if(x > n || x == 0 || y > m || y == 0) continue;

			if(dist[x][y] != -1) continue;

			dist[x][y] = dist[top.first][top.second] + 1;

			q.push({x,y});
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

    while(cin >> n >> m >> testcase)
    {
		for(i = 1; i <= n; i++)
		{
			scanf("%s", grid[i] + 1);
		}

		memset(dist,-1,sizeof dist);

		bfs(n,m);

		while(testcase--)
		{
			ll x, y, z;
			slld(x);
			slld(y);
			slld(z);

			if(dist[x][y] >= z || dist[x][y] == -1) cout << grid[x][y] << "\n";
			else
			{
				z -= dist[x][y];

				char c = grid[x][y];

				if(z % 2)
					if(c == '1') c = '0';
					else c = '1';

				cout << c << "\n";
			}
		}
    }



}



