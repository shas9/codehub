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
ll n;
char mat[15][15];
ll arr[15];

ll solve(ll mask)
{
	if(mask == 0) return 0;

	ll &ret = dp[mask];

	if(ret != -1) return ret;

	ret = mxlld;

	for(ll i = 0; i < n; i++)
	{
		if(check(mask,i))
		{
			ll nmask = mask ^ (1 << i);
			ll shot = 0;
			ll mxdamage = 1;

			for(ll j = 0; j < n; j++)
			{
				if(check(nmask,j))
				{
					ll x = mat[j][i] - '0';

					mxdamage = max(mxdamage, x);
				}
			}

			shot = arr[i] / mxdamage;

			if(arr[i] % mxdamage) shot++;

//			if(mask == 3) cout << i << ":  " << shot << " " <<  mxdamage << endl;

			ret = min(ret, solve(nmask) + shot);
		}
	}

//	cout << mask << " " << ret << endl;

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

		for(i = 0; i < n; i++) slld(arr[i]);

		for(i = 0; i < n; i++)
		{
			scanf("%s", mat[i]);
		}

		memset(dp,-1,sizeof dp);

		ans = solve((1 << n) - 1);

		printf("Case %lld: %lld\n", cs, ans);
    }


}



