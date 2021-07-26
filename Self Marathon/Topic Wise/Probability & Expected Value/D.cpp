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

double dp[10001];
double p, arr[101];
ll n, cost[101];

bool small(double x)
{
	if(abs(x-p) <= 0.000000001) return 0;

	if(x < p) return 1;

	return 0;
}

double calc(double x, double y)
{
	double ret = x + (1 - x) * y;

	return ret;
}

ll tot;

ll solve(ll pos)
{
	if(pos > n)
	{
		ll ret = 0;

//		cout << " " << p << ": ";
		for(int i = 1; i <= tot; i++)
		{
//			cout << dp[i] << " ";
			if(dp[i] >= p)
			{
				ret = i;
			}
		}

//		cout << endl;
//
		return ret;
	}

	for(int j = tot; j >= cost[pos]; j--)
	{
		dp[j] = max(dp[j], dp[j - cost[pos]] * (1 - arr[pos]));
	}

	return solve(pos + 1);
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		memset(dp,0,sizeof dp);
		dp[0] = 1;

		cin >> p >> n;

		p = 1 - p;

		tot = 0;

		for(i = 1; i <= n; i++) cin >> cost[i] >> arr[i], tot += cost[i];

		ans = solve(1);

		printf("Case %lld: %lld\n", cs, ans);
    }


}


