#include <bits/stdc++.h>

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
    ll bet;
    ll sum;
    ll maxsum;

    vector < ll > seq;

    while(1)
    {
        seq.clear();
        sum = 0;
        maxsum = -9999;

        scanlld(bet);

        if(bet == 0)
        {
            return 0;
        }

        for(i = 1; i <= bet; i++)
        {
            scanlld(input);

            seq.push_back(input);
        }

        for(i = 0; i < bet; i++)
        {
            sum += seq[i];

            if(sum > maxsum)
            {
                maxsum = sum;
            }

            if(sum < 0)
            {
                sum = 0;
            }
        }

        if(maxsum <= 0)
        {
            printf("Losing streak.\n");
        }
        else
        {
            printf("The maximum winning streak is %lld.\n", maxsum);
        }
    }


}


