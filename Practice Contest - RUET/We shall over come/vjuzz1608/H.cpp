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
    ll testcase;
    ll input;
    ll temp, flag;
    ll maxsum;

    ll value[110][110];
    ll sum[110][110];

    while(scanlld(n) != EOF)
    {
        memset(value,0,sizeof(value));
        memset(sum,0,sizeof(sum));

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                scanlld(input);

                value[i][j] = input;
            }
        }

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                for(k = 1; k <= i; k++)
                {
                    for(l = 1; l <= j; l++)
                    {
                        sum[i][j] += value[k][l];
                    }
                }
            }
        }

        maxsum = -999999;
        for(i = 0; i <= n; i++)
        {
            for(j = 0; j <= n; j++)
            {
                for(k = 0; k <= i; k++)
                {
                    for(l = 0; l <= j; l++)
                    {
                        temp = sum[i][j] + sum[k][l] - sum[i][l] - sum[k][j];
                        if(temp > maxsum)
                        {
                            maxsum = temp;
                        }
                    }
                }
            }
        }

        printf("%lld\n",maxsum);
    }


}


