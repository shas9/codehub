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

ll rows, cells;
ll ans = 0;
bool visited[22][22];
char path[22][22];

void dfs(ll row, ll col)
{
    //cout << row << " -- " << col << endl;

    if(row < 0 || col < 0)
    {
        return;
    }

    if(visited[row][col] == true)
    {
        return;
    }

    if(row >= rows || col >= cells)
    {
        return;
    }

    if(path[row][col] == '#')
    {
        return;
    }

    ans++;

    visited[row][col] = true;

    //cout << row << " " << col << endl;

    dfs(row + 1, col);
    dfs(row - 1, col);
    dfs(row, col + 1);
    dfs(row, col - 1);
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    slld(testcase);

    char c;

    ll pos_row;
    ll pos_col;

    for(i = 1; i <= testcase; i++)
    {
        slld(cells);
        slld(rows);

        for(j = 0; j < rows; j++)
        {
            scanf("%s", path[j]);
        }

        for(j = 0; j < rows; j++)
        {
            for(k = 0; k < cells; k++)
            {
                if(path[j][k] == '@')
                {
                    pos_row = j;
                    pos_col = k;
                }
            }
        }

        ans = 0;

        memset(visited,false,sizeof(visited));

        dfs(pos_row,pos_col);

        printcase(i,ans);

    }


}

