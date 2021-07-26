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

char grid[103][103];
ll dx[] = {2,-2,1,-1,2,-2,1,-1};
ll dy[] = {1,-1,2,-2,-1,1,-2,2};
bool vis[103][103];

void gen(ll n, ll stx, ll sty)
{
	queue < pair < pll, bool > > q;

	q.push({{stx,sty},1});
	vis[stx][sty] = 1;
	grid[stx][sty] = 'W';

	while(!q.empty())
	{
		pair < pll, bool > top = q.front();
		q.pop();

//		cout << top.first.first << " && " << top.first.second << endl;

		for(int i = 0; i < 8; i++)
		{
			ll nx = top.first.first + dx[i];
			ll ny = top.first.second + dy[i];

			if(nx > n || nx < 1) continue;
			if(ny > n || ny < 1) continue;
			if(vis[nx][ny]) continue;

//			cout << nx << " @ " << ny << endl;

			vis[nx][ny] = 1;

			if(top.second) grid[nx][ny] = 'B';
			else grid[nx][ny] = 'W';

			q.push({{nx,ny}, top.second ^ 1});
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

    slld(n);


    for(i = 1; i <= n; i++) for(j = 1; j <= n; j++) if(vis[i][j] == 0) gen(n,i,j);

    for(i = 1; i <= n; i++)
    {
		for(j = 1; j <= n; j++)
		{
			cout << grid[i][j];
		}

		cout << '\n';
    }


}



