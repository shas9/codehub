
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
    ll input;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(input);

        if(input == 1)
        {
            printf("*\n");
        }
        else if(input == 2)
        {
            printf("**\n**\n");
        }
        else
        {
            for(j = 1; j <=input; j++)
            {
                printf("*");
            }
            printnewline;
            for(j = 1; j <= input - 2; j++)
            {
                printf("*");

                for(k = 1; k <= input - 2; k++)
                {
                    printf(" ");
                }

                printf("*");
                printnewline;
            }
            for(j = 1; j <=input; j++)
            {
                printf("*");
            }
            printnewline;
        }

        printnewline;
    }


}


