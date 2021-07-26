#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanlf(longvalue) scanf("%lf", &longvalue)
#define printlf(longvalue) printf("%lf\n", longvalue)
#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

using namespace std;

ll path[205][205];
ll dp[205][205];
ll n;

ll solve(ll i, ll j)
{
    if(i == 2*n)
    {
        return 0;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    ll way1 = 0, way2 = 0;

    if(i < n)
    {
        way1 = path[i][j] + solve(i + 1, j);
        way2 = path[i][j] + solve(i + 1, j + 1);
        dp[i][j] = max(way1,way2);
    }
    else
    {
        if(j == 1)
        {
            way1 = path[i][j] + solve(i + 1, 1);
            way2 = 0;
        }
        else if(j == (2*n - i))
        {
            way1 = path[i][j] + solve(i + 1, j - 1);
            way2 = 0;
        }
        else
        {
            way1 = path[i][j] + solve(i + 1, j - 1);
            way2 = path[i][j] + solve(i + 1, j);
        }

        dp[i][j] = max(way1,way2);
    }

    return dp[i][j];
}
int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag;

    scanlld(testcase);

    for(ll cas = 1; cas <= testcase; cas++)
    {
        scanlld(n);
        memset(dp,-1,sizeof(dp));
        memset(path,0,sizeof(path));

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= i; j++)
            {
                scanlld(input);

                path[i][j] = input;
            }
        }

        for(i = n + 1; i <= 2*n-1; i++)
        {
            for(j = 1; j <= 2*n - i; j++)
            {
                scanlld(input);

                path[i][j] = input;
            }
        }

        ll ans = solve(1,1);

        printf("Case %lld: %lld\n",cas,ans);
    }

    return 0;
}


