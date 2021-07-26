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

ll arr[10003];
ll dp[(1 << 21)];

ll TLE(ll n, ll m)
{
	memset(dp,0,sizeof dp);

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = i + 1; j <= n; j++)
		{
			ll mask = (arr[i] ^ arr[j]);
			ll orr = (arr[i] | arr[j]);

			if(mask != orr) continue;

			dp[mask]++;

//			cout << mask << endl;
		}
	}

	ll ans = 0;

	for(ll i = 1; i <= n; i++)
	{
		for(ll mask = 0; mask < (1 << 21); mask++)
			{
			ll nmask = mask ^ arr[i];
			ll orr = mask | arr[i];

			if(nmask != orr) continue;

//			if(dp[mask]) cout << i << " " << nmask << " " << mask << endl;

			ans += dp[mask];
		}
	}

	return ans / 3;

}

ll solve(ll n, ll m)
{

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
		slld(n);
		slld(m);

		for(i = 1; i <= n; i++)
		{
			ll num = 0;

			for(j = m - 1; j >= 0; j--)
			{
				slld(input);

				if(input) num += (1 << j);
			}

			arr[i] = num;
		}

		ans = solve(n,m);

		cout << ans << '\n';
    }


}


