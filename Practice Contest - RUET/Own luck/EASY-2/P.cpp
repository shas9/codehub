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

    scanlld(testcase);

    ll precase;

    for(i = 1; i <= testcase; i++)
    {
        ll ans = 0;

        scanlld(precase);

        tag = 2;

        for(j = 1; j <= precase; j++)
        {
            scanlld(input);

            if(tag < input)
            {
                if((input - tag) > 5)
                {
                    flag = input - tag;

                    if(flag % 5 == 0)
                    {
                        ans += (flag / 5);
                    }
                    else
                    {
                        ans++;
                        ans += (flag / 5);
                    }
                }
                else
                {
                    ans++;

                }
            }

            tag = input;
        }

        printcase(i,ans);

    }


}


