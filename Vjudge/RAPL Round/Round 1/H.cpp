// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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

#define mod 100007

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

ll dp[55][55][5005];

ll solve(ll pos, ll right_empty_cnt, ll sum)
{
	if(sum > 1500) return 0;

	ll &ret = dp[pos][right_empty_cnt][sum + 1500];

	if(ret != -1) return ret;

	if(pos == 0)
	{
		if(right_empty_cnt || sum) return ret = 0;

		return ret = 1;
	}

	ret = 0;

	if(right_empty_cnt)
	{
		ret += solve(pos - 1, right_empty_cnt - 1, sum + pos + pos) * right_empty_cnt;
		ret += solve(pos - 1, right_empty_cnt, sum) * 2;
		ret *= right_empty_cnt;
	}

	ret += solve(pos - 1, right_empty_cnt + 1, sum - pos - pos);
	ret += solve(pos - 1, right_empty_cnt, sum);

	return ret = ret % mod;
}

void precalc()
{
	memset(dp,-1,sizeof dp);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


	precalc();

	slld(testcase);

	for(ll cs = 1; cs <= testcase; cs++)
	{
		slld(n);
		slld(m);

		ans = solve(n,0,m);

		printf("Case #%d: %d\n", cs, ans);
	}

}


