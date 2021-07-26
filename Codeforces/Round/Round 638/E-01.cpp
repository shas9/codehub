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

ll red[503];
ll blue[503];
bool dp[503][503];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	for(i = 1; i <= 1000; i++)
//	{
//		for(j = 1; j <= 1000; j++)
//		{
//			for(k = 2; k <= 100; k++)
//			{
//				ll x = (i + (j % k)) % k;
//				ll y = (i - (j % k) + k) % k;
//				cout << i << " ";
//			}
//		}
//	}

    while(cin >> n >> m)
    {
		ll totr = 0, totb = 0;

		for(i = 1; i <= n; i++)
		{
			slld(red[i]);
			slld(blue[i]);

			totr += red[i];
			totb += blue[i];
		}

		memset(dp,0,sizeof dp);
		dp[1][0] = 1;

		for(i = 1; i <= n; i++)
		{
			for(j = 0; j < m; j++)
			{
				if(dp[i][j] == 0) continue;

				for(k = 0; k <= min(m - 1, red[i]); k++)
				{
					if((red[i] - k) % mod + blue[i] < m) continue;

					dp[i + 1][(j + k) % m] = 1;
				}
			}
		}

		ans = 0;


		for(i = 1; i <= n; i++)
		{
			for(j = 0; j < m; j++)
			{
				if(dp[i + 1][j]) ans = max(ans, (totb + totr - j) / m);
			}
		}

		printf("%lld\n", ans);
	}


}


