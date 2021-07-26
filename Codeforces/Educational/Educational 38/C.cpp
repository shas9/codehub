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

#define mod 1000000009


using namespace std;

map < ll , ll > sqr;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    for(i = 1; i * i <= 1000000000; i++)
    {
        sqr[i * i] = i;
    }
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(input);

        flag = 0;

        for(j = 1; j <= 40000; j++)
        {
            ll y = input + j*j;

            if(sqr.find(y)!=sqr.end())
            {
                ll sqq=sqr[y];
                ll te = sqq / j;
                if(((sqq*sqq) - (sqq/te)*(sqq/te) == input)
                {
                    printf("%lld %lld\n",sqq,te);
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0)
        {
            printf("-1\n");
        }
    }


}


