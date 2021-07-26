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

char mp[1000][1000];
ll dp[1000][1000];
bool vis[1000][1000];

ll dfs(ll i, ll  j, ll r, ll c)
{
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if(i < 0 || i >= r || j < 0 || j >= c)
    {
        return 1;
    }

    if(vis[i][j] == 1)
    {
        return 0;
    }

    vis[i][j] = 1;

    if(mp[i][j] == 'D')
    {
        dp[i][j] = dfs(i+1,j,r,c);
    }
    else if(mp[i][j] == 'U')
    {
        dp[i][j] = dfs(i-1,j,r,c);
    }
    else if(mp[i][j] == 'R')
    {
        dp[i][j] = dfs(i,j+1,r,c);
    }
    else
    {
        dp[i][j] = dfs(i,j-1,r,c);
    }
}
ll solve(ll r, ll c)
{
    memset(dp,-1,sizeof dp);

    for(ll i = 0; i < r; i++)
    {
        for(ll j = 0; j < c; j++)
        {
            if(dp[i][j] == -1)
            {
                memset(vis,false,sizeof vis);
                dp[i][j] = dfs(i,j,r,c);
            }
        }
    }

    ll cnt = 0;

    for(ll i = 0; i < r; i++)
    {
        for(ll j = 0; j < c; j++)
        {
//            cout << dp[i][j] << " " << i << " " << j << endl;
            cnt += dp[i][j];
        }
    }

    return cnt;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    ll r, c;

    cin >> r >> c;



    for(i =0; i < r; i++)
    {
        cin >> mp[i];
    }

    ans = solve(r,c);

    cout << ans << endl;

}


