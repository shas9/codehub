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
    ll r1, r2, c1, c2;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(r1);
        scanlld(c1);

        scanlld(r2);
        scanlld(c2);

        flag = (r1 + c1) % 2;
        tag = (r2 + c2) % 2;

        if(tag != flag)
        {
            printf("Case %lld: impossible\n", i);
        }
        else
        {
            flag = r1 - c1;
            tag = r2 - c2;

            if(flag == tag)
            {
                printf("Case %lld: 1\n", i);
            }
            else
            {
                flag = r1 + c1;
                tag = r2 + c2;
                if(flag == tag)
                {
                    printf("Case %lld: 1\n", i);
                }
                else
                {
                    printf("Case %lld: 2\n", i);
                }
            }
        }
    }
}


