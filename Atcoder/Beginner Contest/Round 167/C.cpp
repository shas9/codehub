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

ll mat[20][20];
ll cost[20];
ll n, m, x;

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> x)
    {
		for(i = 0; i < n; i++)
		{
			slld(cost[i]);
			for(j = 0; j < m; j++) slld(mat[i][j]);
		}

		ans = mxlld;

		for(i = 0; i < (1 << n); i++)
		{
			ll arr[m+1];
			memset(arr,0,sizeof arr);
			ll cst = 0;

			for(j = 0; j < n; j++)
			{
				if(check(i,j))
				{
					cst += cost[j];

					for(k = 0; k < m; k++)
					{
						arr[k] += mat[j][k];
					}
				}
			}

			for(j = 0; j < m; j++)
			{
				if(arr[j] < x) break;
			}

			if(j == m) ans = min(ans,cst);
		}

		if(ans == mxlld) ans = -1;

		cout << ans << '\n';
    }


}



