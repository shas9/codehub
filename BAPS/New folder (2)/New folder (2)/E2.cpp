#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n,m;
    cin>>n>>m;
    ll tot=0,ans=0;
    for(ll i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        tot+=x;
        if(n==1)
            continue;
        if(y>=0)
        {
            ans+=((y*n*(n-1))/2);
        }
        else
        {
            ll t=n/2;
            if(n%2==1)
            {
                ans=ans+(y*t*(t+1));
            }
            else
            {
                ans=ans+(y*t*t);
            }
        }
    }
    double vairkoto= (double) tot + (double) ans / (double)n;
    printf("%.8f",vairkoto);

}
