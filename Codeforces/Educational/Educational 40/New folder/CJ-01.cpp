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

ll mat[305][305];
ll dp[305][305];

ll dfs(ll i, ll j, ll sum, ll n)
{
    cout << i << " " << j << endl;
    if(i <= 0 || j <= 0 || i > n || j > n)
    {
        return sum;
    }

    if(dp[i][j] != -1)
    {
        return sum + dp[i][j];
    }

    ll x, y, z = 0;
    if(mat[i][j] == 0)
    {
        x = dfs(i + 1, j, 0, n);
        y = dfs(i, j + 1, 0, n);
        z = sum;
    }
    else
    {
        x = dfs(i + 1, j, sum + mat[i][j], n);
        y = dfs(i, j - 1, sum + mat[i][j], n);
    }

    dp[i][j] = max(z,x);

    return dp[i][j] = max(dp[i][j],y);

}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    memset(dp,-1,sizeof dp);
    slld(n);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
        }
    }

    ans = dfs(1,1,0,n);

    cout << ans << endl;

}

