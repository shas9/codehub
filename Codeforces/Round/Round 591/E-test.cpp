#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define fr first
#define sc second

vector<pair<ll,pair<ll,ll>>>vec;
ll cnt[500005];

int main()
{
    ll test,t,i,j,k,a,b,c,x,y,z,m,ans,n;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        scanf("%lld%lld",&n,&m);

//        m 	*= 2;
        for(i=1;i<n;i++)
        {
            scanf("%lld%lld%lld",&a,&b,&c);
            vec.push_back(mp(c,mp(a,b)));
        }
        for(i=0;i<=n;i++)
            cnt[i]=0;
        sort(vec.begin(),vec.end());
        ans=0;
        z=vec.size();
        for(i=z-1;i>=0;i--)
        {
            a=vec[i].sc.fr;
            b=vec[i].sc.sc;
            if(cnt[a]>=m || cnt[b]>=m)
                continue;
            cnt[a]++;
            cnt[b]++;
            ans+=vec[i].fr;
        }
        vec.clear();
        printf("%lld\n",ans);

    }
    return 0;
}
