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

    scanlld(testcase);

    ll one = 0, two = 0, three = 0, four = 0;

    for(i = 1; i <= testcase; i++)
    {
        scanlld(input);

        if(input == 1)
        {
            one++;
        }
        else if(input == 2)
        {
            two++;
        }
        else if(input == 3)
        {
            three++;
        }
        else if(input == 4)
        {
            four++;
        }
    }

    ll total = 0;

    total += four;
    total += three;

    one -= three;

    if(one < 0)
    {
        one = 0;
    }

    if(two % 2 != 0)
    {
        two--;
        one += 2;
    }

    k = one / 4;

    if(k * 4 != one)
    {
        k++;
    }

    total += (two / 2);
    total += k;

    cout << total << endl;


}

