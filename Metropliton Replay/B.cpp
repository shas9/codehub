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

    ll totalapple = 0;

    scanlld(n);
    scanlld(m);

    for(i = 1; i <= n; i++)
    {
        scanlld(input);

        totalapple += input;
    }

    ll ans;

    if(totalapple % m == 0)
    {
        ans = totalapple / m;
    }
    else
    {
        ans = totalapple / m;
        ans += 1;
    }

    cout << ans << endl;

}


