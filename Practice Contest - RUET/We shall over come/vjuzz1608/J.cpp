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

ll dp[55][25];
ll coins[55];
map < ll, ll > coins_total;
ll K;
ll cnt;
ll coin_size;

ll solve(ll pos, ll used, ll sum)
{
    //cout << "Pos: " << pos << " Used: " << used << " Sum: " << sum << endl;

    if(sum == K)
    {
        cnt++;

        return 0;
    }

    if(sum > K)
    {
        return 0;
    }

    if(used < coins_total[coins[pos]])
    {
        dp[pos][used + 1] = solve(pos,used + 1,sum + coins[pos]);
    }

    if(pos < coin_size)
    {
        solve(pos + 1, 0, sum);
    }
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
        memset(coins,0,sizeof(coins));
        coins_total.clear();

        scanlld(coin_size);
        scanlld(K);

        cnt = 0;

        for(j = 1; j <= coin_size; j++)
        {
            scanlld(input);
            coins[j] = input;
        }

        for(j = 1; j <= coin_size; j++)
        {
            scanlld(input);
            coins_total[coins[j]] = input;
        }

        solve(1,0,0);

        printf("Case %lld: %lld\n", i, cnt);
    }

    return 0;


}

