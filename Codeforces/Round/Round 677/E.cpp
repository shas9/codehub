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

ll rem(ll mask, ll x)
{
    return mask & (~(1 << x));
}


ll dp[(1 << 10)][10][10];

ll solve(ll mask, ll u, ll v)
{
//    cout << mask << " " << u << " " << v << "\n";
    ll &ret = dp[mask][u][v];

    if(ret != -1) return ret;

    if(mask == 0)
    {
        return ret = 1;
    }

    ret = 0;

    for(ll i = 0; i < 10; i++)
    {
        if(check(mask, i)) ret += solve(rem(mask,i), v, i);
    }

    return ret;
}
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    while(cin >> n)
    {
        memset(dp,-1,sizeof dp);

        ans = solve(rem((1 << (n / 2)) - 1, 0), 0, 0);

        ll add = 1;

        for(ll i = n / 2 + 1; i <= n; i++) add *= i;
        for(ll i = 1; i <= n / 2; i++) add /= i;
        add /= 2;

//        cout << ans << " " << add << "\n";

        ans = (ans * add * ans);

        cout << ans << "\n";
    }


}


