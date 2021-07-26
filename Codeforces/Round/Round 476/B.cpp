#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf(" %c", &letter)
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

char mp[200][200];
ll track[200][200];
bool vis[200][200];
ll level[200][200];

ll disx[] = {1,-1,0,0};
ll disy[] = {0,0,1,-1};

void dfs(ll px, ll py, ll n, ll k, ll dot)
{

    if(dot == k)
    {
        //cout << px << " " << py  << " = " << dot << endl;
        track[px][py]++;
        return;
    }

    vis[px][py] = true;

    for(ll i = 0; i < 4; i++)
    {
        ll x = px + disx[i];
        ll y = py + disy[i];

        if(x <= 0 || x > n || y <= 0 || y > n || mp[x][y] == '#') continue;

        dfs(x,y,n,k,dot + 1);
        dfs(x,y,n,k,1);
    }


}

pair < ll, ll > solve(ll n, ll k)
{
    memset(track,0,sizeof(track));
    //memset(dp, -1, sizeof(dp));
    memset(vis, 0, sizeof vis);
    ll i, j;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(vis[i][j] == 0 && mp[i][j] == '.')
            {
                //cout << i << " " << j << endl;
                level[i][j] = 0;
                dfs(i,j,n,k,1);
            }
        }
    }

    ll x = 1, y = 1;

    ll mx = -1;

    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= n; j++)
        {
            cout << i << " " << j << " " << track[i][j] << endl;
            if(mx < track[i][j])
            {
                x = i;
                y = j;
                mx = track[i][j];
            }
        }
    }

    pair < ll, ll > z;

    z.first = x;
    z.second = y;

    return z;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> n >> k;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            sc(mp[i][j]);
        }
    }

    pair < ll, ll > x;

    x = solve(n,k);

    cout << x.first << " " << x.second << endl;


}


