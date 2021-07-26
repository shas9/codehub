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

vector < ll > coins;
ll dp[300];
ll make;

ll solve()
{
    ll i, j, k;

    for(i = 0; i < coins.size(); i++)
    {
        for(j = coins[i]; j <= make; j++)
        {
            dp[j] = dp[j] + dp[j - coins[i]];
        }
    }

    return dp[make];
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    coins.clear();

    scanlld(make);
    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(input);

        coins.push_back(input);
    }

    ll ans = solve();

    printlld(ans);

}

