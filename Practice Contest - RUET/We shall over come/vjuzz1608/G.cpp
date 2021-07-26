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

ll sum[25][25][25], value[25][25][25];



void solve(ll a, ll b, ll c)
{
    ll i, j, k, l, m, n, tag;
    ll maxsum = value[1][1][1];

        for(j = 1; j <= a; j++)
        {
            for(k = 1; k <= b; k++)
            {
                for(l = 1; l <= c; l++)
                {
                    maxsum = max(maxsum,value[j][k][l]);
                }
            }
        }

    for(i = 1; i <= a; i++)
    {
        for(j = i; j <= a; j++)
        {
            for(k = 1; k <= b; k++)
            {
                ll temp[25] = {}, flag;
                for(l = k; l <= b; l++)
                {
                    flag = 0;
                    for(m = 1; m <= c; m++)
                    {
                        printf("Here, I = %lld, J = %lld, k = %lld, L = %lld, m = %lld\n", i, j, k, l, m);

                        temp[m] += sum[j][l][m];
                        cout << temp[m] << endl;
                        temp[m] -= sum[i-1][l][m];
                        cout << temp[m] << endl;

                        flag += temp[m];

                        cout << "flag: " << flag << endl;

                        maxsum = max(maxsum,flag);

                        if(flag < 0)
                        {
                            flag  = 0;
                        }
                    }
                }
            }
        }
    }

    cout << maxsum << endl;
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    ll a, b, c;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(a);
        scanlld(b);
        scanlld(c);

        memset(sum,0,sizeof(sum));

        for(j = 1; j <= a; j++)
        {
            for(k = 1; k <= b; k++)
            {
                for(l = 1; l <= c; l++)
                {
                    scanlld(input);

                    value[j][k][l] = input;

                    sum[j][k][l] = value[j][k][l];

                    sum[j][k][l] += sum[j - 1][k][l];
                }
            }
        }


        solve(a,b,c);

        if(i != testcase)
        {
            cout << endl;
        }


    }
}

/*
1
2 3 3
21 -39 4 -39 4 -44 1 -32 -25 -35 2 17 6 10 2 -12 -22 35
*/


