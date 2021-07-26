#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[110],b[110];
int main()
{
    int n;
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        __int64 ans=1;
        int k=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i])
            b[k++]=i;
            printf("Here k = %d, i =%d, a[i] = %d\n", k, i, a[i]);
        }
        if(k==0)
        cout<<0<<endl;
        else if(k==1)
        cout<<1<<endl;
        else
        {
            for(int i=1;i<k;i++)
            {
                ans=ans*(b[i]-b[i-1]);
                printf("ans = %lld\ni = %d, b[i] = %d, b[i - 1] = %d\n", ans, i, b[i], b[i - 1]);
            }
            cout<<ans<<endl;

        }
    }
    return 0;
}
