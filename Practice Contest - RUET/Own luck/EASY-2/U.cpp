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
    ll flag, tag;

    scanlld(testcase);

    ll donation;

    string input, f1 = "donate", f2 = "report";

    for(i = 1; i <= testcase; i++)
    {
        scanlld(flag);
        donation = 0;

        cout << "Case " << i << ":" << endl;

        for(j = 1; j <= flag; j++)
        {
            cin >> input;

            if(input == f1)
            {
                cin >> tag;
                donation += tag;
            }
            else
            {
                cout << donation << endl;
            }
        }
    }


}


