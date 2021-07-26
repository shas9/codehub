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

    char sent[100010];
    char x;

    for(i = 1; i <= testcase; i++)
    {
        scanlld(flag);

        scanf(" %[^\n]s", sent);

        tag = strlen(sent);

        for(j = 0; j < tag; j++)
        {
            if(sent[j] >= 'A' && sent[j] <= 'Z' && sent[j] != 32)
            {
                sent[j] += 32;

            }

            if(sent[j] != 32)
            {
                printf("%c", sent[j]);
            }
        }

        cout << endl;

    }


}

