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

ll dp[16][(1 << 16)];
vector < pll > gold;
pll me;
char grid[25][25];

ll dist(pll a, pll b)
{
	return max(abs(a.first - b.first), abs(a.second - b.second));
}

ll solve(ll prv, ll mask)
{
	if(mask == (1 << gold.size()) - 1)
	{
		return dist(gold[prv], gold[0]);
	}

	ll &ret = dp[prv][mask];

	if(ret != -1) return ret;

	ret = 1e9;

	for(ll i = 0; i < gold.size(); i++)
	{
		if(check(mask,i)) continue;

		ret = min(ret, solve(i,Set(mask,i)) + dist(gold[i], gold[prv]));
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

		memset(dp,-1,sizeof dp);
		gold.clear();

		for(i = 0; i < n; i++)
		{
			scanf("%s", grid[i]);

			for(j = 0; j < m; j++)
			{
				if(grid[i][j] == 'x') me = {i,j};
			}
		}

		gold.push_back(me);
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < m; j++)
			{
				if(grid[i][j] == 'g') gold.push_back({i,j});
			}
		}

		ans = solve(0,1);

		printf("Case %lld: %lld\n", cs, ans);
    }


}



