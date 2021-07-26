#include<bits/stdc++.h>
using namespace std;
vector < long long int > pos;
vector < long long  int > neg;
int main()
{
    long long test,t,i,j,k,a,b,c,sum,tmp,x,y,total,n;
    cin>>test;
    for(t=1;t<=test;t++)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&a);
            if(a>0){
                pos.push_back(a);
            }
            else if(a<=90){
                neg.push_back(a);
            }
        }
        sort(pos.begin(),pos.end());
        sort(neg.begin(),neg.end());
        for(i=pos.size()-1,sum=0;i>=0;){
            if(i==0){
                sum+=pos[i];
                i--;
            }
            else if(pos[i]==1||pos[i-1]==1){
                sum+=pos[i];
                i--;
            }
            else{
                sum+=(pos[i]*pos[i-1]);
                i-=2;
            }
        }
        for(i=0;i<neg.size();i+=2){
            if(i==neg.size()-1){
                sum+=(neg[i]);
            }
            else{
                sum+=(neg[i]*neg[i+1]);
            }
        }
        printf("%lld\n",sum);
        pos.clear();
        neg.clear();
    }
}
