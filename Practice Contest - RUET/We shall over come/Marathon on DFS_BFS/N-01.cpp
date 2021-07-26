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

#define pll pair <ll,ll>

using namespace std;

char path[15][15];
ll val[15][15], n;
bool flag;
ll mx;
ll fx[] = {1,-1,0,0};
ll fy[] = {0,0,1,-1};

deque < pll > dq;

ll bfs(ll r, ll c, ll pos)
{
    if(pos > mx)
    {
        flag = 1;
        return 0;
    }

    dq.clear();

    memset(val,-1,sizeof(val));

    dq.pb(pll(r,c));
    val[r][c] = 0;

    while(!dq.empty())
    {
        pll u = dq[0];

        dq.pop_front();

        for(ll i = 0; i < 4; i++)
        {
            ll x = u.first + fx[i];
            ll y = u.second + fy[i];

            if(0 <= x && x < n && 0 <= y && y < n)
            {
                if(val[x][y] == -1 && path[y][x] != '#')
                {
                    val[x][y] = val[u.first][u.second] + 1;

                    if(path[y][x] - 'A' == pos)
                    {
                        return val[x][y] + bfs(x,y,pos + 1);
                    }
                    else if('A' + pos <= path[y][x] && path[y][x] <= 'Z')
                    {
                        continue;
                    }

                    dq.pb(pll(x,y));
                }
            }
        }
    }
}


int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag;

    slld(testcase);

    ll x, y;

    for(i = 1; i <= testcase; i++)
    {
        slld(n);

        mx = 0;

        for(j = 0; j < n; j++)
        {
            scanf("%s", path[j]);

            for(k = 0; k < n; k++)
            {
                if('A' <= path[j][k] && path[j][k] <= 'Z')
                {
                    if(path[j][k] - 'A' > mx)
                    {
                        mx = path[j][k] - 'A';
                    }

                    if(path[i][j] == 'A')
                    {
                        x = k;
                        y = j;
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


}

