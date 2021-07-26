#include <bits/stdc++.h>

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

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;

    ll dp[35][35];

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(i = 2; i <= 30; i++)
    {
        dp[i][0] = 1;
        for(j = 1; j <= i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] * i * i / j;
        }
    }


    scanlld(testcase);
    for(i = 1; i <= testcase; i++)
    {
        scanlld(n);
        scanlld(k);

        if(k > n)
        {
            printf("Case %lld: 0\n", i);
        }
        else
        {
            printf("Case %lld: %lld\n", i, dp[n][k]);
        }
    }


}

