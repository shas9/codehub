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

ll dp[55][1005];
ll coins[55];
ll used[55];
ll K;
ll cnt;
ll coin_size;
ll mod = 100000007;

ll solve(ll pos, ll sum)
{
    ll ans = 0;

    if(sum == K)
    {
        return 1;
    }

    if(pos == coin_size)
    {
        return 0;
    }

    if(dp[pos][sum] != -1)
    {
        return dp[pos][sum];
    }

    for(ll j = 0; (j <= used[pos]) && ((j * coins[pos]) + sum <= K); j++)
    {
        ans += solve(pos + 1, sum + (j * coins[pos]));
        cout << ans << endl;
        ans = ans % mod;
    }

    return dp[pos][sum] = ans;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        memset(dp,-1,sizeof(dp));

        scanlld(coin_size);
        scanlld(K);

        for(j = 0; j < coin_size; j++)
        {
            scanlld(input);
            coins[j] = input;
        }

        for(j = 0; j < coin_size; j++)
        {
            scanlld(input);
            used[j] = input;
        }
        printf("Case %lld: %lld\n", i, solve(0,0));
    }

    return 0;


}



