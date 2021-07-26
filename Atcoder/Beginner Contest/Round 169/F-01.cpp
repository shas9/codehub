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

#define mod 998244353

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

ll dp[3003][3003];
ll arr[3003];
ll S;

ll solve(ll pos, ll sum)
{
	if(sum > S) return 0;

	ll &ret = dp[pos][sum];

	if(ret != -1) return ret;

	if(pos == 0) return ret = (sum == S);

	ret = (solve(pos - 1, sum + arr[pos]) + solve(pos - 1, sum) * 2) % mod;

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> S)
    {
		memset(dp,-1,sizeof dp);

		for(i = 1; i <= n; i++) slld(arr[i]);

		ans = solve(n,0);

		cout << ans << '\n';
    }


}


