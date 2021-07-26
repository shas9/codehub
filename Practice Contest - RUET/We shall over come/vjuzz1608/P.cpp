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

string a, b;
ll dp[40][40];
ll dp2[40][40][100];
ll ans;
ll temp;

ll lcs(ll i, ll j)
{
    //cout << i << "--" << j << endl;

    if(i >= a.size() || j >= b.size())
    {

        return 0;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if(a[i] == b[j])
    {
        dp[i][j] = (1 + lcs(i+1,j+1));
        return dp[i][j];
    }
    else
    {
        dp[i][j] = max(lcs(i+1, j), lcs(i, j+ 1));
        return dp[i][j];
    }
}

ll solve(ll i, ll j, ll k)
{
    //cout << i << "--" << j << "--" << k << endl;

    ll flag;

    if(i == a.size())
    {
        flag = k + (b.size() - j);
        //cout << "Flag = " << flag << endl;

        if(flag == ans)
        {
            //bug;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(j == b.size())
    {
        flag = k + (a.size() - i);
        //cout << "Flag = " << flag << endl;

        if(flag == ans)
        {
            //bug;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if(dp2[i][j][k] != -1)
    {
        return dp2[i][j][k];
    }

    if(a[i] == b[j])
    {
        dp2[i][j][k] = solve(i + 1, j + 1, k + 1);
    }
    else
    {
        dp2[i][j][k] = solve(i + 1, j, k + 1) + solve(i, j + 1, k + 1);
    }

    //cout << i << " " << j << "==" << dp[i][j] <<  endl;

    return dp2[i][j][k];
}



int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    ll totalsize;
    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        cin >> a >> b;
        totalsize = a.size() + b.size();

        memset(dp,-1,sizeof(dp));

        temp = lcs(0,0);
        ans = totalsize - temp;

        memset(dp2,-1,sizeof(dp2));
        ll comb;

        comb = solve(0,0,0);

        printf("Case %lld: %lld %lld\n", i, ans, comb);


    }


}

