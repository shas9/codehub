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

ll arr[2003];
ll dp[2003][2003];
const ll mod = (1e9) + 7;
ll n, k;

ll solve(ll pos, ll num)
{
	ll &ret = dp[pos][num];

	if(ret != -1) return ret;

	if(pos == k) return ret = 1;

	ret = 0;

	for(ll i = num; i <= n; i += num)
	{
		ret += solve(pos + 1, i);
	}

	return ret = ret % mod;
}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		memset(dp,-1,sizeof dp);
		ans = 0;

		for(ll i = 1; i <= n; i++) ans += solve(1, i);

		cout << ans % mod << "\n";
    }


}


