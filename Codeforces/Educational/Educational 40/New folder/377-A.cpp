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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

ll row, col, X;
char mp[1000][1000];
bool vis[1000][1000];
ll s;
ll x;

void dfs(ll _i, ll _j)
{
//    cout << _i << " " << _j << " " << x << endl;
    if(x <= 0)
    {
        return;
    }

    if(_i < 0 || _i >= row || _j < 0 || _j >= col)
    {
        return;
    }

    if(mp[_i][_j] == '#')
    {
        for(ll i = 0; i < row; i++)
        {
            for(ll j = 0; j < col; j++)
            {
                if(mp[i][j] == '.' && vis[i][j] == false)
                {
                    dfs(i,j);
                    return;
                }
            }
        }
    }

    if(vis[_i][_j] == true)
    {
        return;
    }
    x--;

    if(x <= 0)
    {
        return;
    }

    vis[_i][_j] = true;

    dfs(_i+1,_j);
    dfs(_i-1,_j);
    dfs(_i,_j+1);
    dfs(_i,_j-1);

}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);


    cin >> row >> col >> X;

    s = 0;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            scanf(" %c", &mp[i][j]);

            if(mp[i][j] == '.')
            {
                s++;
            }
        }
    }


    x = s - X;
    x++;

    dfs(0,0);

//    for(i = 0; i < row; i++)
//    {
//        for(j = 0; j < col; j++)
//        {
//            if(vis[i][j])
//            {
//                cout << 1;
//            }
//            else
//            {
//                cout << 0;
//            }
//        }
//
//        cout << endl;
//    }

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(mp[i][j] == '.' && vis[i][j] == false)
            {
                cout << "X";
            }
            else
            {
                cout << mp[i][j];
            }
        }

        cout << endl;
    }
}

