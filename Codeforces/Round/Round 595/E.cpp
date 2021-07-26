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

ll dp[200005][3];
ll n, c;
ll a[200005];
ll b[200005];
ll ans[200005];

ll solve(ll pos, ll st)
{
	if(pos == 1)
	{
		if(st == 0) return 0;

		return c;
	}

	ll &ret = dp[pos][st];

	if(ret != -1) return ret;

	if(st == 1)
	{
		ret = min(solve(pos - 1, 0) + a[pos] + c, solve(pos - 1,1) + b[pos]);
	}
	else
	{
		ret = min(solve(pos - 1, 0) + a[pos], solve(pos - 1,1) + b[pos]);
	}

	ans[pos] = min(ans[pos],ret);

	return ret;
}


int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> c)
    {
		memset(dp,-1,sizeof dp);

		for(i = 2; i <= n; i++)
		{
			slld(a[i]);
		}

		for(i = 2; i <= n; i++)
		{
			slld(b[i]);
		}

		for(i = 1; i <= n; i++) ans[i] = mxlld;

		solve(n,0);

		ans[1] = 0;
		for(i = 1; i <= n; i++) printf("%lld ", ans[i]);

		printf("\n");
    }


}



