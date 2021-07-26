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

#define mod 998244353


using namespace std;

ll n, ncr[1100][1100];
ll dp[1100];
ll arr[1100];

ll nCr(ll a, ll b)
{
    if(ncr[a][b] != -1) return ncr[a][b];

    if(b == 0|| a == b)
    {
        return ncr[a][b] = 1;
    }

    return ncr[a][b] = (nCr(a-1,b-1) + nCr(a-1,b)) % mod;
}

ll solve(ll pos)
{
    if(dp[pos] != -1) return dp[pos];

    if(pos > n) return 1;

    dp[pos] = 0;
    dp[pos] = solve(pos + 1);

    if(arr[pos] == 0 || arr[pos] > n) return dp[pos];

    for(ll i = pos + arr[pos]; i <= n; i++)
    {
        ll left = arr[pos] - 1;
        ll leftt = i - pos - 1;;

        dp[pos] += nCr(leftt,left) * solve(i + 1);
        dp[pos] %= mod;
    }

    return dp[pos];


}

int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    memset(ncr,-1,sizeof ncr);
    memset(dp,-1,sizeof dp);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);

        arr[i] = max(0LL, arr[i]);
    }

    ans = solve(1);

    ans--;

    ans %= mod;

    cout << ans << endl;




}
