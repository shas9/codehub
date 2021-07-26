#include <stdio.h>

int coins[110];
long dp[10005];
int n,K;
int mod = 100000007;

long solve(int K)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 1; j <= K; j++)
        {
            if(coins[i] <= j)
            {
                dp[j] = dp[j] % mod + dp[j-coins[i]] % mod;
            }
        }
    }

    return dp[K];
}

int main()
{
    int i, j;
    int testcase;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d%d", &n, &K);

        for(j = 1; j <= K; j++)
        {
            dp[j] = 0;
        }

        for(j = 0; j < n; j++)
        {
            scanf("%d", &coins[j]);
        }

        dp[0] = 1;

        printf("Case %d: %ld\n", i, solve(K) % mod);
    }

    return 0;

}
