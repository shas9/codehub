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

ll mat[2][505][505];
ll sum[2][505][505];
ll dp[505][505];

void prn(ll n, ll m)
{
    for(ll i = 0; i <= 1; i++)
    {
        cout << i + 1 << ": " << endl;

        for(ll j = 1; j <= n; j++)
        {
            for(ll k = 1; k <= m; k++)
            {
                cout << mat[i][j][k] << " ";
            }

            cout << endl;
        }

        cout << endl;
    }

    for(ll i = 0; i <= 1; i++)
    {
        cout << i + 1 << ": " << endl;
        for(ll j = 1; j <= n; j++)
        {
            for(ll k = 1; k <= m; k++)
            {
                cout << sum[i][j][k] << " ";
            }

            cout << endl;
        }

        cout << endl;
    }

}


ll calc(ll row, ll lastc)
{
	if(row == 0 || lastc == 0) return 0;

	ll &ret = dp[row][lastc];

	if(ret != -1) return ret;

	ret = 0;

	ret = max(ret, calc(row - 1, lastc) + sum[0][row][lastc]);
	ret = max(ret, calc(row, lastc - 1) + sum[1][row][lastc]);

//	cout << row << " " << lastc << " " << ret << endl;

	return ret;
}

ll solve(ll n, ll m)
{
	memset(sum,0,sizeof sum);


	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= m; j++)
		{
			sum[0][i][j] = sum[0][i][j - 1] + mat[0][i][j];
		}
	}

	for(ll i = 1; i <= m; i++)
	{
		for(ll j = 1; j <= n; j++)
		{
			sum[1][j][i] = sum[1][j - 1][i] + mat[1][j][i];
		}
	}





	memset(dp,-1,sizeof dp);

	return calc(n,m);
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

		for(i = 0; i < 2; i++) for(j = 1; j <= n; j++) for(k = 1; k <= m; k++) slld(mat[i][j][k]);

		ans = solve(n,m);

		printf("Case %d: %d\n", cs, ans);
    }


}


