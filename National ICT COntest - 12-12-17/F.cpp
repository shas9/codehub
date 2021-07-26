#include <bits/stdc++.h>

using namespace std;

#define mx 1000006
int b[mx],n,cnt[mx];
multiset<int>ind;
vector<int>mxid[mx];


int main()
{
    cin>>n;
    int mxi=0;
    int mxe=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        ind.insert(i);
        mxid[b[i]].push_back(i);
        cnt[b[i]]++;
        mxi=max(cnt[b[i]],mxi);
    }

    int dis;
    int mxs=0;

    if(mxi==1)
    {
        cout<<1+(2*(n-1))<<endl;
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        dis=0;
        if(cnt[b[i]]==mxi)
        {
            dis=mxid[b[i]][0];
            int len=mxid[b[i]].size();
            for(int j=0;j< len-1;j++)
                dis+=(mxid[b[i]][j+1]-mxid[b[i]][j]);
            dis+=(n-mxid[b[i]][len-1]);
            if(dis>mxs)
            {
                mxs=dis;
                mxe=b[i];
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(b[i]==mxe)
        {
            ind.erase(i);
        }
    }

    int ans=0;
    ans+=mxi;
    //cout<<mxe<<" "<<mxi<<endl;
    int t=0;
    while(!ind.empty())
    {
         t++;
         for(int i=0;i<mxi;i++)
         {
             if(ind.find((mxid[mxe][i]+t)%n)!=ind.end())
             {
                 ans++;
                 ind.erase(ind.find((mxid[mxe][i]+t)%n));
             }
         }
         ans++;
    }
    cout<<ans<<endl;
    return 0;
}
