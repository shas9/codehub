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
    ll a, b;
    ll minchess_a = 99999999999999999, maxchess_a = -99999999999999999;
    ll minclass_a = 99999999999999999, maxclass_a = -99999999999999999;

    ll minchess_b = 99999999999999999, maxchess_b = -99999999999999999;
    ll minclass_b = 99999999999999999, maxclass_b = -99999999999999999;

    ll ans1 = -999, ans2 = -999, ans3 = -999, ans4 = -999, ans5 = -999;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(a);
        scanlld(b);

        minchess_a = min(minchess_a,a);
        maxchess_a = max(maxchess_a,a);

        maxchess_b = max(maxchess_b,b);
        minchess_b = min(minchess_b,b);
    }

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(a);
        scanlld(b);

        minclass_a = min(minclass_a,a);
        maxclass_a = max(maxclass_a,a);

        maxclass_b = max(maxclass_b,b);
        minclass_b = min(minclass_b,b);
    }

    ll ans;
    flag = 0;

    ans = max(maxchess_a - minclass_b, maxclass_a - minchess_b);

    //cout << maxchess_a << " " <<  minclass_b << " " << maxclass_a << " " << minchess_b << endl;
    //cout << maxchess_a - minclass_b << " " << maxclass_a - minchess_b << endl;
    ans = max(ans,flag);

    cout << ans << endl;


}


