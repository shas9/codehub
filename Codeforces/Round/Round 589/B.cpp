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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll grid[1003][1003];

#define mod 1000000007

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		memset(grid,-1,sizeof grid);

		for(ll i = 1; i <= n; i++)
		{
			slld(input);

			for(ll j = 1; j <= input; j++) grid[i][j] = 1;

			grid[i][input + 1] = 0;
		}

		bool no = 0;

		for(ll i = 1; i <= m; i++)
		{
			slld(input);

			for(ll j = 1; j <= input; j++)
			{
				if(grid[j][i] == 0) no = 1;

				grid[j][i] = 1;
			}

			if(grid[input + 1][i] == 1) no = 1;

			grid[input + 1][i] = 0;
		}

		if(no)
		{
			printf("0\n");
			continue;
		}

		ans = 1;

		for(ll i = 1; i <= n; i++)
		{
			for(ll j = 1; j <= m; j++)
			{
				if(grid[i][j] == -1) ans = (ans * 2) % mod;
			}
		}

		printf("%lld\n", ans);
    }


}



