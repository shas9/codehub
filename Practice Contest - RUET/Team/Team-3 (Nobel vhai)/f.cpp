#include<bits/stdc++.h>
using namespace std;
long long t=100,l=0,r=INT_MAX,mid,ans;
main()
{
    long long n,m;
    scanf("%lld %lld",&n,&m);
    if(n<=m)
    {
        printf("%lld",n);
        return 0;
    }
    while(t--)
    {
        mid=(l+r)/2;
        if(n-mid*(mid+1)/2<=m)
            r=mid;
        else
            l=mid;
    }
    ans=mid+m+1;
    printf("%lld",ans);
}
