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

    ll mat[6][6];

    ll one_i, one_j;

    for(i = 1; i <= 5; i++)
    {
        for(j = 1; j <= 5; j++)
        {
            scanlld(input);;

            if(input == 1)
            {
                one_i = i;
                one_j = j;
            }

            mat[i][j] = input;
        }
    }

    ll ans = 0;

    if(one_i == 3 && one_j == 3)
    {
        ans = 0;
    }
    else if(one_i == 3)
    {
        ans = abs(3 - one_j);
    }
    else if(one_j == 3)
    {
        ans = abs(3 - one_i);
    }
    else
    {
        ans = abs(3 - one_i) + abs(3 - one_j);
    }

    cout << ans << endl;
}


