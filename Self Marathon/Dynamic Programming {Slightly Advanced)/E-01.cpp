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

ull pw[30];
ll dp[30][200];

ull solve(ll n, ll x)
{
	if(x <= 0) return pw[n];

	if(n == 0) return 0;

	ll &ret = dp[n][x];

	if(ret != -1) return (unsigned long long)ret;

	ret = 0;

	for(ll i = 1; i <= 6; i++)
	{
		ret += solve(n - 1, x - i);
	}

	return (unsigned long long)ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	pw[0] = 1;

	for(i = 1; i <= 25; i++)
	{
		pw[i] = pw[i - 1] * 6;
	}

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(m);

		memset(dp,-1,sizeof dp);

		ull ans = solve(n,m);

		ull g = __gcd(ans,pw[n]);

		ull f = ans / g;
		ull s = pw[n] / g;

		if(s == 1) printf("Case %lld: %llu\n", cs, f);
		else printf("Case %lld: %llu/%llu\n", cs, f,s);
    }


}



