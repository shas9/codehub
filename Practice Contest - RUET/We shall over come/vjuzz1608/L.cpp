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

ll dp[100005];
ll coins[105];
ll C[105];
ll check[100005];

ll solve(ll n, ll m)
{
    ll i, j, k, cnt = 0;
    ll tag;
    ll limit = 0;
    ll flag;

    for(i = 1; i <= n; i++)
    {
        memset(dp,0,sizeof(dp));
        for(j = coins[i]; j <= m; j++)
        {
            if(check[j] == 0 && dp[j - coins[i]] < C[i])
            {
                check[j] |= check[j - coins[i]];
                dp[j] = dp[j - coins[i]] + 1;
            }
        }

    }

    cnt = 0;

    for(i = 1; i <= m; i++)
    {
        if(check[i] != 0)
        {
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(n);
        scanlld(m);
        memset(check,0,sizeof(check));
        check[0] = 1;

        for(j = 1; j <= n; j++)
        {
            scanlld(input);
            coins[j] = input;
        }

        for(j = 1; j <= n; j++)
        {
            scanlld(input);
            C[j] = input;
        }

        ll ans = solve(n,m);

        printcase(i,ans);
    }


}


