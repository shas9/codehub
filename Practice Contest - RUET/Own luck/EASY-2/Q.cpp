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
    ll a, b, c, vol;

    string names;

    vector < ll > volume;
    map < ll, string > person;

    scanlld(testcase);


    ll precase;

    for(i = 1; i <= testcase; i++)
    {
        scanlld(precase);
        volume.clear();
        person.clear();

        for(j = 1; j <= precase; j++)
        {
            cin >> names;
            scanlld(a);
            scanlld(b);
            scanlld(c);

            vol = a * b * c;

            person[vol] = names;
            volume.push_back(vol);
        }

        sort(volume.begin(),volume.end());

        if(volume[0] == volume[volume.size() - 1])
        {
            printf("Case %lld: no thief\n", i);
        }
        else
        {
            cout << "Case " << i << ": " << person[volume[volume.size()-1]] << " took chocolate from " << person[volume[0]] << endl;
        }
    }


}


