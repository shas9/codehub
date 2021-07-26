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

ll arr[300005];
ll dp[300005][2][2];
ll m, n;

ll solve(ll pos, bool on, bool used)
{
	ll &ret = dp[pos][on][used];

	if(ret != -1) return ret;

	if(pos > n) return ret = 0;

	ret = 0;

	if(on)
	{
		ret = max(ret, solve(pos + 1, 1, 1) + arr[pos] * m);
		ret = max(ret, solve(pos + 1, 0, 1) + arr[pos]);
	}
	else
	{
		if(used)
		{
			ret = max(ret, solve(pos + 1, 0, 1) + arr[pos]);
		}
		else
		{
			ret = max(ret, solve(pos + 1, 0, 0) + arr[pos]);
			ret = max(ret, solve(pos + 1, 1, 1) + arr[pos] * m);
		}
	}

	return ret;

}
int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++) cin >> arr[i];

		memset(dp,-1,sizeof dp);

        ans = 0;

        for(ll i = 1; i <= n; i++) ans = max(ans, solve(i,0,0));

		cout << ans << "\n";

    }


}


