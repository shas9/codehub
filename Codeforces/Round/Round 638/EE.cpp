// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define ll int

using namespace std;

long long red[503];
long long blue[503];
bool dp[503][503];
int main()
{
    long long i, j, k, l, m, n, o, r, q;
    long long testcase;
    long long input, flag, tag;

//    freopen("input.txt", "r", stdin);

    while(cin >> n >> m)
    {
		long long totr = 0, totb = 0;

		for(i = 1; i <= n; i++)
		{
			cin >> red[i] >> blue[i];

			totr += red[i];
			totb += blue[i];

//			cout << red[i] << " " << blue[i] << endl;
//			cout << totr << " " << totb << endl;
		}

		memset(dp,0,sizeof dp);
		dp[0][0] = 1;

		for(i = 1; i <= n; i++)
		{
			int x = min(m - 1, red[i]);
			for(j = 0; j < m; j++)
			{
				dp[i][j] = dp[i - 1][(j - (red[i] % m) + m) % m];

				for(k = 0; k <= x; k++)
				{
					if(((int)red[i] - k) % m + blue[i] < m) continue;

					dp[i][j] |= dp[i - 1][(j - (k % m) + m) % m];
				}
			}
		}

		long long ans = 0;

		for(i = n; i <= n; i++)
		{
			for(j = 0; j < m; j++)
			{
				if(dp[i][j]) ans = max(ans, (totb + totr - j) / m);
			}
		}

		printf("%lld\n", ans);
	}


}



