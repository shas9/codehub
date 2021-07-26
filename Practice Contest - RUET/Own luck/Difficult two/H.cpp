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

bool number[130000];
void sieve()
{
    ll i, j, k, l;

    for(i = 2; i*i <= 130000; i++)
    {
        if(number[i] == false)
        {
            for(j = i * i; j <= 130000; j = j + i)
            {
                number[j] = true;
            }
        }
    }
}


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll result;


    sieve();

    ll input;
    ll tag, flag;

    scanlld(input);
    ll color[input];

    if(input == 1 || input == 2)
    {
        printf("1\n");
    }
    else
    {
        printf("2\n");
    }

    printf("1");
    for(i = 2; i <= input; i++)
    {
        if(number[i + 1] == false)
        {
            printf(" 1");
        }
        else
        {
            printf(" 2");
        }
    }

    printf("\n");

    return 0;


}

