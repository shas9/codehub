#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll test;
    cin>>test;
    while(test--)
    {
        ll n,cnt=0,sztl=0,sztr=0,x=0,sltn=0,srtn=0;
        cin>>n;
        ll a[200001]= {0};
        ll b[n+5];
        ll compare[n+5];
        bool com=false,r=false,l=false;
        for(ll i=0; i<n; i++)
        {
            ll p;
            cin>>p;
            b[i]=p;
            compare[i]=p;
            a[p]+=1;  //FREQUENCY ARRAY
        }
        for(ll i=0; i<n; i++)
        {
            if(a[i]>1)
            {
                cnt++;
            }
        }
        ll left=min(cnt,n-cnt);
        ll right=max(cnt,n-cnt);
        ll ls=(left*(left+1))/2;  //CUMSUM
        ll rs=(right*(right+1))/2; //CUMSUM
        for(ll i=0; i<left; i++) sztl+=b[i];
       // cout<<sztl<<"<-sztl:ls->"<<ls<<" rs-> "<<rs<<endl;

        for(ll i=0; i<right; i++) sztr+=b[i];
        //cout<<sztr<<"<-sztr:ls->"<<ls<<" rs-> "<<rs<<endl;

//SZTL=sum_zero_to_leftmost
//SZTR=sum_zero_to_right
        sort(compare,compare+n);
        if(compare[0]==compare[n-1])  //TO CHECK EVERY ELEMENT WHEATHER SAME OR NOT
            com=true;
        if(!com)
        {
            if(sztl == ls)
                {
                    x++;
                    l=true; //PARTITION MARK
                }
            if(sztr == rs)
                {x++;
                r=true;} //PARTITION MARK
            if(x==1)
            {
                cout<<x<<endl;
                if(r)
                {cout<<right<<" "<<left<<endl;}
                else if(l) cout<<left<<" "<<right<<endl;
            }
            else if(x==2)
            {
                cout<<x<<endl<<left<<" "<<right<<endl;
                cout<<right<<" "<<left<<endl;
            }
            else if(x==0)
                cout<<"0"<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
    }
    return 0;
}
