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

void test(int dig)
{
	ll adj = 0;

	dig--;

	for(int i = (1 << dig); i < (1 << (dig + 1)); i++)
	{
		for(int j = 1; j <= 60; j++)
		{
			if(check(i,j) && check(i, j - 1)) adj++;
		}
	}

	printf("%lld\n", adj);
}

ll dp[40];

void precalc()
{
	memset(dp,0,sizeof dp);

	for(int i = 1; i <= 35; i++)
	{
		dp[i] = dp[i - 1] + (1 << (i - 1));
		dp[i] = dp[i] + dp[i - 1];

//		cout << dp[i] << " ";
	}
}

ll solve(ll n, ll bitt, bool on = 0)
{
	if(bitt == 0) return on && n;

	ll ret = 0;

	if(check(n,bitt) == 0) return solve(n,bitt - 1, 0);
	else
	{
		if(on)
		{
//			cout << n << " " << bitt << " " << (n - (1 << bitt) + 1) << endl;
			return ret = dp[bitt - 1] + (n - (1 << bitt) + 1) + solve(n ^ (1 << bitt), bitt - 1, 1);
		}

//		cout << n << ": " <<  bitt - 1 << " " << dp[bitt - 1] << endl;
		return solve(n ^ (1  << bitt), bitt - 1, 1) + dp[bitt - 1];
	}
}

void brute(ll n)
{
	ll adj = 0;


	for(int i = 0; i <= n; i++)
	{
		for(int j = 1; j <= 60; j++)
		{
			if(check(i,j) && check(i, j - 1)) adj++;
		}
	}

	printf("%lld\n", adj);
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	while(cin >> input)
//	{
//		test(input);
//	}

	precalc();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

//		brute(n);
		ans = solve(n,35);

		printf("Case %lld: %lld\n", cs, ans);
    }


}

