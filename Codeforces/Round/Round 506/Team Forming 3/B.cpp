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

#define maxn 205

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll dp[maxn][maxn];
ll arr[maxn][maxn];
ll n;

ll solve(ll i, ll j)
{
    if(dp[i][j] != -1) return dp[i][j];

    if(i >= (2 * n)) return 0;

    ll ans = 0;
    if(i < n)
    {
        ans = max(solve(i + 1, j + 1), solve(i + 1, j));
    }
    else
    {
        ll high = (2 * n) - i;

        if(j == 1)
        {
            ans = solve(i + 1, 1);
        }
        else if(j == high)
        {
            ans = solve(i + 1, j - 1);
        }
        else
        {
            ans = max(solve(i + 1, j - 1), solve(i + 1, j));
        }
    }

    return dp[i][j] = ans + arr[i][j];



}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        memset(dp,-1,sizeof dp);

        slld(n);

        n /= 2;
        n++;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= i; j++)
            {
                slld(arr[i][j]);
            }
        }

        for(i = n - 1, k = n + 1; i >= 1; i--, k++)
        {
            for(j = 1; j <= i; j++)
            {
                slld(arr[k][j]);
            }
        }

        ans = solve(1,1);

        plld(ans);
    }


}


