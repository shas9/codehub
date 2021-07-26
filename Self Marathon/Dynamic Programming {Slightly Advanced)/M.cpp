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

ll dp[55][55][55];
string str[3];

ll solve(ll posa, ll posb, ll posc)
{
	if(posa >= str[0].size()) return 0;
	if(posb >= str[1].size()) return 0;
	if(posc >= str[2].size()) return 0;

	ll &ret = dp[posa][posb][posc];

	if(ret != -1) return ret;

	ret = 0;

	ret = max(ret, solve(posa + 1, posb, posc));
	ret = max(ret, solve(posa, posb + 1, posc));
	ret = max(ret, solve(posa, posb, posc + 1));

	if(str[0][posa] == str[1][posb] && str[1][posb] == str[2][posc])
	{
		ret = max(ret, solve(posa + 1, posb + 1, posc + 1) + 1);
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

		for(i = 0; i < 3; i++) cin >> str[i];

		ans = solve(0,0,0);

		printf("Case %lld: %lld\n", cs, ans);
    }


}



