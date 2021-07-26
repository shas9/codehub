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

pll dp[30][160];

pll solve(ll n, ll sum)
{
	if(n == 0) return {sum <= 0,1};
	if(sum <= 0) return {1,1};

	pll &ret = dp[n][sum];

	if(ret.first != -1) return ret;

	ret = {0,0};

	for(int i = 1; i <= 6; i++)
	{
		pll x = solve(n - 1, sum - i);
		ret.first *= x.first;
		ret.second *= x.second;
	}

	ret.second *= 6;

	ll g = __gcd(ret.first,ret.second);

	ret.first /= g;
	ret.second /= g;

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
		slld(m);

		pll ans = solve(n,m);

		if(ans.second > 1) printf("Case %lld: %lld/%lld\n", cs, ans.first, ans.second);
		printf("Case %lld: %lld/%lld\n", cs, ans.first);
    }


}



