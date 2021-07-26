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
    ll zero;
    ll div;

    scanlld(n);
    scanlld(zero);

    ll ans = 0;

    if(zero == 0)
    {
        ans = n;

        printlld(ans);
        return 0;
    }
    else
    {
        div = 1;

        for(i = 1; i <= zero; i++)
        {
            div = div * 10;
        }

        if(n % div == 0)
        {
            ans = n;

            printlld(ans);
            return 0;
        }

        while(1)
        {
            ans += (n * 10);

            if(ans % div == 0)
            {
                break;
            }
        }

        printlld(ans);
        return 0;
    }

}

