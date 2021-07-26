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

ll lft[5005];
ll rgt[5005];

ll a[5005];
ll b[5005];

ll dp[5005][5005][2];
ll n;

ll solve(ll pos, ll lim, bool on)
{
    if(lim > n) return 0;
    if(pos > n) return 0;

    ll &ret = dp[pos][lim][on];

    if(ret != -1) return ret;

    ret = 0;

    if(on == 1) ret = max(ret, solve(pos, lim + 1, on));

    if(lim == 0)
    {
        ret = max(ret, solve(pos + 1, lim, on) + a[pos] * b[pos]);
        ret = max(ret, solve(pos, pos + 1, 1));
    }
    else if(lim > pos)
    {
        if(on)
        {
            ret = max(ret, solve(pos + 1, lim - 1, 0) + a[pos] * b[lim] + b[pos] * a[lim] + rgt[lim + 1]);
        }
        else
        {
            ret = max(ret, solve(pos + 1, lim - 1, 0) + a[pos] * b[lim] + b[pos] * a[lim]);
        }
    }
    else if(lim == pos)
    {
        ret = max(ret, solve(pos + 1, lim - 1, 0) + a[pos] * b[lim]);
    }

//    cout << pos << " " << lim << " " << ret << "\n";

    return ret;
}

int main()
{
    ll i, j, k, l, m, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        ans = 0;

        for(ll i = 1; i <= n; i++) cin >> a[i];
        for(ll i = 1; i <= n; i++) cin >> b[i];

        for(ll i = 1; i <= n; i++)
        {
            lft[i] = lft[i - 1] + (a[i] * b[i]);
        }

        rgt[n + 1] = 0;

        for(ll i = n; i >= 1; i--)
        {
            rgt[i] = rgt[i + 1] + (a[i] * b[i]);
        }

        ans = lft[n];

        for(ll i = 1; i <= n; i++)
        {

        }
        memset(dp,-1,sizeof dp);

        ans = solve(1,0,0);

        cout << ans << "\n";
    }


}

