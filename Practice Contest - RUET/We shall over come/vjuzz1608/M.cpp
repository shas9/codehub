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
ll path[10005];
ll dp[10005];
ll row;
ll totalrow;

ll solve(ll index, ll pos, ll mark)
{
    cout << index << " " << pos << " " << mark << endl;
    ll sum1 = 0, sum2 = 0, sum3 = 0;
    ll i, j, k;

    if(pos == totalrow)
    {
        return 0;
    }

    if(dp[index] != -1)
    {
        return dp[index];
    }

    if(pos < row)
    {

        sum1 = solve(index + pos, pos + 1, mark + pos + 1);
        sum2 = solve(index + pos + 1, pos + 1, mark + pos + 1);
        dp[index] = max(sum1,sum2);

    }
    else
    {
        if(mark == index)
        {
            sum1 = solve(index + totalrow - pos - 1, pos + 1, mark + totalrow - pos - 1);
        }
        else if(mark - totalrow + pos + 1 == index)
        {
            sum2 = solve(index + totalrow - pos, pos + 1, mark + totalrow - pos - 1);
        }
        else
        {
            sum1 = solve(index + totalrow - pos - 1, pos + 1, mark + totalrow - pos - 1);
            sum2 = solve(index + totalrow - pos, pos + 1, mark + totalrow - pos - 1);
        }
        dp[index] = max(sum1,sum2);
    }

    return dp[index];


}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(row);
        totalrow = row * 2;
        flag = row * row;

        for(j = 1; j <= flag; j++)
        {
            scanlld(input);
            path[j] = input;
        }
        memset(dp,-1,sizeof(dp));

        ll ans = solve(1,1,1);

        printcase(i,ans);
    }


}


