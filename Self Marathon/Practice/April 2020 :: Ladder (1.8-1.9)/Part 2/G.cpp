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

ll val[5005];
ll arr[5005];
ll dp[5005][5005];
ll n, m, k;

ll solve(ll pos, ll rem)
{
	ll &ret = dp[pos][rem];

	if(ret != -1) return ret;

	if(pos > (n - m + 1))
	{
		if(rem == 0) return 0;

		return mnlld;
	}

	ret = 0;

	ret = max(solve(pos + m, rem - 1) + val[pos], solve(pos + 1, rem));

	return ret;
}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
		}

		memset(val,0,sizeof val);

		for(i = 1; i <= n - m + 1; i++)
		{
			for(j = 1; j <= k; j++) dp[i][j] = -1;
		}

		for(i = 1; i <= (n - m + 1); i++)
		{
			for(j = i; j <= (i + m - 1); j++)
			{
				val[i] += arr[j];
			}
		}

		ans = solve(1,k);

		printf("%lld\n", ans);
    }


}

