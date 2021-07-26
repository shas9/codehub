// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

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

ll dp[101][101];
string str;

ll solve(ll lft, ll rgt)
{
	if(lft == rgt) return 1;
	if(lft > rgt) return 0;

	ll &ret = dp[lft][rgt];

	if(ret != -1) return ret;

	ret = 1e5;

	if(str[lft] == str[rgt]) ret = min(ret, solve(lft + 1, rgt - 1) + 2);
	else ret = min(ret, min(solve(lft + 1, rgt) + 2, solve(lft, rgt - 1) + 2));

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

		cin >> str;

		ll sz = str.size();

		ans = solve(0,str.size() - 1);

//		cout << ans << " ";

		ans = ans - sz;

		printf("Case %lld: %lld\n", cs, ans);
    }


}



