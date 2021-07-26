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

ll dp[103][103][103];
ll arr[103];
ll n;

ll solve(ll lft, ll pos, ll rgt)
{
	if(pos > n) return 0;

	ll &ret = dp[lft][pos][rgt];

	if(ret != -1) return ret;

	ret = solve(lft, pos + 1, rgt);

	if(arr[lft] <= arr[pos] && arr[pos] <= arr[rgt]) ret = max(ret, solve(pos, pos + 1, rgt) + 1);
	if(arr[lft] <= arr[pos] && arr[pos] <= arr[rgt]) ret = max(ret, solve(lft, pos + 1, pos) + 1);

//	cout << lft << " " << pos << " " << rgt << " = " << ret << endl;
	return ret;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);
//
//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		memset(dp,-1,sizeof dp);

		slld(n);

		for(i = 1; i <= n; i++) slld(arr[i]);

		arr[0] = 0;
		arr[n + 1] = 1000000;

		ans = solve(0,1,n + 1);

		printf("Case %lld: %lld\n", cs, ans);
    }



}



