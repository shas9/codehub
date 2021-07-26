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

#define printcase(indexing) printf("Case %lld:\n", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

using namespace std;

ll words, times;
bool check[150];
ll cnt;
char all[40];

void solve(ll pos)
{
    if(pos == words)
    {
        cnt++;
        for(ll i = 0; i < words; i++)
        {
            cout << all[i];
        }

        cout << endl;

        return;
    }
    for(ll i = 65; i <= 64 + words; i++)
    {
        if(cnt == times)
        {
            return;
        }
        if(check[i] == false)
        {
            check[i] = true;

            all[pos] = i;

            solve(pos + 1);

            check[i] = false;
        }
    }
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(words);
        scanlld(times);

        memset(check,false,sizeof(check));
        memset(all,0,sizeof(all));

        cnt = 0;

        printcase(i);
        solve(0);
    }


}


