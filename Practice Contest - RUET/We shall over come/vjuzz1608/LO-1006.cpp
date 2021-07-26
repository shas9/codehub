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

ll dp[15000];

ll fn( ll n )
{
    if(dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        dp[n] = fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6);
        dp[n] = dp[n] % 10000007;
    }

    return dp[n];
}
int main()
{
    ll n, caseno = 0, cases;
    ll a, b, c, d, e, f;

    scanf("%lld", &cases);

    while( cases-- )
    {
        memset(dp,-1,sizeof(dp));

        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);

        dp[0] = a;
        dp[1] = b;
        dp[2] = c;
        dp[3] = d;
        dp[4] = e;
        dp[5] = f;

        printf("Case %lld: %lld\n", ++caseno, fn(n) % 10000007);
    }

    return 0;
}
