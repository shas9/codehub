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

ll dp[100005][3];
ll arr[100005][3];
ll n;

ll solve(ll pos, ll mark)
{
	ll &ret = dp[pos][mark];

	if(ret != -1) return ret;
	if(pos > n) return 0;

	ret = 0;

	if(mark == 0)
	{
		ret = max(ret, solve(pos + 1, 1) + arr[pos][1]);
		ret = max(ret, solve(pos + 1, 2) + arr[pos][2]);
		ret = max(ret, solve(pos + 1, 0));
	}
	else if(mark == 1)
	{
		ret = max(ret, solve(pos + 1, 2) + arr[pos][2]);
		ret = max(ret, solve(pos + 1, 0));
	}
	else
	{
		ret = max(ret, solve(pos + 1, 1) + arr[pos][1]);
		ret = max(ret, solve(pos + 1, 0));
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

    while(cin >> n)
    {
		for(ll i = 1; i <= 2; i++) for(ll j = 1; j <= n; j++) cin >> arr[j][i];

		memset(dp,-1,sizeof dp);

		ans = solve(1,0);

		cout << ans << "\n";
    }


}


