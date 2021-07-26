#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define sc second
#define fr first
#define scl(n) scanf("%lld",&n)
#define scll(n,m) scanf("%lld%lld",&n,&m)
#define scs(ch) scanf("%s", ch)
#define pll pair< ll,ll >

set < ll > st;
set < ll > :: iterator it;

vector < ll > vec;

ll ara[100005];

int main()
{
    ll test,t,i,j,k,a,b,c,x,y,z,n,m;
    scl(test);
    for(t=1;t<=test;t++){
        scl(n);
        z=0;
        for(i=1;i<=n;i++){

            scl(ara[i]);

            z+=ara[i];
        }

        if(z%2){
            printf("N\n");
            continue;
        }

        for(i=1;i<=n;i++){
            a=z-ara[i];
            if(a<0){
                printf("N\n");
                break;
            }
        }
        if(i>=n){
            printf("Y\n");
        }


    }


    return 0;
}

