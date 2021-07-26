#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string.h>
#include<map>
typedef long long LL;
using namespace std;
typedef struct node
{
    int x,y;
} ss;
int ans[300006],bns[300006];
ss a[300006];
int er(int l,int r,int ask);
bool cmp(node p,node q);
LL dp[300006];
LL mod = 1e8;
int main(void)
{
        freopen("in.txt", "r", stdin);

    int n;
    while(scanf("%d",&n),n!=-1)
    {
        int cn = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d",&a[i].x,&a[i].y);
            ans[cn++] = a[i].x;
            ans[cn++] = a[i].y;
        }
        sort(ans,ans+cn);
        bns[1] = ans[0];int t = 1;
        for(int i = 1;i < cn;i++)
        {
            if(ans[i]!=ans[i-1])
            {
                t++;
                bns[t] = ans[i];
            }
        }
        for(int i = 0;i < n;i++)
        {
            a[i].x = er(1,t,a[i].x);
            a[i].y = er(1,t,a[i].y);
        }
        memset(dp,0,sizeof(dp));
        int u = 1;
        sort(a,a+n,cmp);
        for(int i = 0;i < n;i++)
        {
            while(u <= a[i].y)
            {
               dp[u] = dp[u-1];
               u++;
            }
            dp[u-1] = (dp[u-1] + dp[a[i].x] + 1)%mod;
        }
        printf("%08lld\n",dp[a[n-1].y]);
    }
    return 0;
}
int er(int l,int r,int ask)
{
    int mid = (l+r)/2;
    if(bns[mid] == ask)
     return mid;
    else if(bns[mid] > ask)
        return er(l,mid-1,ask);
    else return er(mid+1,r,ask);
}
bool cmp(node p,node q)
{
    if(p.y == q.y)
        return p.x < q.x;
    else return p.y < q.y;
}
