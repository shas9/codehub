
#include <bits/stdc++.h>

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

    scanlld(testcase);

    ll input;
    for(i = 1; i <= testcase; i++)
    {
        scanlld(input);

        printf("Case %lld: ", i);

        if(input == 1)
        {
            printf("bc\n");
        }
        else if(input == 2)
        {
            printf("abdeg\n");
        }
        else if(input == 3)
        {
            printf("abcdg\n");
        }
        else if(input == 4)
        {
            printf("bcfg\n");
        }
        else if(input == 5)
        {
            printf("acdfg\n");
        }
        else if(input == 6)
        {
            printf("acdefg\n");
        }
        else if(input == 7)
        {
            printf("abc\n");
        }
        else if(input == 8)
        {
            printf("abcdefg\n");
        }
        else if(input == 9)
        {
            printf("abcdfg\n");
        }
        else if(input == 0)
        {
            printf("abcdef\n");
        }
    }


}

