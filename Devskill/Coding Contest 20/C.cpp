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

ll dp[100][100];

ll dfs(ll fr, ll ln)
{
    if(fr > ln)
    {
        return 0;
    }

    if(dp[ln][fr] != -1)
    {
        return dp[ln][fr];
    }
    if(ln == 0)
    {
        if(fr == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    ll ans = 0;

    if(fr)
    {
        ans += dfs(fr - 1, ln - 1);
    }

    ans += dfs(fr + 1, ln - 1);

    return dp[ln]ans;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    memset(dp,-1,sizeof(dp));

    for(i = 2; i <= 50; i += 2)
    {
        for(j = 1; j * 2 <= 50; j++)
        {
            if(dp[i][j] == -1)
            dp[i][j] = dfs(j,i-j);

        }
    }
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(l);
        slld(k);

        ans = 0;

        if(l % 2 != 0)
        {
            ans = 0;
        }
        else if(l < (k * 2))
        {
            ans = 0;
        }
        else if(l == (k * 2))
        {
            ans = 1;
        }
        else
        {
            ans = dp[l][k];
        }

        printcase(cs,ans);
    }


}

