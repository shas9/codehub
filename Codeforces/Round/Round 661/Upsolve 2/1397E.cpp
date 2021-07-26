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

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    while(cin >> n)
    {
        ll r1, r2, r3, d;

        cin >> r1 >> r2 >> r3 >> d;

        memset(dp,0,sizeof dp);

        for(ll i = 1; i <= n; i++) cin >> arr[i];

        dp[0][0] = 0;
        dp[0][1] = 1e17;

        for(ll i = 1; i <= n; i++)
        {
            ll minshot = min((arr[i] + 2) * r1, r2 + r1);

            ll add = d;
            if(i < n) add += d;

            dp[i][0] = min(dp[i - 1][0] + r1 * arr[i] + r3, dp[i - 1][1] + minshot + 2 * d);
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + r1 * arr[i] + r3 + add);
            dp[i][1] = dp[i - 1][0] + minshot;
        }

        dp[n][1] += 2 * d;

        cout << min(dp[n][0], dp[n][1]) + (n - 1) * d << "\n";
    }


}

