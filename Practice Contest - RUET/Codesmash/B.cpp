
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

    double r;
    double pi = 3.141593;

    scanlld(testcase);

    double areaC;
    double areaC4;

    double areaS;
    double areaT;

    double areaG;
    double areaG1;
    double areaG2;

    for(i = 1; i <= testcase; i++)
    {
        scanlf(r);

        areaC = pi * r * r;
        areaC4 = areaC / 4.0;

        areaS = r * r;

        areaG1 = areaS - areaC4;

        areaT = (r * r) / 2.0;

        areaG2 = areaC4 - areaT;

        areaG = areaG1 + areaG2;

        printlf(areaG);

    }


}


