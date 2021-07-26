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

ll fact(ll num)
{
    ll i, j, k;
    ll f;

    f = 1;

    for(i = 1; i <= num; i++)
    {
        f *= i;
    }

    return f;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;

    scanlld(testcase);

    ll ini, sum, x, y, ini_1, ini_2;

    for(i = 1; i <= testcase; i++)
    {
        scanlld(n);
        scanlld(k);

        if(k == 1)
        {
            printf("Case %lld: %lld\n", i, n*n);
        }
        else if(k == n)
        {
            printf("Case %lld: %lld\n", i, fact(k));
        }
        else if(k > n)
        {
            printf("Case %lld: 0\n", i);
        }
        else if(k == 0)
        {
            printf("Case %lld: 1\n", i);
        }
        else
        {
            sum = 0;
            x = n - k + 1;
            y = x * x;

            while(y != 0)
            {
                sum += y;
                y -= x;
            }

            ini_1 = pow(n,k-1);

            //cout << sum << endl;

            ini = ini_1 * sum;

            printf("Case %lld: %lld\n", i, ini);
        }
    }


}

