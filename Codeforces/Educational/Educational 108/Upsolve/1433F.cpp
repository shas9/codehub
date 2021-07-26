// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

#define mxlld LLONG_MAX
#define mnlld -1e9

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dp[71][71][36][71];
ll mat[71][71];
ll n, m, k;

ll solve(ll r, ll c, ll t, ll s)
{
    if(r > n)
    {
        if(s == 0)
        {
            return 0;
        }

        return mnlld;
    }

    ll &ret = dp[r][c][t][s];

    if(ret != -1) return ret;

    ret = mnlld;

    if(t < (m / 2))
    {
        if(c < m)
        {
            ret = max(ret, solve(r, c + 1, t, s));
            ret = max(ret, solve(r, c + 1, t + 1, (s + mat[r][c]) % k) + mat[r][c]);
        }

        ret = max(ret, solve(r + 1, 1, 0, (s + mat[r][c]) % k) + mat[r][c]);
    }

    ret = max(ret, solve(r + 1, 1, 0, s));

    return ret;
}
int main()
{
    ll i, j, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    while(cin >> n >> m >> k)
    {
        for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) cin >> mat[i][j];

        memset(dp,-1,sizeof dp);
        ans = solve(1,1,0,0);

        cout << ans << "\n";
    }


}
