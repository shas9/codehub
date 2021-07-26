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

ll dp[(1 << 20)];
ll arr[(1 << 20)];

ll solve()
{
	memset(dp,0,sizeof dp);

	ll mx = 0;

	for(ll i = 0; i < (1 << 20); i++) dp[i] = arr[i], mx = max(mx,dp[i]);

	for(ll i = 0; i < 20; i++)
	{
		for(ll mask = 0; mask < (1 << 20); mask++)
		{
			if(check(mask,i)) dp[i] ^= dp[i ^ (1 << i)];

			mx = max(mx,dp[i]);
		}
	}

	return mx;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++) slld(arr[i]);

    ans = solve();

    printf("%lld\n", ans);
}



