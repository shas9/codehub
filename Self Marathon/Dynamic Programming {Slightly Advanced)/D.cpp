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

ll dp[100][100];
string str;
vector < ll > g[100];

ll solve(ll lft, ll rgt)
{
	if(lft >= rgt) return 0;

//	assert(lft <= 60 && rgt >= 0);

	ll &ret = dp[lft][rgt];

	if(ret != -1) return ret;

	ret = 0;

	if(str[lft] == str[rgt])
	{
		ret = (rgt - lft);

		for(ll i = lft + 1; i < rgt; i++)
		{
			for(auto it: g[i])
			{
				if(it >= rgt) break;

				ret += solve(i, it);
			}
		}
	}

	return ret;

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
		memset(dp,-1,sizeof dp);

		for(i = 0; i <= 65; i++) g[i].clear();

		cin >> str;

		for(i = 0; i < str.size(); i++)
		{
			for(j = i + 1; j < str.size(); j++)
			{
				if(str[i] == str[j]) g[i].pb(j);
			}
		}

		ans = str.size();

		for(i = 0; i < str.size(); i++)
		{
			for(j = i + 1; j < str.size(); j++)
			{
				ans += solve(i,j);
			}
		}
		printf("Case %lld: %lld\n", cs, ans);
    }


}



