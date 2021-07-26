// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

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

long double dp[1001][1001];
bool vis[1001][1001];

long double solve(ll w, ll b)
{
	if(w <= 0) return 0;
	if(b <= 0) return 1;

	long double &ret = dp[w][b];

	if(vis[w][b]) return ret;

	vis[w][b] = 1;

	ret = (w * 1.0 / (w + b));

	long double prob = (b * 1.0 / (w + b));
	b--;

	prob *= (b * 1.0 / (w + b));

	b--;

	if(prob > 0.000000000000001)
	{
		long double black = 0;

		if(b > 0) black = solve(w, b - 1) * (b * 1.0 / (w + b));

		long double white = solve(w - 1, b) * (w * 1.0 / (w + b));

		ret += prob * (black + white);
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

    while(cin >> n >> m)
    {
		memset(dp,0,sizeof dp);
		memset(vis,0,sizeof vis);

		long double x = solve(n,m);

		printf("%.15f\n", (double)x);
    }


}



