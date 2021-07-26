#include<bits/stdc++.h>
using namespace std;
#define ll  long long
int dp[10003][10002];
ll ara[3][10005],mod=1000000007;


int main()
{
    ll test,t,i,j,k,a,b,c,n,m,x=0,y,z=1,sum;
    for(i=1;i<=10001;i++){
        for(j=0;j<=10000;j++){
            if(i==1){
                dp[i][j]=1;
                if(j==0){
                    ara[x][j]=1;
                }
                else{
                    ara[x][j]=ara[x][j-1]+1;
                }
                continue;
            }
            dp[i][j]=(int)ara[z][j];
            if(j==0){
                ara[x][j]=(long long)dp[i][j];

            }
            else{
                ara[x][j]=(ara[x][j-1]+(long long)dp[i][j])%mod;
            }
        }
        x=(x+1)%2;
        z=(z+1)%2;
    }
    cin>>test;
    for(t=1;t<=test;t++)
    {
        scanf("%lld %lld",&a,&b);
        printf("%d\n",dp[a+1][b]);
    }

}
