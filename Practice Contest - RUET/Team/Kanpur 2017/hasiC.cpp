#include <bits/stdc++.h>

#define LL  long long
#define SL(n) scanf("%lld", &n)

using namespace std;
#define lim 1000100
#define mod 1000000007
LL cumsum[lim];
LL G[lim];
LL S[lim];
LL fact[lim];
int main()
{

    LL cs;
    SL(cs);

    fact[0] = 1;
    for(LL i =1; i<lim ; i++) fact[i] = (i*fact[i-1])%mod;

    for(LL T = 1; T<=cs; T++)
    {
        memset(cumsum, 0, sizeof cumsum);
        LL Kp,Ks;
        SL(Kp);
        SL(Ks);
        LL sum = Kp*Ks;
        LL n;
        SL(n);

        for(LL i = 1; i<=n ; i++) SL(G[i]);

        for(LL i = 1; i<=n ; i++) SL(S[i]);

        sort( S+1,S+1+n );
        sort( G+1,G+1+n);

        LL f1 = 0 , f2 = 0;

        for( LL i = 1 ; i<=n ; i++ ){
            if( S[1] * G[i] <= sum ) f1++;
            if( G[1] * S[i] <= sum ) f2++;
        }

        LL mn = max(f1,f2);

        if( f1 == 0 ) {
             printf("Case %lld: %lld\n", T, fact[n]);
             continue;
        }

        //cout<<"fs: "<<f1<<" "<<f2<<endl;

        LL ans = (f1 * fact[n-1]) %mod;
        ans += (( ( (n-f1)*(f2-1)) % mod )*fact[n-2])%mod;
        ans = (ans%mod+mod)%mod;

        ans = (fact[n] + mod - ans)%mod;
        printf("Case %lld: %lld\n", T, ans);
    }

    return 0;
}
