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
    ll cnt = 0;

    vector < ll > coins;
    ll sum = 0;
    coins.clear();

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(input);
        sum += input;

        coins.push_back(input);
    }

    ll half = (sum / 2) + 1;

    sort(coins.begin(),coins.end());

    for(i = coins.size() - 1; i >= 0; i--)
    {
        half -= coins[i];
        cnt++;

        if(half <= 0)
        {
            break;
        }
    }

    cout << cnt << endl;

}

