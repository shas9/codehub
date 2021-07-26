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
    ll cumsum[200005];
    ll maxtime;
    ll q;

    memset(cumsum,0,sizeof(cumsum));

    scanlld(testcase);
    scanlld(maxtime);
    scanlld(q);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(a);
        scanlld(b);

        cumsum[a]++;
        cumsum[b+1]--;
    }

    for(i = 1; i <= 200000; i++)
    {
        cumsum[i] += cumsum[i-1];
    }

    for(i = 1; i <= 200000; i++)
    {

        if(cumsum[i] >= maxtime)
        {
            cumsum[i] = 1;
        }
        else
        {
            cumsum[i] = 0;
        }
        cumsum[i] += cumsum[i-1];
    }

    for(i = 1; i <= q; i++)
    {
       ll sum = 0;

       scanlld(a);
       scanlld(b);

       sum = cumsum[b] - cumsum[a-1];

       cout << sum << endl;
    }


}


