 // God put a smile upon your face <3

#include <bits/stdc++.h>

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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dp[(1 << 10)];
ll arr[15];
ll n;


ll solve(ll mask)
{
	if(mask == (1 << n) - 1) return 0;

	ll &ret = dp[mask];

	if(ret != -1) return ret;

	ret = 0;

	ll lft = -1;
	ll rgt = -1;

	for(ll i = 0; i < n; i = rgt)
	{
		if(check(mask,i) == 0)
		{
			rgt = -1;
			for(ll j = i + 1; j < n; j++)
			{
				if(check(mask,j) == 0)
				{
					rgt = j;
					break;
				}
			}

			if(lft == -1 && rgt == -1) return ret = 0;

			if(lft == -1) ret = max(ret, solve(Set(mask, i)) + arr[rgt]);
			else if(rgt == -1)
			{
				ret = max(ret, solve(Set(mask, i)) + arr[lft]);
				break;
			}
			else ret = max(ret, solve(Set(mask, i)) + arr[lft] * arr[rgt]);

			lft = i;
		}
	}

//	cout << mask << " " << ret << "\n";

	return ret;
}
int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		memset(dp, -1, sizeof dp);

		for(ll i = 0; i < n; i++) cin >> arr[i];

		ans = solve(0);

		cout << ans << "\n";
    }


}



