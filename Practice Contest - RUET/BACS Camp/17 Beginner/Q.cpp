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

ll dp[1005][35];
vector < ll > price;
vector < ll > weight;
ll max_weight;

ll solve(ll pos, ll w)
{
    if(pos == price.size())
    {
        return 0;
    }

    if(dp[pos][w] != -1)
    {
        return dp[pos][w];
    }

    ll profit1 = 0;
    ll profit2 = 0;

    if(max_weight >= w + weight[pos])
    {
        profit1 = price[pos] + solve(pos + 1, w + weight[pos]);
    }



    profit2 = solve(pos + 1, w);

    dp[pos][w] = max(profit1, profit2);

    return dp[pos][w];
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;
    ll sum;

    ll total_people, total_product;

    scanlld(testcase);

    for(o = 1; o <= testcase; o++)
    {
        price.clear();
        weight.clear();

        sum = 0;

        scanlld(total_product);

        for(i = 1; i <= total_product; i++)
        {
            scanlld(input);

            price.push_back(input);

            scanlld(input);

            weight.push_back(input);
        }

        scanlld(total_people);

        for(i = 1; i <= total_people; i++)
        {
            scanlld(input);

            memset(dp,-1,sizeof(dp));
            max_weight = input;

            sum += solve(0,0);
        }

        cout << sum << endl;
    }
}

