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

ll dp[(1 << 15)];
ll mat[15][15];
ll n;
ll sum[15][(1 << 15)];

ll solve()
{
	dp[0] = 0;

	for(int i = 0; i < n; i++)
	{
		sum[i][0] = mat[i][i];

		for(int mask = 1; mask < (1 << n); mask++)
		{
			int submask = (mask - 1) & mask;

			int missed = mask ^ submask;

			sum[i][mask] = sum[i][submask] + mat[i][missed];

//			cout << submask << " && " << sum[i][submask] << " " << missed << " " << mat[i][missed] << endl;
			cout << i << ":: " << mask << " " << sum[i][mask] << endl;
		}
	}

	for(int mask = 0; mask < (1 << n); mask++) dp[mask] = 1e10;
	dp[0] = 0;

	for(int mask = 1; mask < (1 << n); mask++)
	{
		for(int j = 0; j < n; j++)
		{
			int nmask = mask;

			if(check(nmask,j))
			{
				int submask = nmask ^ (1 << j);

				dp[mask] = min(dp[mask], dp[submask] + sum[j][submask]);
			}
		}
	}

	return dp[(1 << n) - 1];
}

ll solve1(ll mask)
{
	if(mask == 0) return 0;

	ll &ret = dp[mask];

	if(ret != -1) return ret;

	ret = mxlld;

	for(int i = 0; i < n; i++)
	{
		if(check(mask,i))
		{
			ll nmask = mask ^ (1 << i);
			ll sum = mat[i][i];

			for(int j = 0; j < n; j++)
			{
				if(check(nmask,j)) sum += mat[i][j];
			}

			ret = min(ret, solve1(nmask) + sum);
		}
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
		memset(dp,-1,sizeof dp);

		slld(n);

		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				slld(mat[i][j]);
			}
		}

		ans = solve1((1 << n) - 1);

		printf("Case %lld: %lld\n", cs, ans);
    }


}



