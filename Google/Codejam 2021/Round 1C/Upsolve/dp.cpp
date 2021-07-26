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

ll dp[2003][2003];
ll l, r, n, h;
ll arr[2003];

ll solve(ll pos, ll sum)
{
    if(pos > n) return l <= sum && sum <= r;

    ll &ret = dp[pos][sum];

    if(ret != -1) return ret;

    ret = 0;

    ret = solve(pos + 1, (sum + arr[pos]) % h);
    ret = max(ret, solve(pos + 1, (sum + arr[pos + 1]) % h));

    if(l <= sum && sum <= r && pos > 1) ret++;

    return ret;
}

int main()
{
    ll i, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> h >> l >> r)
    {
        memset(dp, -1, sizeof dp);

        for(ll i = 1; i <= n; i++) cin >> arr[i];

        arr[n + 1] = 0;

        ans = solve(1,0);

        cout << ans << "\n";
    }

}

