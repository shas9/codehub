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

#define pll pair < ll, ll >

#define printcase(indexing) printf("Case %lld:\n", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009

#define mp make_pair


using namespace std;

char path[60][60];
ll row, col;


bool mark[55];
bool vis[55][55];

ll disx[] = {1,-1,0,0};
ll disy[] = {0,0,1,-1};

void bfs(char word)
{
    memset(vis,false,sizeof(vis));

    queue < pll > q;

    ll i;

    for(i = 0; i < row; i++)
    {
        if(path[i][0] != word)
        {
            q.push(mp(i,0));
            vis[i][0] = 1;
        }

        if(path[i][col - 1] != word)
        {
            q.push(mp(i,col - 1));
            vis[i][col - 1] = 1;
        }
    }

    for(i = 0; i < col; i++)
    {
        if(path[0][i] != word)
        {
            q.push(mp(0,i));

            vis[0][i] = 1;
        }

        if(path[row - 1][i] != word)
        {
            q.push(mp(row - 1, i));
            vis[row - 1][i] = 1;
        }
    }

    while(!q.empty())
    {
        pll top = q.front();
        q.pop();

        for(i = 0; i < 4; i++)
        {
            ll fx = top.first + disx[i];
            ll fy = top.second + disy[i];

            if(fx >= 0 && fx < row && fy >= 0 && fy < col && word != path[fx][fy] && vis[fx][fy] == false)
            {
                vis[fx][fy] = true;
                q.push(mp(fx,fy));
            }
        }
    }

    for(i = 0; i < row; i++)
    {
        for(ll j = 0; j < col; j++)
        {
            if(!vis[i][j])
            {
                path[i][j] = word;
            }
        }
    }

    return;
}

void solve()
{
    for(ll i = 0; i < row; i++)
    {
        for(ll j = 0; j < col; j++)
        {
            ll temp = path[i][j] - 'A';
            if(path[i][j] != '.' && !mark[temp])
            {
                mark[temp] = 1;

                bfs(path[i][j]);
            }
        }
    }
}


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(row);
        slld(col);
        memset(mark, false,sizeof(mark));

        for(i = 0; i < row; i++)
        {
            ss(path[i]);
        }

        solve();

        printcase(cs);

        for( i = 0; i < row; i++)
        {
            for(j = 0; j < col; j++)
            {
                pc(path[i][j]);
            }
            pnew;
        }
    }


}


