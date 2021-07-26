 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

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
ll arr[2003];
ll n;

ll solve(ll lft, ll rgt)
{
    ll &ret = dp[lft][rgt];

    if(ret != -1) return ret;

    ret = mxlld;

    if(lft > 1) ret = min(ret, solve(lft - 1, rgt));
    if(rgt < n) ret = min(ret, solve(lft, rgt + 1));

    if(ret == mxlld) ret = 0;

    ret += arr[rgt] - arr[lft];

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
        memset(dp, -1, sizeof dp);

        for(ll i = 1; i <= n; i++) cin >> arr[i];

        sort(arr + 1, arr + 1 + n);

        ans = mxlld;

        for(ll i = 1; i <= n; i++)
        {
//            cout << i << " : " << solve(i,i) << "\n";
            ans = min(ans, solve(i,i));
        }

        cout << ans << "\n";
    }


}

