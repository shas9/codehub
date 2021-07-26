#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

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
    ll input, tag, flag;

    //read:
    ll ans = 1;
    ll cased = 0;

    scanlld(testcase);

    tag = 0;
    flag = -1;
    m = 0;

    for(i = 1; i <= testcase; i++)
    {
        scanlld(input);

        if(input == 1)
        {
            if(flag == -1)
            {
                flag = i;
            }
            else
            {
                ans = ans * (i - flag);
                flag = i;
                //printf("ans = %lld, i = %lld\n", ans, i);
            }
            tag = 1;
        }
    }

    if(tag == 0)
    {
        ans = 0;
    }

    printlld(ans);


    return 0;
}


