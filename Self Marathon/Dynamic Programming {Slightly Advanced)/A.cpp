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

ll dp[25][5];
ll n;
ll arr[25][4];

ll solve(ll pos, ll prv)
{
	if(pos > n) return 0;

	ll &ret = dp[pos][prv];

	if(ret != -1) return ret;

	ret = mxlld;

	for(int i = 1; i <= 3; i++)
	{
		if(i != prv)
		{
			ret = min(ret, solve(pos + 1, i) + arr[pos][i]);
		}
	}

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
		memset(dp,-1,sizeof dp);

		slld(n);

		for(i = 1; i <= n; i++) for(j = 1; j <= 3; j++) slld(arr[i][j]);

		ans = solve(1,0);

		printf("Case %lld: %lld\n", cs, ans);
    }


}


