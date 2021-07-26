#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dp[105][105];
ll grid[105][105];
vector < pll > vec[10005];
ll m;

ll solve(ll r, ll c)
{
	ll &ret = dp[r][c];

	if(ret != -1) return ret;

	ret = 0;

	ll num = grid[r][c];

	if(num == m) return ret;

	ret = mxlld;

	for(auto it: vec[num + 1])
	{
		ll dist = abs(it.first - r) + abs(it.second - c);
		ret = min(ret, dist + solve(it.first,it.second));
	}

	return ret;
}

int main()
{
    ll i, j, k, l, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(m);

		for(i = 1; i <= m; i++) vec[i].clear();

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				slld(grid[i][j]);
				dp[i][j] = -1;

				vec[grid[i][j]].push_back({i,j});
			}
		}

		ans = mxlld;

		for(auto it: vec[1])
		{
			ans = min(ans,solve(it.first, it.second));
		}

		printf("%lld\n", ans);
    }


}



