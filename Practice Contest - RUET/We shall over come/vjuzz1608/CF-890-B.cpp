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

    ll lastvisit[200005];

    memset(lastvisit,999999,sizeof(lastvisit));

    scanlld(testcase);
    vector < ll > cafe;
    cafe.clear();

    ll minimum = 9999999;

    for(i = 1; i <= testcase; i++)
    {
        scanlld(input);

        cafe.push_back(input);

        lastvisit[input] = i;
    }

    ll ans = 0;

    for(i = 0; i <= testcase; i++)
    {
        //cout << i << " " << lastvisit[i] << endl;
        if(minimum > lastvisit[i])
        {
            minimum = lastvisit[i];
            ans = i;
        }
    }

    cout << ans << endl;


}


