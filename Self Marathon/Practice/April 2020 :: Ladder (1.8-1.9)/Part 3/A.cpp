// God put a smile upon your face <3

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

#define mod 1000000007

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

ll arr[2003];

ll dp[2003][2003];
ll n, m;

ll solve(ll pos, ll cover)
{
	if(pos > n)
	{
		if(cover == 0) return 1;

		return 0;
	}

	ll &ret = dp[pos][cover];

	if(ret != -1) return ret;

	ret = 0;

	if(arr[pos] + cover > m) return ret = 0;

	if(arr[pos] + cover + 1 < m) return ret = 0;

	if(arr[pos] + cover < m) ret += solve(pos + 1, cover + 1); // Opening a segment

	if(arr[pos] + cover < m && cover) ret += solve(pos + 1, cover) * cover; // Ending a segment and start from it

	if(arr[pos] + cover < m) ret += solve(pos + 1, cover); // Opening a segment of size 1

	if(arr[pos] + cover == m && cover) ret += solve(pos + 1, cover - 1) * cover; // Closing a segment

	if(arr[pos] + cover == m) ret += solve(pos + 1, cover); // Do nothing

//	cout << pos << " " << cover << " " << ret << endl;
	return ret = ret % mod;
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
		for(i = 1; i <= n; i++) slld(arr[i]);

		memset(dp,-1,sizeof dp);

		ans = solve(1,0);

		printf("%lld\n", ans);
    }


}


