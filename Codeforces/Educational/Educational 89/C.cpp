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

ll mat[35][35];
ll lv[100][2];
bool vis[35][35];

ll dx[] = {-1,0,1,0};
ll dy[] = {0,-1,0,1};

ll solve(ll n, ll m)
{
	memset(lv,0,sizeof lv);
	memset(vis,0,sizeof vis);

	queue < pair < pll, pll > > qq;

	qq.push({{1,1},{1,0}});
	qq.push({{n,m},{1,1}});

	lv[1][mat[n][m]]++;
	lv[1][mat[1][1]]++;

	vis[1][1] = 1;
	vis[n][m] = 1;

	ll totdist = n + m - 1;

	while(!qq.empty())
	{
		pair < pll, pll > top = qq.front();

		qq.pop();

		if(top.second.second)
		{
			for(int i = 0; i < 2; i++)
			{
				ll x = dx[i] + top.first.first;
				ll y = dy[i] + top.first.second;

				if(vis[x][y]) continue;
				if(x < 1 || x > n) continue;
				if(y < 1 || y > m) continue;

				lv[top.second.first + 1][mat[x][y]]++;
				vis[x][y] = 1;
				qq.push({{x,y}, {top.second.first + 1, top.second.second}});
			}
		}
		else
		{
			for(int i = 2; i < 4; i++)
			{
				ll x = dx[i] + top.first.first;
				ll y = dy[i] + top.first.second;

				if(vis[x][y]) continue;
				if(x < 1 || x > n) continue;
				if(y < 1 || y > m) continue;

				lv[top.second.first + 1][mat[x][y]]++;
				vis[x][y] = 1;
				qq.push({{x,y}, {top.second.first + 1, top.second.second}});
			}
		}
	}

	ll ret = 0;

	totdist /= 2;
//	cout << totdist << " " << lv[i][0] << " " << lv[i][1] << endl;
	for(int i = 1; i <= totdist; i++)
	{
		ret += min(lv[i][0], lv[i][1]);
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

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(m);

		for(i = 1; i <= n; i++) for(j = 1; j <= m; j++) slld(mat[i][j]);

		ans = solve(n,m);

		printf("%lld\n", ans);
    }


}



