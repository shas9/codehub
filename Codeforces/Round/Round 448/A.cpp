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
    ll total = 0;

    vector < ll > value;

    scanlld(testcase);

    value.clear();

    for(i = 1; i <= testcase; i++)
    {
        scanlld(input);

        value.pb(input);

        total += input;
    }

    if(testcase == 1)
    {
        cout << total << endl;
    }
    else if(testcase == 2)
    {
        cout << abs(value[0] - value[1]) << endl;
    }






}

