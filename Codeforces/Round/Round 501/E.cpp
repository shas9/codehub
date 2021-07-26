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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

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


char grid[2000][2000];

struct node
{
    ll x, y, z;

    node(ll _x, ll _y, ll _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
};

vector < node > vec;

bool vis[2000][2000];
ll lr[2000][2000];
ll rl[2000][2000];
ll ud[2000][2000];
ll du[2000][2000];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n >> m)
    {
        for(i = 1; i <= n; i++)
        {
            scanf(" %s", grid[i] + 1);
        }

        vec.clear();

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(grid[i][j] == '.') continue;

                lr[i][j] = lr[i][j - 1] + 1;
            }
        }

        for(i = 1; i <= n; i++)
        {
            for(j = n; j >= 1; j--)
            {
                if(grid[i][j] == '.') continue;

                rl[i][j] = rl[i][j - 1] + 1;
            }
        }

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(grid[j][i] == '.') continue;

                ud[j][i] = ud[j][i - 1] + 1;
            }
        }

        for(i = 1; i <= n; i++)
        {
            for(j = n; j >= 1; j--)
            {
                if(grid[j][i] == '.') continue;

                ud[j][i] = ud[j][i - 1] + 1;
            }
        }


        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(grid[i][j] == '.') continue;

                if(vis[i][j] == 1) continue;

                for(k = i + 1; k <= n; k++)
                {
                    if(grid[k][j] == '.') break;

                    ll mn = min(lr[k][j], rl[k][j]);
                    mn = min(mn, du[k][j]);

                    if(mn >= (k - i))
                    {
                        vec.push_back(node(k,j,k-i));
                    }
                }
            }
        }

        ll sz = vec.size();

        cout << sz << endl;

        for(i = 0; i < sz; i++)
        {
            cout << vec[i].x << " " << vec[i].y << " " << vec[i].z << endl;
        }
    }


}


