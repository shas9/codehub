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

char path[25][25];

ll row, col;
ll flag;
ll limit;

ll fx[] = {1,-1,0,0};
ll fy[] = {0,0,1,-1};

ll val[15][15];

ll bfs(ll r, ll c, ll pos)
{
    //cout << r << " " << c << endl;
    if(pos > limit)
    {
        flag = 1;
        return 0;
    }

    queue < pair < ll, ll > > q;

    while(!q.empty())
    {
        q.pop();
    }

    pair < ll, ll > current;
    pair < ll, ll > u;

    current.first = r;
    current.second = c;

    q.push(current);

    for(ll i = 0; i < 13; i++)
    {
        for(ll j = 0; j < 13; j++)
        {
            val[i][j] = -1;
        }
    }

    val[r][c] = 0;

    while(!q.empty())
    {
        current = q.front();
        q.pop();

        for(ll i = 0; i < 4; i++)
        {
            ll x = current.first + fx[i];
            ll y = current.second + fy[i];

//            cout << "Moved: " << x << " & " << y << " & i = " << i <<  endl;
//            cout << "Current: " << current.first << " & " << current.second << endl;

            if(x >= 0 && x < row && y >= 0 && y < row)
            {
                if(val[x][y] == -1 && path[x][y] != '#')
                {
//                    cout << "Done" << endl;
                    val[x][y] = val[current.first][current.second] + 1;

                    if(path[x][y] - 'A' == pos)
                    {
//                        cout << "Found: " << x << " " << y <<  endl;
                        return val[x][y] + bfs(x,y,pos + 1);
                    }
                    else if('A' + pos <= path[x][y] && path[x][y] <= 'Z')
                    {
                        continue;
                    }
                    u.first = x;
                    u.second = y;

//                    cout << "Push: " << x << " " << y << endl;

                    q.push(u);
                }
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

        ll x, y;

        limit = 0;

        for(j = 0; j < row; j++)
        {
            scanf("%s", path[j]);

            for(k = 0; k < row; k++)
            {
                if(path[j][k] >= 'A' && path[j][k] <= 'Z')
                {
                    if((path[j][k] - 'A') > limit)
                    {
                        limit = path[j][k] - 'A';
                    }

                    if(path[j][k] == 'A')
                    {
                        x = j;
                        y = k;
                    }
                }
            }
        }

        flag = 0;

        ll ans = bfs(x,y,1);

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



