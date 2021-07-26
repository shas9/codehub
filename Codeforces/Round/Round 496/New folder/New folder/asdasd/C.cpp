#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[1001][1001];
ll ara[1001];

int main()
{
    ll n,m;
    while(1)
    {
        scanf("%lld %lld",&n,&m);
        if(n==0 && m==0)
            return 0;
        memset(dp,0,sizeof(dp));
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&ara[i]);
        }
        for(ll i=0;i<=n;i++)
            dp[i][0]=1;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=i;j++)
            {
                dp[i][j]=( (dp[i-1][j]%m) + ((ara[i] %m ) * ( dp[i-1][j-1] % m ) ) % m ) % m;
            }
        }
        ll ans=0;
        for(ll i=1;i<=n;i++)
            ans=max(ans,dp[n][i]);
        printf("%lld\n",ans);
    }

}
