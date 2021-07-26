#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll test;
    cin>>test;
    while(test--)
    {
        ll n,cnt=0;
        cin>>n;
        ll a[200000]={0};
        ll b[n];
        bool check=false;
        bool check1 = false;

        for(ll i=0;i<n;i++)
        {
            ll p;
            cin>>p;
            b[i]=p;
            a[p]+=1;
        }
        for(ll i=0;i<200000;i++)
        {
            if(a[i]>1)
            {
                cnt++;
                check=true;
            }
            if(a[i]>1 && i==0) check1=true;
        }
        if((check) && (check1))
        {
            cout<<"2"<<endl;
            cout<<abs(n-cnt)<<" "<<cnt<<endl;
            cout<<cnt<<" "<<abs(n-cnt)<<endl;
        }
        else
        {
            cout<<"1"<<endl;
            cout<<abs(n-cnt)<<" "<<cnt<<endl;
        }
    }
    return 0;
}
