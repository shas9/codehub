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
    ll minim = 99999999;
    ll maxim = -99999999;

    scanlld(testcase);

    vector < ll > store;
    store.clear();

    for(i = 1; i <= testcase; i++)
    {
        scanlld(input);

        store.pb(input);

        minim = min(minim,input);
        maxim = max(maxim,input);
    }

    ll maxpos;
    ll minpos;

    for(i = 0; i < testcase; i++)
    {
        if(store[i] == maxim)
        {
            maxpos = i;
        }
        if(store[i] == minim)
        {
            minpos = i;
        }
    }


    ll checkmin, checkmax;

    if((maxpos == 0 && minpos == testcase - 1) ||(maxpos == testcase - 1 && minpos == 0))
    {
        cout << testcase - 1 << endl;
    }
    else
    {
        if(maxpos < minpos)
        {
            checkmax = testcase - maxpos - 1;
            checkmin = minpos;

            //cout << testcase << " " << maxpos << " " << minpos << " " << checkmax << " " << checkmin << endl;
        }
        else
        {
            checkmax = testcase - minpos - 1;
            checkmin = maxpos;

            //cout << testcase << " " << maxpos << " " << minpos << " " << checkmax << " " << checkmin << endl;
        }

        cout << max(checkmax,checkmin) << endl;
    }






}


