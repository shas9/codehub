#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000007


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll dp[200][2];

    ll d;

    cin >> n >> k >> d;

    memset(dp,0,sizeof dp);

    dp[0][0] = 1;

    for(i = 0; i <= n; i++)
    {
        for(j = 1; j <= k; j++)
        {
            if(j > i) break;

            if(j < d)
            {
                dp[i][0] += dp[i-j][0];
            }
            else
            {
                dp[i][1] += dp[i-j][0];
            }

            dp[i][1] += dp[i-j][1];

            dp[i][0] %= mod;
            dp[i][1] %= mod;
        }
    }

    cout << dp[n][1] << endl;


}


