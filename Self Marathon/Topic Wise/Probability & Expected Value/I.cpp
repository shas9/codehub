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

double dp[1003];
ll ans[1003];

void precalc(ll k)
{
	memset(dp,0,sizeof dp);

	dp[0] = 1;

	for(int d = 1, n = 1; d <= 1000; n++)
	{
		for(int x = k; x >= 1; x--)
		{
			dp[x] = (x * dp[x] + (k - x + 1) * dp[x - 1]) / k;
		}

		while(d <= 1000 && (dp[k] * 2000) >= d)
		{
			ans[d] = n;
			d++;
		}

		dp[0] = 0;
	}
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		precalc(n);

		for(i = 1; i <= m; i++)
		{
			slld(input);

			printf("%lld\n", ans[input]);
		}
    }


}



