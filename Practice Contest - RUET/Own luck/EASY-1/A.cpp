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
    ll store;

    vector < ll > values;

    string input;

    cin >> input;

    stringstream val(input);

    while(val >> store)
    {
        values.push_back(store);
    }

    sort(values.begin(),values.end());

    for(i = 0; i < values.size(); i++)
    {
        cout << values[i];

        if(i != values.size() - 1)
        {
            cout << "+";
        }
    }

    cout << endl;


}


