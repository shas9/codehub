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

int fire[205][205];
int level[205][205];
char grid[205][205];
int disx[] = {1,-1,0,0};
int disy[] = {0,0,-1,1};

ll r, c;

void fireup()
{
    ll i, j;
    ll x, y;
    queue < pair < ll, ll > > q;
        for(i = 1; i <= r; i++)
        {
            for(j = 1; j <= c; j++)
            {
                if(grid[i][j] == 'F')
                {
                    q.push(make_pair(i,j));
                    fire[i][j] = 1;
                }
            }
        }

    while(!q.empty())
    {
        pair < ll, ll > top = q.front();
        q.pop();

        for(i = 0; i < 4; i++)
        {
            x = top.first + disx[i];
            y = top.second + disy[i];

            if(x <= 0 || x > r || y <= 0 || y > c) continue;
            if(fire[x][y] != 0) continue;
            if(grid[x][y] == '#') continue;

            fire[x][y] = fire[top.first][top.second] + 1;

            q.push(make_pair(x,y));
        }
    }
}

ll solve()
{
    ll i, j;
    ll x, y;

    queue < pair < ll, ll > > q;

    for(i = 1; i <= r; i++)
    {
        for(j = 1; j <=  c; j++)
        {
            if(grid[i][j] == 'J')
            {
                q.push(make_pair(i,j));
                level[i][j] = 1;
                break;
            }
        }
        if(!q.empty()) break;
    }

    while(!q.empty())
    {
        pair < ll, ll > top = q.front();
        q.pop();

        for(i = 0; i < 4; i++)
        {
            x = top.first + disx[i];
            y = top.second + disy[i];

            if(x <= 0 || x > r || y <= 0 || y > c)
            {
                return level[top.first][top.second];
            }
            if(grid[x][y] == '#') continue;

            if(level[x][y] != 0) continue;

            if(level[top.first][top.second] + 1 >= fire[x][y]) continue;

            level[x][y] = level[top.first][top.second] + 1;

            q.push(make_pair(x,y));
        }
    }

    return -1;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);


    for(ll cs = 1; cs <= testcase; cs++)
    {
        memset(fire,0,sizeof fire);
        memset(level,0,sizeof level);

        slld(r);
        slld(c);

        for(i = 1; i <= r; i++)
        {
            scanf("%s", grid[i] + 1);
        }

        fireup();
        ans = solve();

        if(ans == -1) printf("Case %lld: IMPOSSIBLE\n", cs);
        else printcase(cs,ans);

    }


}

