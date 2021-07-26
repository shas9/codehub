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

#define mod ((int)1e9 + 7)

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

ll newnode[2000006];
ll dp[2000006];

void precalc()
{
	newnode[1] = newnode[2] = 1;
	dp[0] = dp[1] = dp[2] = 0;

	for(ll i = 3; i <= 2000000; i++)
	{
		dp[i] = (dp[i - 3] + newnode[i - 2]) % mod;

		newnode[i] = (2 * newnode[i - 2] + newnode[i - 1]) % mod;
	}

//	for(ll i = 1; i <= 10; i++) cout << dp[i] << " ";
//
//	cout << endl;
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

		ans = (dp[n] * 4) % mod;

		printf("%lld\n", ans);
    }


}

