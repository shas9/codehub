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

const ll md = 100000000;
ll k1, k2;
ll dp[103][103];

ll solve(ll n1, ll n2)
{
	if(n1 < 0 || n2 < 0) return 0;
	if(n1 == 0 && n2 == 0) return 2;

	if(n1 == 0)
	{
		if(n2 <= k2) return 1;
		return 0;
	}

	if(n2 == 0)
	{
		if(n1 <= k1) return 1;
		return 0;
	}

	ll &ret = dp[n1][n2];

	if(ret != -1) return ret;

	ret = 0;

	for(ll i = 1; i <= k1; i++)
	{
		for(ll j = 1; j <= k2; j++)
		{
			ret = (ret + solve(n1 - i, n2 - j)) % md;
		}
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

    while(cin >> n >> m >> k1 >> k2)
    {
		memset(dp,-1,sizeof dp);

		ans = solve(n,m);

		printf("%lld\n", ans);
    }


}


