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

using namespace std;

int main()
{
    ll i, j, k, l, m, n, o, p;
    ll testcase;
    ll input, flag, tag;
    ll ans;

    slld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        ans = 0;

        slld(n);
        slld(p);

        j = 1;


        if(n == 0 && p == 1)
        {
            ans = 1;
        }
        else
        {
            while(1)
            {
                flag = n;

                ans += flag / pow(p,j);

                if(n / pow(p,j) == 0)
                {
                    break;
                }

                j++;
            }
        }

        printf("Case %lld: %lld\n", i, ans);
    }


}

