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

ll mat[25][25];
ll dist[25][25];
ll dx[] = {-1,1,0,0};
ll dy[] = {0,0,1,-1};

pll solve(ll x, ll y, ll n, ll m)
{
	for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) dist[i][j] = -1;

	dist[x][y] = 0;

	queue < pll > q;

	q.push({x,y});

	ll cnt = 0;
	ll tot = 0;

	while(!q.empty())
	{
		pll top = q.front();
		q.pop();

		for(ll i = 0; i < 4; i++)
		{
			ll nx = top.first + dx[i];
			ll ny = top.second + dy[i];

			if(nx >= n || ny >= m) continue;
			if(nx < 0 || ny < 0) continue;
			if(dist[nx][ny] != -1) continue;
			if(mat[nx][ny] == 0) continue;

			dist[nx][ny] = dist[top.first][top.second] + 1;

			if(mat[nx][ny] == 2)
			{
				cnt++;
				tot = max(tot, dist[nx][ny]);
			}
			else if(mat[nx][ny] == 3)
			{
				cnt++;
				tot = max(tot, dist[nx][ny]);
				q.push({nx,ny});
			}
			else
			{
				q.push({nx,ny});
			}
		}
	}

//	cout << x << " " << y << " == " << cnt << " " << tot << endl;
	return {tot,cnt};
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> k >> n >> m)
    {
		for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cin >> mat[i][j];

		for(ll i = 0; i < k; i++)
		{
			ll x, y;
			cin >> x >> y;
			mat[x][y] += 2;
		}

		ans = mxlld;
		for(ll i = 0; i < n; i++)
		{
			for(ll j = 0; j < m; j++)
			{
				if(mat[i][j] == 0)
				{
					pll get = solve(i,j,n,m);

					if(get.second != k) continue;

					ans = min(ans, get.first);
				}
			}
		}

		if(ans == mxlld) ans = -1;

		cout << ans << "\n";

    }


}



