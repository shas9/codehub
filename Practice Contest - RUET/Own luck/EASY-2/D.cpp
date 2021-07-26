#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanlf(longvalue) scanf("%lf", &longvalue)
#define printlf(longvalue) printf("%lf\n", longvalue)
#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")




using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;
    ll me, lift;
    ll sum;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(me);
        scanlld(lift);

        if(lift >= me)
        {
            sum = (lift * 4) + 10 + 9;
        }
        else
        {
            sum = 10 + 9 + (me * 4) + ((me - lift) * 4);
        }

        printcase(i,sum);

    }

    return 0;
}
