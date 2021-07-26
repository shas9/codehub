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

    scanlld(testcase);

    ll input;

    vector < ll > triangle;

    ll tag = 1;

    for(i = 1; i <= testcase; i++)
    {
        triangle.clear();

        for(j = 1; j <= 3; j++)
        {
            scanlld(input);

            triangle.push_back(input);
        }

        sort(triangle.begin(), triangle.end());

        if(triangle[2] >= (triangle[0] + triangle[1]))
        {
            tag = 0;
        }
    }

    if(tag == 0)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }


}

