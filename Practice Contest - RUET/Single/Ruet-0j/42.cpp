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

ll poss[1100];
ll dp[10005];
ll n;

ll solve(ll K)
{
    ll i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 1; j <= K; j++)
        {
            if(poss[i] <= j)
            {
                dp[j] = dp[j] % 1000000009 + dp[j-poss[i]] % 1000000009;
            }
        }
    }

    return dp[K] % 1000000009;
}

int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag;
    ll K;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        memset(dp,0,sizeof(dp));
        memset(poss,0, sizeof(poss));

        scanlld(n);
        scanlld(K);

        for(j = 0; j < n; j++)
        {
            scanlld(input);
            poss[j] = input;
        }

        dp[0] = 1;
        ll ans = solve(K);

        printf("Case %lld: %lld\n", i, ans);
    }

    return 0;

}
