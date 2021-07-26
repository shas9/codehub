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

ll arr[103];
ll cover[103];
ll dp[100005];
ll n, m;

ll solve(ll pos)
{
	if(pos > m) return 0;

	ll &ret = dp[pos];

	if(ret != -1) return ret;

	ret = (m - pos + 1);

	for(ll i = 1; i <= n; i++)
	{
		if(arr[i] + cover[i] < pos) continue;

		ll need = max(0LL, arr[i] - cover[i] - pos);

		ret = min(ret, need + solve(arr[i] + cover[i] + need + 1));
	}

//	cout << pos << " " << ret << endl;

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
		for(i = 1; i <= n; i++) slld(arr[i]), slld(cover[i]);

		memset(dp,-1,sizeof dp);

		ans = solve(1);

		printf("%lld\n", ans);
    }


}


