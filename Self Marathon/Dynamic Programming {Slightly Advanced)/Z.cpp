// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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

ll dp[55][5][5];
char str[55];
ll sz;

ll solve(ll pos, ll con, ll vow)
{
	if(con == 5) return 0;
	if(vow == 3) return 0;
	if(pos == sz) return 1;

	ll &ret = dp[pos][con][vow];

	if(ret != -1) return ret;

	ret = 0;

	bool bad = 0;
	bool good = 0;

	if(str[pos] == '?')
	{
		ll x = solve(pos + 1, con + 1, 0);
		if(x == 0) bad = 1;
		if(x == 1) good = 1;
		ret = max(ret, x);

		x = solve(pos + 1, 0, vow + 1);
		if(x == 0) bad = 1;
		if(x == 1) good = 1;

		ret = max(ret, x);

	}
	else if(str[pos] == 'A' || str[pos] == 'E' || str[pos] == 'I' || str[pos] == 'O' || str[pos] == 'U')
	{
		ll x = solve(pos + 1, 0, vow + 1);
		if(x == 0) bad = 1;
		if(x == 1) good = 1;

		ret = max(ret, x);

	}
	else
	{
		ll x = solve(pos + 1, con + 1, 0);
		if(x == 0) bad = 1;
		if(x == 1) good = 1;

		ret = max(ret, x);

	}

	if(bad && good) ret = 2;

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
		scanf("%s", str);

		sz = strlen(str);

		memset(dp,-1,sizeof dp);

		ans = solve(0,0,0);

		printf("Case %d: ", cs);

		if(ans == 0) printf("BAD\n");
		else if(ans == 2) printf("MIXED\n");
		else printf("GOOD\n");
    }


}



