
#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%llu", &longvalue)
#define plld(longvalue) printf("%llu\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll unsigned long long int

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        ans = 0;

        for(i = 1; i <= n; i++)
        {
            slld(m);

            ans += (m % 1000000007);

            if(ans > 1000000007)
            {
                ans = ans % 1000000007;
            }
        }

        plld(ans);
    }


}


