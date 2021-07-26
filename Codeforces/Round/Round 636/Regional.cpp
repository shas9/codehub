// God put a smile upon your face <3

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

ll mat[23][23];
ll cost[2000006];
ll dp[23][2000006];
ll costfk[23][2000006];

ll solve(ll pos, ll mask)
{
	if(pos == 0) return 0;

	ll &ret = dp[pos][mask];

	if(ret != -1) return ret;


	for(ll submask = mask; ; submask = (submask - 1) & mask)
	{
		ll x = solve(pos - 1, (mask ^ submask) & mask) + costfk[pos][submask];

//		cout << pos << " " << submask << " " << x << endl;
		ret = max(ret, x);

		if(submask == 0) return ret;
	}
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
		slld(k);

		ll tot = 0;

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++)
			{
				slld(mat[i][j]);

				tot += mat[i][j];
			}
		}

		tot = (tot >> 1);

		ll ext = (n - k);

		for(i = 1; i <= n; i++)
		{
			for(j = 0; j <= (1 << ext); j++)
			{
				dp[i][j] = -1;
			}
		}

		for(ll mask = 0; mask < (1 << ext); mask++)
		{
			cost[mask] = 0;
			for(ll i = 0; i <= n; i++)
			{
				for(ll j = i + 1; j <= n; j++)
				{
					if(check(mask,i) && check(mask,j))
					{
						cost[mask] += mat[i + k + 1][j + k + 1];
					}
				}
			}
		}

		for(ll mask = 0; mask < (1 << ext); mask++)
		{
			for(ll i = 1; i <= k; i++)
			{
				costfk[i][mask] = cost[mask];
				for(ll j = 0; j < n; j++)
				{
					if(check(mask,j))
					{
						costfk[i][mask] += mat[i][j + k + 1];

//						cout << costfk[i][mask] << " " << mask << " " << i << " " << j + k + 1 << endl;
					}
				}
			}
		}

		ans = solve(k,(1 << ext) - 1);

		printf("%lld\n", tot - ans);

    }


}


