
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

bool vis[101][101];

void dfs(ll x, ll y, ll dir, ll step)
{
	if(step == 0)
	{
		vis[x][y] = 1;
		return;
	}

	if(dir == 0)
	{
		dfs(x + 1, y, 1, step - 1);
		dfs(x - 1, y, 1, step - 1);
		dfs(x, y + 1, 2, step - 1);
		dfs(x, y - 1, 2, step - 1);
	}
	else if(dir == 1)
	{
		dfs(x, y + 1, 2, step - 1);
		dfs(x, y - 1, 2, step - 1);
	}
	else
	{
		dfs(x + 1, y, 1, step - 1);
		dfs(x - 1, y, 1, step - 1);
	}
}

void brute(ll step)
{

	memset(vis,0,sizeof vis);

	dfs(40,40,0,step);

	ll cnt = 0;

	for(ll i = 1; i <= 100; i++) for(ll j = 1; j <= 100; j++) cnt += vis[i][j] == 1;

	cout << cnt << endl;

}

ll dp[1001];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


	ll cnt = 2;

	for(ll i = 2; i <= 1000; i += 2, cnt++) dp[i] = cnt * cnt;

	cnt = 8;
	dp[1] = 4;

	for(ll i = 3; i <= 1000; i += 2, cnt += 4) dp[i] = dp[i - 2] + cnt;

    while(cin >> n)
    {
		cout << dp[n] << "\n";
    }


}


