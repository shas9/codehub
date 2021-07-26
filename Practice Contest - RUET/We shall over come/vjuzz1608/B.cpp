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
    ll input;

    vector < ll > queens;

    ll countseq, longest_pos, longest_start, longest_end;

    ll tag, flag;

    while(scanlld(input) != EOF)
    {
        queens.clear();
        longest_pos = 0;
        longest_start = -1;
        countseq = 0;
        longest_end = -1;
        tag = 0;
        flag = 0;

        queens.pb(input);

        for(i = 1; i <= 7; i++)
        {
            scanlld(input);
            queens.pb(input);
        }
    }


}


