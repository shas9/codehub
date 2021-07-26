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

ll dp[17][132000];
ll mat[17][17];
ll maxprio;
ll mat_size;
ll sum;

ll solve(ll pos, ll mask)
{
    if(pos == mat_size + 1)
    {
        return 0;
    }

    if(dp[pos][mask] == -1)
    for(ll i = 1; i <= mat_size; i++)
    {
        if((mask & (1 << (i - 1))) == 0)
        {
            ll mask2 = (mask | (1 << (i - 1)));
            dp[pos][mask] = max(dp[pos][mask],mat[pos][i] + solve(pos + 1, mask2));
        }
    }

    return dp[pos][mask];
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
        memset(mat,0,sizeof(mat));

        scanlld(mat_size);

        for(j = 1; j <= mat_size; j++)
        {
            for(k = 1; k <= mat_size; k++)
            {
                scanlld(input);

                mat[j][k] = input;
            }
        }

        maxprio = -9999;

        flag = solve(1,0);

        printf("Case %lld: %lld\n", i, flag);
    }


}


