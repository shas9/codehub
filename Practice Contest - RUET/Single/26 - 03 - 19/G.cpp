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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

ll dp[1005][1005];
ll arr[5][1005];
ll pos[5][1005];
ll n, k;

ll solve(ll x, ll last)
{
    if(last > n) return 0;

    if(dp[x][last] != -1) return dp[x][last];

    ll &ret = dp[x][last];

    ret = 0;

    ll pos_[5];

    for(ll i = 1; i <= k; i++)
    {
        pos_[i] = pos[i][x];
    }

    for(ll i = pos_[1] + 1; i <= n; i++)
    {
        ll _x = arr[1][i];

        ll cnt = 0;

        for(ll j = 1; j <= k; j++)
        {
            if(pos[j][_x] > pos_[j])
            {
                cnt++;
            }
        }

        if(cnt == k)
        {
            ret = max(ret,solve(_x,x));
        }
    }

    return ret + 1;

}
int main()
{
    ll i, j, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> n >> k;

    for(i = 1; i <= k; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cin >> arr[i][j];

            pos[i][arr[i][j]] = j;
        }
    }

    memset(dp,-1,sizeof(dp));

    ans = -1;

    for(i = 1; i <= n; i++)
    {
        ans = max(ans, solve(arr[1][i], 0));
    }

    cout << ans << endl;


}



