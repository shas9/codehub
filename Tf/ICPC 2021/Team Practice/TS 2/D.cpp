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

ll col[25][25];
ll dp[25][25];
ll m;

ll comb(ll pos, ll lft)
{
	if(pos == 0) return 1;
	if(lft == 0) return 0;

	ll &ret = col[pos][lft];

	if(ret != -1) return ret;

	ret = 0;

	for(ll i = 0; i <= pos; i++)
	{
		ret += comb(pos - i, lft - 1);
	}

	return ret;
}


ll solve(ll pos, ll sum)
{
	if(sum == 0) return 1;
	if(pos > sum) return 0;

	ll &ret = dp[pos][sum];

	if(ret != -1) return ret;

	ret = 0;

	for(ll i = 0; i * pos <= sum; i++)
	{
		ret += comb(i,m) * solve(pos + 1, sum - (i * pos));
	}

	return ret;
}

int main()
{
    ll i, j, k, l, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		memset(dp,-1,sizeof dp);
		memset(col,-1,sizeof col);

		ans = solve(1,n);

		cout << ans << "\n";
    }

}



