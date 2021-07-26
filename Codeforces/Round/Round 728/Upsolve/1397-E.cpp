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

ll dp[1000006][2];
ll arr[1000006];
ll n;
ll r1, r2, r3, d;

ll solve(ll pos, bool x)
{
    ll &ret = dp[pos][x];

    if(ret != -1) return ret;

    ret = 0;

    if(pos == n)
    {
        ret = min(r1 * arr[n] + r3, r2 + r1);
        return ret;
    }

    ll add = 0;

    if(x) add = d;
}

int main()
{
    ll i, j, k, l, m, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> r1 >> r2 >> r3 >> d)
    {
        memset(dp,-1,sizeof dp);

        for(ll i = 1; i <= n; i++) cin >> arr[i];

        ans = solve(1,0);

        cout << ans << "\n";
    }


}
