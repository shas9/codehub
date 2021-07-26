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

long double dp[505][505];
bool vis[505][505];

long double solve(ll r, ll b)
{
	if(r == 0 && b == 1) return 1;
	if(r + b == 0) return 0;

	long double &ret = dp[r][b];

	if(vis[r][b]) return ret;

	vis[r][b] = 1;

	if((r + b) & 1)
	{
		if(r) ret += (r * 1.0 / (r + b)) * solve(r - 1,b);
		if(b) ret += (b * 1.0 / (r + b)) * solve(r,b - 1);
	}
	else
	{
		if(b) ret += solve(r, b- 1);
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
		slld(n);
		slld(m);

		long double ans = solve(n,m);

		printf("Case %lld: %.10f\n", cs, (double)ans);
    }


}


