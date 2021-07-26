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

vector < string > store;
ll value[30][30];
ll sum[30][30];

void generatetoint(ll size_arr)
{
    for(ll i = 0; i < size_arr; i++)
    {
        for(ll j = 0; j < size_arr; j++)
        {
            if(store[i][j] == 48)
            {
                value[i + 1][j + 1] = -1000;
            }
            else
            {
                value[i + 1][j + 1] = 1;
            }
        }
    }
}
ll solve(ll n)
{
   generatetoint(n);

   ll i, j, maxsum = -99;
   ll temp, k, l;

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

        return maxsum;


}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll flag, tag;
    string input;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        memset(sum,0,sizeof(sum));
        cin >> input;
        store.clear();

        flag = input.size();

        store.push_back(input);

        for(j = 1; j < flag; j++)
        {
            cin >> input;

            store.push_back(input);
        }

        ll ans = solve(flag);

        printlld(ans);

        if(i < testcase)
        {
            cout << endl;
        }
    }


}


