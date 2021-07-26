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

long double exp_val[2004][2004];
long double p;
bool vis[2004][2004];

long double solve(ll n, ll t)
{
	if(n == 0 || t == 0) return 0;

	if(vis[n][t]) return exp_val[n][t];

	vis[n][t] = 1;

	return exp_val[n][t] = (p * (1 +solve(n - 1, t - 1))) + ((1 - p) * solve(n, t - 1));
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    ll t;


    while(cin >> n >> p >> t)
    {
		memset(vis,0,sizeof vis);

		printf("%.10f\n", (double)solve(n,t));
    }


}


