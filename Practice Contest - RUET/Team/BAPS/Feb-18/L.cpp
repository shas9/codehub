
#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000007


using namespace std;

ll dp[1000005];
ll rec(ll n)
{
    if(n < 0)
    {
        return 0;
    }

    if(n == 0)
    {
        return 1;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = ((rec(n - 2) % 1000000007)  + (rec(n - 3) % 1000000007) ) % 1000000007;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    slld(testcase);

    memset(dp,-1,sizeof(dp));

    for(i = 1; i <= 1000000; i++)
    {
        rec(i);
    }

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(input);

        plld(dp[input]);


    }


}

