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
    ll a, b;
    ll lights, limit;

    bool check[10005];

    ll manual[10005];

    scanlld(testcase);


    for(i = 1; i <= testcase; i++)
    {
        memset(check,false,sizeof(check));
        for(j = 1; j <= lights; j++)
        {
            manual[j] = 1;
        }
        flag = 0;

        scanlld(lights);
        scanlld(limit);

        for(j = 1; j <= limit; j++)
        {
            scanlld(a);
            scanlld(b);

            if(check[b] == false)
            {
                check[b] = true;
                if(manual[b] == 1)
                {
                    manual[b] = 0;
                }
            }
        }

        ll ans = 0;

        for(j = 1; j <= lights; j++)
        {
            if(manual[j] == 1)
            {
                ans++;
            }
        }

        printcase(i,ans);
    }


}


