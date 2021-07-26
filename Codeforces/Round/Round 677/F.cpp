// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dp[71][71][36];
ll mat[71][71];
ll n, m, k;

ll solve(ll row, ll col, ll pick)
{
    if(row > n) return 0;

    ll &ret = dp[row][col][pick];

    if(ret != -1) return ret;


}
int main()
{
    ll i, j, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
        for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) cin >> mat[i][j];

        memset(dp, -1, sizeof dp);

        ans = solve(1,1,0);
    }


}


