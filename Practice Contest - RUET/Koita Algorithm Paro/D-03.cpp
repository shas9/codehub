 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
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

ll dp[152][52][52][52];
char grid[152];
vector < ll > v[3];
ll n;
const ll mod = 51123987;

ll solve(ll pos, ll a, ll b, ll c)
{
	if(a >= 52 || b >= 52 || c >= 52) return 0;

	ll &ret = dp[pos][a][b][c];

	if(ret != -1) return ret;

	ret = 0;

	if(a + b + c == n)
	{
		return ret = (abs(a - b) <= 1 && abs(b - c) <= 1 && abs(a - c) <= 1);
	}

	for(ll i = 0; i < 3; i++)
	{
		auto it = upper_bound(v[i].begin(), v[i].end(), pos);

		if(it != v[i].end())
		{
			if(grid[*it] == grid[pos]) continue;

			if(grid[*it] == 'a') ret += solve(*it, a + 1, b, c);
			if(grid[*it] == 'b') ret += solve(*it, a, b + 1, c);
			if(grid[*it] == 'c') ret += solve(*it, a, b, c + 1);
		}
	}

	if(pos)
	{
		if(grid[pos] == 'a') ret += solve(pos, a + 1, b, c);
		if(grid[pos] == 'b') ret += solve(pos, a, b + 1, c);
		if(grid[pos] == 'c') ret += solve(pos, a, b, c + 1);
	}

//	cout << pos << " " << a << " " << b << " " << c << " " << ret << "\n";

	return ret %= mod;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> grid + 1)
    {
		memset(dp,-1,sizeof dp);
		for(ll i = 0; i < 3; i++) v[i].clear();

		for(ll i = 1; i <= n; i++) v[grid[i] - 'a'].pb(i);

		ans = solve(0,0,0,0);

		cout << ans << "\n";
    }


}


