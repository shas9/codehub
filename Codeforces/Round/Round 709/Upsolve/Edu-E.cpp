 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < pll > seg;
vector < ll > dp;

bool comp(pll a, pll b)
{
    return a.first + a.second < b.first + b.second;
}

ll intersect(ll idx, ll x, ll y)
{
    ll x1 = seg[idx].first;
    ll y1 = seg[idx].second;

    if(x <= x1 && y1 <= y) return (y1 - x1 + 1);
    if(x1 <= x && y <= y1) return (y - x + 1);

    if(x1 <= x && x <= y1) return (y1 - x + 1);
    if(x <= x1 && x1 <= y) return (y - x1 + 1);

    return 0;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
        seg.resize(m);
        dp.assign(m + 1, 0);

        for(auto &it: seg) cin >> it.first >> it.second;

        sort(seg.begin(), seg.end(), comp);

        ll ans = 0;

        for(ll i = 1; i <= (n - k + 1); i++)
        {
            ll tot = 0;

            for(ll j = m - 1; j >= 0; j--)
            {
                tot += intersect(j,i,i + k - 1);
                dp[j] = max(dp[j], tot);
            }
        }


        for(ll i = 1; i <= (n - k + 1); i++)
        {
            ll tot = 0;

            for(ll j = 0; j < m; j++)
            {
                tot += intersect(j, i, i + k - 1);
                ans = max(ans, tot + dp[j + 1]);

//                cout << tot << " " << dp[j + 1] << " " << i << " " << j << "\n";
            }
        }

        cout << ans << "\n";
    }


}

