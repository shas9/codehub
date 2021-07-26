// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
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

ll arr[5003];
ll dp[5003][5003];
ll n;

ll solve(ll pos, ll komaise)
{
    ll &ret = dp[pos][komaise];

    if(ret != -1) return ret;

    if(pos > n) return ret = 0;

    ret = solve(pos + 1, 0) + (arr[pos] > 0);

    if(komaise >= arr[pos])
    {
        ret = min(ret, solve(pos + 1, arr[pos]));
    }
    else
    {
		ret = min(ret, solve(pos + 1, komaise) + 1);
		if(arr[pos] <= 5000) ret = min(ret, solve(pos + 1, arr[pos]) + arr[pos] - komaise);
    }

    return ret;

}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        memset(dp,-1,sizeof dp);

        for(ll i = 1; i <= n; i++) cin >> arr[i];

        ans = solve(1,0);

        cout << ans << "\n";
    }


}




