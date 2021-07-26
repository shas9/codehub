#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

char grid[500][500];

ll disx[] = {-1,-1,0,1,1,-1,0,1};
ll disy[] = {-1,0,-1,-1,0,1,1,1};

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        scanf(" %s", grid[i] + 1);
    }

    bool on = 1;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(grid[i][j] >= '0' && grid[i][j] <= '8')
            {
                ll id = grid[i][j] - '0';

                for(k = 0; k < 8; k++)
                {
                    ll x = disx[k] + i;
                    ll y = disy[k] + j;

                    if(grid[x][y] == '*') id--;
                }

                if(id != 0) on = 0;
            }

            if(grid[i][j] == '.')
            {
                for(k = 0; k < 8; k++)
                {
                    ll x = disx[k] + i;
                    ll y = disy[k] + j;

                    if(grid[x][y] == '*') on = 0;
                }
            }
        }
    }

    if(on == 0) cout << "NO" << endl;
    else cout << "YES" << endl;

}


