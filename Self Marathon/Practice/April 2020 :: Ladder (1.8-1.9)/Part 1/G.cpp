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

char grid[1003][1003];
ll vis[1003][1003];
ll dp[1003][1003];
ll dirx[] = {1,0,-1,0};
ll diry[] = {0,1,0,-1};
ll col;

bool cycle(ll stx, ll sty, ll n, ll m)
{
    queue < pll > q;

    q.push(make_pair(stx,sty));

    vis[stx][sty] = col;

    while(!q.empty())
    {
        pll top = q.front();
        q.pop();

        for(ll i = 0; i < 4; i++)
        {
            ll xx = top.first + dirx[i];
            ll yy = top.second + diry[i];

            if(xx == 0 || xx > n) continue;
            if(yy == 0 || yy > m) continue;

            if(vis[xx][yy] == col)
            {
                if(grid[top.first][top.second] == 'A' && grid[xx][yy] == 'D') return 1;

                continue;
            }

            if(grid[top.first][top.second] == 'D' && grid[xx][yy] == 'I');
            else if(grid[top.first][top.second] == 'I' && grid[xx][yy] == 'M');
            else if(grid[top.first][top.second] == 'M' && grid[xx][yy] == 'A');
            else if(grid[top.first][top.second] == 'A' && grid[xx][yy] == 'D');
            else continue;

            vis[xx][yy] = col;

            q.push(make_pair(xx,yy));
        }
    }

    return 0;
}

ll dfs(ll xx, ll yy, ll n, ll m)
{

    ll &ret = dp[xx][yy];

    if(ret != -1) return ret;

    vis[xx][yy] = 1;

    ret = 0;

    for(ll i = 0; i < 4; i++)
    {
        ll x = xx + dirx[i];
        ll y = yy + diry[i];

        if(x == 0 || x > n) continue;
        if(y == 0 || y > m) continue;

        if(grid[x][y] == 'M' && grid[xx][yy] == 'I');
        else if(grid[x][y] == 'A' && grid[xx][yy] == 'M');
        else if(grid[x][y] == 'D' && grid[xx][yy] == 'A');
        else if(grid[x][y] == 'I' && grid[xx][yy] == 'D');
        else continue;

//        cout << x << " " << y << " " << vis[x][y] << endl;
        if(vis[x][y]) return mnlld;

        ll rr = dfs(x,y,n,m);

        if(rr == mnlld) return mnlld;

        ret = max(ret,rr);
    }

    vis[xx][yy] = 0;

    if(grid[xx][yy] == 'A') ret++;

    return ret;



}

ll solve(ll n, ll m)
{
    memset(vis,0,sizeof vis);

    ll ret = 0;
    ll i, j;

    col = 0;
//
//    for(i = 1; i <= n; i++)
//    {
//        for(j = 1; j <= m; j++)
//        {
//            if(vis[i][j]) continue;
//
//            if(grid[i][j] == 'D')
//            {
//                col++;
//                if(cycle(i,j,n,m)) return -1;
//            }
//        }
//    }

    memset(dp,-1,sizeof dp);

    for(i = 1; i  <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(grid[i][j] == 'D')
            {
                ll x = dfs(i,j,n,m);

                if(x == mnlld) return -1;

                ret = max(ret,x);
            }
        }
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(scanf("%lld %lld", &n, &m) != EOF)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%s", grid[i] + 1);
        }

        ans = solve(n,m);

        if(ans == -1)
        {
            printf("Poor Inna!\n");
        }
        else if(ans == 0)
        {
            printf("Poor Dima!\n");
        }
        else
        {
            printf("%lld\n", ans);
        }
    }


}


