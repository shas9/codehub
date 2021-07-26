
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

    scanlld(n);

    printf("*");
    for(i = 1; i <= n - 2; i++)
    {
        printf(" ");
    }
    printf("* ");
    for(i = 1; i <= n; i++)
    {
        printf("*");
    }

    printnewline;

    for(i = 1; i <= n - 2; i++)
    {
        //printnewline;
        printf("*");

        for(j = 1; j <= n - 2; j++)
        {
            printf(" ");
        }

        printf("* *");

        for(j = 1; j <= n - 2; j++)
        {
            printf(" ");
        }

        printf("*");
        printnewline;

    }

    for(i = 1; i <= n; i++)
    {
        printf("*");
    }

    printf(" *");

    for(i = 1; i <= n - 2; i++)
    {
        printf(" ");
    }

    printf("*\n");




}

