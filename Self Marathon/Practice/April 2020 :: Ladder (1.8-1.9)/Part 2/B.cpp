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

ll dp[200005][2];
ll arr[200005];
ll n;

ll solve(ll x, ll step)
{
	if(x <= 0 || x > n) return 0;

	ll &ret = dp[x][step];

	if(ret != -1) return ret;

	ret = mnlld;

	if(step == 0) ret = solve(x + arr[x], step ^ 1);
	else ret = solve(x - arr[x], step ^ 1);

	ret += arr[x];

	return ret;
}
int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    while(cin >> n)
    {
		memset(dp,-1,sizeof dp);

		for(i = 2; i <= n; i++) slld(arr[i]);

		dp[1][0] = mnlld;
		for(i = 2; i <= n; i++)
		{
			ans = solve(i,1) + i - 1;

			if(ans < 0) ans = -1;

			printf("%lld\n", ans);
		}
    }


}



