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

#define mod 1000000009

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

vector < ll > g[1003];
ll dp[1003];
ll base_i[1003];
string str;

void precalc()
{
	for(ll i = 0; i <= 1000; i++) g[i].clear();

	base_i[0] = 1;

	for(ll i = 1; i <= 1000; i++) base_i[i] = (base_i[i - 1] * base) % mod;

	for(ll i = 0; i < str.size(); i++)
	{
		ll f = 0;
		ll r = 0;

		for(ll j = i; j < str.size(); j++)
		{
			f = ((f * base) + str[j]) % mod;
			r = ((str[j] * base_i[j - i]) + r) % mod;

			if(f == r) g[i].pb(j);
		}
	}

//	for(ll i = 0; i < str.size(); i++)
//	{
//		cout << i << ": ";
//
//		for(auto it: g[i]) cout << it << " ";
//
//		cout << endl;
//	}
}

ll solve(ll pos)
{
	if(pos == str.size()) return 0;

	if(dp[pos] != -1) return dp[pos];

	dp[pos] = mxlld;

	for(auto it: g[pos])
	{
		dp[pos] = min(dp[pos], solve(it + 1) + 1);
 	}

 	return dp[pos];
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
		cin >> str;

		precalc();

		memset(dp,-1,sizeof dp);

		ans = solve(0);

		printf("Case %lld: %lld\n", cs, ans);
    }


}



