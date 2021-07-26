#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dp[4][1003][1003];
ll mat[1003][1003];

void solve1(ll n, ll m, ll idx)
{
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++)
        {
            dp[idx][i][j] = max(dp[idx][i- 1][j], dp[idx][i][j - 1]) + mat[i][j];
        }
    }
}

void solve2(ll n, ll m, ll idx)
{
    for(ll i = n; i >= 1; i--)
    {
        for(ll j = 1; j <= m; j++)
        {
            dp[idx][i][j] = max(dp[idx][i + 1][j], dp[idx][i][j - 1]) + mat[i][j];
        }
    }
}

void solve3(ll n, ll m, ll idx)
{
    for(ll i = n; i >= 1; i--)
    {
        for(ll j = m; j >= 1; j--)
        {
            dp[idx][i][j] = max(dp[idx][i + 1][j], dp[idx][i][j + 1]) + mat[i][j];
        }
    }
}

void solve4(ll n, ll m, ll idx)
{
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = m; j >= 1; j--)
        {
            dp[idx][i][j] = max(dp[idx][i - 1][j], dp[idx][i][j + 1]) + mat[i][j];
        }
    }
}

ll solve(ll n, ll m)
{
    ll ret = 0;

    for(ll i = 2; i < n; i++)
    {
        for(ll j = 2; j < m; j++)
        {
            ll scene1 = dp[0][i][j - 1] + dp[1][i + 1][j] + dp[2][i][j + 1] + dp[3][i - 1][j];
            ll scene2 = dp[1][i][j - 1] + dp[2][i + 1][j] + dp[3][i][j + 1] + dp[0][i - 1][j];
            ret = max(ret, max(scene1,scene2));
        }
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    cout << 4 * 1003 * 1003 << endl;
    while(cin >> n >> m)
    {
//        memset(dp,0,sizeof dp);
//        memset(mat,0,sizeof mat);

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                slld(mat[i][j]);
            }
        }

        solve1(n,m,0);
        solve2(n,m,1);
        solve3(n,m,2);
        solve4(n,m,3);

        ans = solve(n,m);

        cout << ans << endl;
    }

}


