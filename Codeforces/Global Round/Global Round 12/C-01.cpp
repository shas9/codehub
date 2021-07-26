
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

char grid[303][303];



bool left(ll x, ll y, ll n)
{
	if(grid[x][y] != 'X') return 0;

	if(y - 1 < 1 || grid[x][y - 1] != 'X') return 0;

	if(y - 2 < 1 || grid[x][y - 2] != 'X') return 0;

	return 1;
}

bool up(ll x, ll y, ll n)
{
	if(grid[x][y] != 'X') return 0;

	if(x - 1 < 1 || grid[x - 1][y] != 'X') return 0;

	if(x - 2 < 1 || grid[x - 2][y] != 'X') return 0;

	return 1;
}

bool right(ll x, ll y, ll n)
{
	if(grid[x][y] != 'X') return 0;

	if(y + 1 > n || grid[x][y + 1] != 'X') return 0;

	if(y + 2 > n || grid[x][y + 2] != 'X') return 0;

	return 1;
}

bool down(ll x, ll y, ll n)
{
	if(grid[x][y] != 'X') return 0;

	if(x + 1 > n || grid[x + 1][y] != 'X') return 0;

	if(x + 2 > n || grid[x + 2][y] != 'X') return 0;

	return 1;
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
		cin >> n;

		for(ll i = 1; i <= n; i++) cin >> grid[i] + 1;

		k = 0;

		for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) if(grid[i][j] == 'X') k++;

		k = (k / 3);

		for(ll i =  1; i <= n; i++)
		{
			for(ll j = 1; j <= n; j++)
			{
				if(joint3(i,j,n))
				{
					grid[i][j] = 'O';
					k--;
				}
			}
		}

		for(ll i =  1; i <= n; i++)
		{
			for(ll j = 1; j <= n; j++)
			{
				if(joint2(i,j,n))
				{
					grid[i][j] = 'O';
					k--;
					j += 2;
				}
			}
		}

		for(ll i =  1; i <= n; i++)
		{
			for(ll j = 1; j <= n; j++)
			{
				if(joint1(i,j,n))
				{
//					if(joint(i,j,n) )cout << i << " " << j << endl;
					grid[i][j] = 'O';
					k--;
				}
			}
		}

		for(ll i =  1; i <= n; i++)
		{
			for(ll j = 1; j <= n; j++)
			{
				if(left(i,j,n) || up(i,j,n))
				{
//					if(joint(i,j,n) )cout << i << " " << j << endl;
					grid[i][j] = 'O';
					k--;
				}
			}
		}

		assert(k >= 0);

		for(ll i = 1; i <= n; i++) cout << grid[i] + 1 << "\n";
    }


}



