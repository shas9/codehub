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

char grid[101][1003][1003];
//char tgrid[1003][1003];

ll adx[] = {-1,1,0,0};
ll ady[] = {0,0,1,-1};

void iter(ll n, ll m)
{
	for(ll i = 1; i <= 100; i++)
	{
//		for(ll j = 1; j <= n; j++)
//		{
//			for(ll k = 1; k <= m; k++) tgrid[j][k] = grid[j][k];
//		}

		for(ll j = 1; j <= n; j++)
		{
			for(ll k = 1; k <= m; k++)
			{
				for(ll l = 0; l < 4; l++)
				{
					ll tj = j + adx[l];
					ll tk = k + ady[l];

					if(tj > n || tk > m) continue;
					if(!tj || !tk) continue;

//					if(tgrid[tj][tk] == grid[j][k])
//					{
//						if(grid[j][k] == '1') grid[j][k] = '0';
//						else grid[j][k] = '1';
//
//						break;
//					}
				}
			}
		}

		ll cnt = 0;

		for(ll j = 1; j <= n; j++)
		{
//			for(ll k = 1; k <= m; k++) if(tgrid[j][k] == grid[j][k]) cnt++;
		}

		if(cnt == 0)
		{
			cout << i << endl;
			return;
		}

//		for(ll j = 1; j <= n; j++)
//		{
//			cout << grid[j] + 1 << endl;
//		}
//
//		cout << endl;
	}
}

void simulate(ll n, ll m)
{
	for(ll i = 1; i <= 100; i++)
	{
		for(ll j = 1; j <= n; j++)
		{
			for(ll k = 1; k <= m; k++)
			{
				grid[i][j][k] = grid[i - 1][j][k];

				for(ll l = 0; l < 4; l++)
				{
					ll x = j + adx[l];
					ll y = k + ady[l];

					if(x > n || x < 1 || y > m || y < 1) continue;

					if(grid[i - 1][x][y] == grid[i][j][k])
					{
						if(grid[i][j][k] == '1') grid[i][j][k] = '0';
						else grid[i][j][k] = '1';

						break;
					}
				}
			}
		}
	}
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> testcase)
    {
		for(i = 1; i <= n; i++)
		{
			scanf("%s", grid[0][i] + 1);
		}

//		iter(n,m);

		simulate(n,m);

		for(i = 1; i <= testcase; i++)
		{
			ll x, y, p;
			slld(x);
			slld(y);
			slld(p);

			if(p <= 100) printf("%c", grid[p][x][y]);
			else
			{
				if(p % 2 == 0) printf("%c", grid[100][x][y]);
				else printf("%c", grid[99][x][y]);
			}

			printf("\n");
		}
    }



}



