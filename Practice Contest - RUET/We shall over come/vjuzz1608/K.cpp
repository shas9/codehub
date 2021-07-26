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

ll dp[101][10001];
vector < ll > coins;
ll K;
ll n;
ll cnt;

ll solve(ll pos, ll amount)
{
    ll ans = 0;
    if(amount == K)
    {
        return 1;
    }

    if(pos == n)
    {
        return 0;
    }

    if(dp[pos][amount] != -1)
    {
        return dp[pos][amount];
    }

    for(ll i = 0; (i <= K) && (amount + i * coins[pos] <= K); i++)
    {
        ans += solve(pos + 1, amount + (i * coins[pos]));

        if(ans >= 100000007)
        {
            ans = ans % 100000007;
        }
    }

    return dp[pos][amount] = ans;
}

int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(n);
        scanlld(K);

        memset(dp,-1,sizeof(dp));
        coins.clear();

        for(j = 1; j <= n; j++)
        {
            scanlld(input);

            coins.push_back(input);
        }

        ll ans = solve(0,0);

        printf("Case %lld: %lld\n", i, ans);
    }

    return 0;


}

