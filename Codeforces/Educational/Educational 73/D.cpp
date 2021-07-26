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

ll arr[300005];
ll brr[300005];
ll dp[300005][5];
ll n;

ll solve(ll pos, ll inc)
{
	if(pos > n) return 0;

	ll &ret = dp[pos][inc];

	if(ret != -1) return ret;

	ll prv = inc + arr[pos - 1];

	ret = mxlld;

	for(int i = 0; i <= 4; i++)
	{
		ll now = i + arr[pos];

		if(now == prv) continue;

		ret = min(ret, solve(pos + 1, i) + (i * brr[pos]));
	}

	return ret;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		for(i = 1; i <= n; i++) slld(arr[i]), slld(brr[i]);

		for(i = 0; i <= (n + 2); i++)
		{
			for(j = 0; j <= 4; j++) dp[i][j] = -1;
		}

		ans = solve(1,0);

		cout << ans << '\n';
    }


}



