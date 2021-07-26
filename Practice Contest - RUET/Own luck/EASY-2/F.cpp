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

    ll x1, x2, y1, y2, x, y;

    for(i = 1; i <= testcase; i++)
    {

        scanlld(x1);
        scanlld(y1);
        scanlld(x2);
        scanlld(y2);


        scanlld(n);

        printf("Case %lld:\n", i);

        for(j = 0; j < n; j++)
        {
            scanlld(x);
            scanlld(y);

            if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }

    }


}


