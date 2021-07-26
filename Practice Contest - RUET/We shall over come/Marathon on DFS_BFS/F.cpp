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

char path[110][110];
char match[] = "ALLIZZWELL";
ll row, col;
ll flag;
bool visited[110][110];
ll fx[8] = {-1,-1,-1,0,0,1,1,1};
ll fy[8] = {-1,0,1,-1,1,-1,0,1};

/*

1
3 3
AEL
LWZ
LIZ

*/

void dfs(ll r, ll c, ll pos)
{
                if(flag == 1)
                {
                    return;
                }

                if(pos == 10)
    {
        flag = 1;
        return;
    }

    if(path[r][c] != match[pos])
    {
        return;
    }

    ll x, y, i, j, k, l, m, n;

    for(i = 0; i < 8; i++)
    {
        x = r + fx[i];
        y = c + fy[i];

        if(x >= 0 && x < row && y >= 0 && y < col)
        {
            if(visited[x][y] == false)
            {
                visited[x][y] = true;
                dfs(x,y,pos+1);
                visited[x][y] = false;
            }
        }
    }
}


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, tag;

    slld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        slld(row);
        slld(col);

        for(j = 0; j < row; j++)
        {
            scanf("%s", path[j]);
        }

        flag = 0;

        memset(visited, false, sizeof(visited));

        for(j = 0; j < row; j++)
        {
            for(k = 0; k < col; k++)
            {
                if(flag == 0)
                {
                    visited[j][k] = 1;
                    dfs(j,k,0);
                    visited[j][k] = 0;
                }
            }
        }

//        if(row * col < 10)
//        {
//            flag = 0;
//        }

        if(flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

    }

    return 0;


}


