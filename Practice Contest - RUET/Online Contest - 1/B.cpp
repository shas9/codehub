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




using namespace std;

int main()
{
    ll i, j, l, m, n, o;
    ll k;
    ll testcase;

    char input[100000];

    scanf("%s", input);
    int ln;

    for(ln = 0; input[ln] != '\0'; ln++);

    int value;
    int ans;

    value = ((input[ln - 2] - 48) * 10) + (input[ln - 1] - 48);

    if(value % 4 == 0)
    {
        ans = 4;
    }
    else
    {
        ans = 0;
    }

    printf("%d\n", ans);

}


