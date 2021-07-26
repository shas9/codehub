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

double mat[20][20];
double dp[1 << 18];
bool vis[1 << 18];
ll n;

double solve(ll mask)
{
	if(mask + 1 == (1 << n)) return 1;

	double &ret = dp[mask];

	if(vis[mask]) return ret;

	vis[mask] = 1;

	ret = 0;

	ll alive = __builtin_popcount(mask);
	ll totpair = alive * (alive + 1) / 2;

	for(ll i = 0; i < n; i++)
	{
		if(check(mask, i)) continue;

		double sum = 0;

		for(ll j = 0; j < n; j++)
		{
			if(check(mask, j))
			{
				sum += mat[j][i];
			}
		}

		ret += (1.0 / totpair) * sum * solve(Set(mask,i));
	}

	return ret;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;

    while(cin >> n)
    {
		memset(vis,0,sizeof vis);
		for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) cin >> mat[i][j];

		for(ll i = 0; i < n; i++)
		{
			cout << setprecision(10) << fixed << solve(1 << i) << " ";
		}

		cout << endl;
    }


}



