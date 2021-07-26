#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

char grid[5003][5003];
ll csumr[5003][5003];
ll rr[5003];

bool comp(ll a, ll b)
{
	return a > b;
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
		for(i = 1; i <= n; i++)
		{
			scanf("%s", grid[i] + 1);
		}


		for(i = 1; i <= n; i++)
		{
			for(j = m; j >= 1; j--)
			{
				if(grid[i][j] == '1')
				{
					csumr[i][j] = (1 + csumr[i][j + 1]);
				}
				else
				{
					csumr[i][j] = 0;
				}
			}
		}

		ans = 0;

		for(i = 1; i <= m; i++)
		{
			ll idx = 0;
			for(j = 1; j <= n; j++)
			{
				if(grid[j][i] == '0') continue;

				rr[++idx] = csumr[j][i];
			}

			sort(rr + 1, rr + 1 + idx);

			for(j = idx; j >= 1; j--)
			{
				ans = max(ans, (idx - j + 1) * rr[j]);
			}
		}

		printf("%d\n", ans);


    }
}


