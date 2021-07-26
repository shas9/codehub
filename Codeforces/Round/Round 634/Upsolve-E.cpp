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

#define mod 998244353


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
char ss[5003];
char tt[5003];
ll ln;
ll lnt;

ll solve()
{
	ll ret = 0;

	for(ll i = 1; i <= ln + 1; i++) dp[i][0] = 1;

	for(ll len = 1; len <= ln; len++)
	{
		for(ll i = 1; i + len - 1 <= ln; i++)
		{
			ll j = i + len - 1;

			if(tt[i] == '$' || tt[i] == ss[len])
			{
				dp[i][len] += dp[i + 1][len - 1];
			}

			if(tt[j] == '$' || tt[j] == ss[len])
			{
				dp[i][len] += dp[i][len - 1];
			}

			dp[i][len] %= mod;
		}

		if(len >= lnt)
		{
			ret = (ret + dp[1][len]) % mod;
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

    while(scanf("%s %s", ss + 1, tt + 1) != EOF)
    {
		ln = strlen(ss + 1);
		ll ln1 = strlen(tt + 1);
		lnt = ln1;

		memset(dp,0,sizeof dp);

		while(ln1 < ln)
		{
			tt[++ln1] = '$';
		}

		ans = solve();

		printf("%lld\n", ans);
    }


}



