/*
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
*/
#include <bits/stdc++.h>
#define LL              long long
#define ll              long long
#define SL(n)           scanf("%lld",&n)
#define LF              double
#define SF(n)           scanf("%lf",&n)

#define pb              push_back
#define mp              make_pair

#define ON(n,i)         (n|(1LL<<i))
#define OFF(n,i)        (n&(~(1LL<<i)))
#define CHK(n,i)        (n&(1LL<<i))

#define ff              first
#define ss              second

#define SET(arr)        memset( arr , -1 , sizeof arr)
#define RESET(arr)      memset( arr,0,sizeof arr)

#define srt(v)          sort(v.begin(),v.end())
#define uniq(v)			v.resize(distance(v.begin(),unique(v.begin(),v.end())))
#define found( s,d )    (s.find(d) != s.end())

#define FOR(i,s,e)      for( LL i = s ; i<=e ; i++ )
#define RFOR(i,e,s)     for( LL i = e ; i>=s ; i-- )


#define FILEIN          freopen("in.txt","r",stdin)
#define FILEOUT         freopen("WA.txt","w",stdout)

#define DEBUG(x)        cerr<<#x<<" = "<<x<<endl
#define PRINTALL(v)     {cerr<<endl<<"Printing: "<<#v<<endl;for(LL i = 0 ; i<v.size(); i++) DEBUG(v[i]); cerr<<endl;}

using namespace std;

unsigned LL dp[2][150];
LL fact[25];

int main(){



    LL cs;
    SL(cs);
    FOR(T,1,cs){
        LL n,x;
        SL(n);SL(x);

        LL prev = 1,now = 0;
        for( LL i = 0 ; i<x ; i++ ) dp[0][i] = 1;


        FOR(i,1,n){
            prev ^= 1;
            now ^= 1;
            FOR(make,0,x-1){
                if(make)
                    dp[now][make] = dp[prev][make-1] - ( (make>=7)?dp[prev][make-7]:0 );
                else dp[now][make] = 0;
                if(make) dp[now][make]+=dp[now][make-1];
            }
        }


        unsigned LL z = 1;
        FOR(i,1,n) z = z*6;

        unsigned LL y = z - dp[now][x-1];

        unsigned LL g = __gcd(z,y);

        y = y/g;
        z = z/g;

        if(z==1) printf("Case %lld: %llu\n", T,y);
        else printf("Case %lld: %lld/%llu\n", T,y,z);


    }


return 0;}
