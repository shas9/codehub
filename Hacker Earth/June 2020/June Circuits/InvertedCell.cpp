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

#define mod 1000004207

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

ll dp[1003][1003][2];
ll n, m;
char str[1003][1003];

ll solve1(ll i, ll j)
{
	ll &ret = dp[i][j][1];

	if(ret != -1) return ret;

	if(str[i][j] == '#') return ret = 0;

	if(i == n && j == m) return ret = 1;

	ret = 0;

	if(i < n) ret += solve1(i + 1, j);
	if(j < m) ret += solve1(i, j + 1);

	return ret;
}

ll solve2(ll i, ll j)
{
	ll &ret = dp[i][j][0];

	if(ret != -1) return ret;

	if(str[i][j] == '#') return ret = 0;

	if(i == 1 && j == 1) return ret = 1;

	ret = 0;

	if(i > 1) ret += solve2(i - 1, j);
	if(j > 1) ret += solve2(i, j - 1);

	return ret;
}

void solve()
{
	memset(dp,0,sizeof dp);

	for(ll i = 0; i <= n + 2; i++) for(ll j = 0; j <= m + 2; j++) for(ll k = 0; k < 2; k++) dp[i][j][k] = 0;

	dp[n][m + 1][1] = 1;
	dp[1][1 - 1][0] = 1;

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= m; j++)
		{
			if(str[i][j] == '.') dp[i][j][0] = (dp[i - 1][j][0] + dp[i][j - 1][0]) % mod;
		}
	}

	for(ll i = n; i >= 1; i--)
	{
		for(ll j = m; j >= 1; j--)
		{
			if(str[i][j] == '.') dp[i][j][1] = (dp[i + 1][j][1] + dp[i][j + 1][1]) % mod;
		}
	}

//	for(ll i = 1; i <= n; i++)
//	{
//		for(ll j = 1; j <= m; j++)
//		{
//			cout << dp[i][j][1] * dp[i][j][0] << " ";
//		}
//		cout << endl;
//	}

	return;
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(i = 1; i <= n; i++) scanf("%s", str[i] + 1);

		solve();

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				if(str[i][j] == '#')
				{
					{
						ll upor = 0, nich = 0;

						upor = dp[i - 1][j][0] + dp[i][j - 1][0];
						nich = dp[i + 1][j][1] + dp[i][j + 1][1];

						ll cnt = (upor * nich) % mod;

						if(cnt + dp[1][1][1]) printf("1");
						else printf("0");
					}
				}
				else if(str[i][j] == '.')
				{
					{
						ll upor = 0, nich = 0;

						upor = dp[i - 1][j][0] + dp[i][j - 1][0];
						nich = dp[i + 1][j][1] + dp[i][j + 1][1];

						ll cnt = (upor * nich) % mod;

//						assert(cnt <= dp[1][1][1]);

						if(cnt - dp[1][1][1]) printf("1");
						else printf("0");
					}
				}
				else assert(0);

				printf(" ");
			}

			printf("\n");

		}
    }


}


