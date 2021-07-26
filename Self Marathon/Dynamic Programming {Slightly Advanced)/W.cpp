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

ll arr[103];
ll dp[103][103][2];

ll solve(ll lft, ll rgt, ll pos)
{
	if(lft > rgt) return 0;

	ll &ret = dp[lft][rgt][pos];

	if(ret != -1) return ret;

	if(pos == 0)
	{
		ret = mnlld;

		ll sum = 0;

		for(ll i = lft; i <= rgt; i++)
		{
			sum += arr[i];

			ret = max(ret, solve(i + 1, rgt, pos ^ 1) + sum);
		}

		sum = 0;

		for(ll i = rgt; i >= lft; i--)
		{
			sum += arr[i];

			ret = max(ret, solve(lft, i - 1, pos ^ 1) + sum);
		}
	}
	else
	{
		ret = mxlld;

		ll sum = 0;

		for(ll i = lft; i <= rgt; i++)
		{
			sum += arr[i];

			ret = min(ret, solve(i + 1, rgt, pos ^ 1) - sum);
		}

		sum = 0;

		for(ll i = rgt; i >= lft; i--)
		{
			sum += arr[i];

			ret = min(ret, solve(lft, i - 1, pos ^ 1) - sum);
		}
	}

	return ret;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		memset(dp,-1,sizeof dp);

		slld(n);

		for(i = 1; i <= n; i++) slld(arr[i]);

		ans = solve(1,n,0);

		printf("Case %lld: %lld\n", cs, ans);
    }


}


