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

ll cost[2][1003];
ll jump[2][1003];
ll dp[2][1003];
ll n;

ll solve(ll building, ll floor)
{
	if(floor == n - 1) return cost[building][floor];

	ll &ret = dp[building][floor];

	if(ret != -1) return ret;

	ret = cost[building][floor];

	ret += min(solve(building, floor + 1), solve(building ^ 1, floor + 1) + jump[building][floor]);

	return ret;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		for(i = 0; i < 2; i++) for(j = 0; j < n; j++) slld(cost[i][j]);
		for(i = 0; i < 2; i++) for(j = 0; j < n - 1; j++) slld(jump[i][j]);

		memset(dp,-1,sizeof dp);

		ans = min(solve(0,0), solve(1,0));

		printf("Case %lld: %lld\n", cs, ans);

    }


}



