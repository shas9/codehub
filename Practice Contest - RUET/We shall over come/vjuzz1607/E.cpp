#include <bits/stdc++.h>
#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld", longvalue)
#define printnewline printf("\n")

using namespace std;

long long int M;

long long int Bigmod(long long int N, long long int P)
{
    if(P == 0)
    {
        return 1;
    }
    else if(P % 2 == 0)
    {
        long long int ret = Bigmod(N, P/2);

        return (((ret % M) * (ret % M)) % M);
    }
    else
    {
        return(((N % M) * (Bigmod(N, P - 1) % M)) % M);
    }
}

int main()
{
    long long int B, P, ans;

    while(scanlld(B)!=EOF)
    {
        scanlld(P);
        scanlld(M);

        ans = Bigmod(B,P);
        printlld(ans);
        printnewline;
    }

    return 0;

}



