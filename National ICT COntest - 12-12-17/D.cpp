#include<bits/stdc++.h>
#define mx 100005
#define pii pair<long long,long long>

using namespace std;
typedef long long ll;
ll n,s;
pii arr[mx];
ll ans;

int main()
{
    cin>>n>>s;
    for(ll i=0;i<n;i++)
        scanf("%lld%lld",&arr[i].first,&arr[i].second);
    ans=0;
    sort(arr,arr+n);
    for(ll i=0;i<n;i++)
    {
        s+=arr[i].first;
        ans+=(s-arr[i].second);
    }
    cout<<ans<<endl;
    return 0;
}
