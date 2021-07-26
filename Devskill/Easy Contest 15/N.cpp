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

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

using namespace std;

char path[20][20];
char match[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

ll row, col;
ll flag;
ll ans;
ll limit;

bool visited[20][20];

ll fx[8] = {-1,0,1,0};
ll fy[8] = {0,-1,0,1};

void dfs(ll r, ll c, ll pos, ll dist)
{
    if(pos == limit)
    {
        flag = 1;
        ans = min(dist,ans);
        return;
    }

    if(path[r][c] == '#')
    {
        return;
    }

    if(path[r][c] >= 'A' && path[r][c] <= 'Z')
    {
//        cout << path[r][c] << " " << match[pos] << endl;
        if(path[r][c] != match[pos])
        {
            return;
        }
    }

//    cout << r << " " << c << " " << pos << " " << dist << endl;

    ll x, y, i, j, k, l, m, n;

    for(i = 0; i < 4; i++)
    {
        x = r + fx[i];
        y = c + fy[i];

        if(x >= 0 && x < row && y >= 0 && y < col)
        {
            if(visited[x][y] == false)
            {
                visited[x][y] = true;

                if(path[r][c] == match[pos])
                {
                    dfs(x,y,pos+1,dist+1);
                }
                else
                {
                    dfs(x,y,pos,dist+1);
                }
                visited[x][y] = false;
            }
        }
    }
}


int main()
{
    ll i, j, l, m, n, o;
    ll testcase;
    ll input, tag;
    ll k;

    slld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        slld(row);

        col = row;

        for(j = 0; j < row; j++)
        {
            scanf("%s", path[j]);
        }

        flag = 0;
        ans = mxlld;

        memset(visited, false, sizeof(visited));

        char maxc = path[j][k];

        for(j = 0; j < row; j++)
        {
            for(k = 0; k < col; k++)
            {
                if(path[j][k] > maxc)
                {
                    maxc = path[j][k];
                }
            }
        }

        limit = maxc - 'A';


        for(j = 0; j < row; j++)
        {
            for(k = 0; k < col; k++)
            {
                if(path[j][k] == 'A')
                {
                    visited[j][k] = 1;
                    dfs(j,k,0,0);
                }
            }
        }

        if(flag)
        {
            printf("Case %lld: %lld\n", i, ans);
        }
        else
        {
            printf("Case %lld: Impossible\n", i);
        }

    }

    return 0;


}



