#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
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

char grid[103][103];

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

        if(n * m % 2)
        {
            for(i = 1; i <= n; i++)
            {
                for(j = 1; j <= m; j++)
                {
                    if(i % 2)
                    {
                        if(j % 2) grid[i][j] = 'B';
                        else grid[i][j] = 'W';
                    }
                    else
                    {
                        if(j % 2 == 0) grid[i][j] = 'B';
                        else grid[i][j] = 'W';
                    }
                }
            }
        }
        else
        {
            for(i = 1; i <= n; i++)
            {
                for(j = 1; j <= m; j++)
                {
                    if(i % 2)
                    {
                        if(j % 2) grid[i][j] = 'B';
                        else grid[i][j] = 'W';
                    }
                    else
                    {
                        if(j % 2 == 0) grid[i][j] = 'B';
                        else grid[i][j] = 'W';
                    }
                }
            }

            if(grid[n][m] == 'B') grid[1][m] = 'B';
            else grid[n][m] = 'B';
        }

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                cout << grid[i][j];
            }

            cout << endl;
        }
    }


}


