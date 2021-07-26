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

ll dp[3003][3003][4];
ll val[3003][3003];
ll r, c;

ll solve(ll rr, ll cc, ll took)
{
    ll &ret = dp[rr][cc][took];

    if(ret != -1) return ret;

    if(rr > r || cc > c) return ret = 0;

    if(val[rr][cc] == -1)
    {
		return ret = max(solve(rr + 1, cc, 0), solve(rr, cc + 1, took));

    }

    ret = 0;

    if(took != 3)
    {
        ret = max(ret, solve(rr, cc + 1, took + 1) + val[rr][cc]);
    }

    ret = max(ret, solve(rr, cc + 1, took));


    ret = max(ret, solve(rr + 1, cc, 0) + (took == 3 ? 0 : val[rr][cc]));


//	cout << rr << " " << cc << " " << took << " = " << ret << endl;

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
    while(cin >> r >> c >> n)
    {
        memset(dp,-1,sizeof dp);
        memset(val,-1,sizeof val);

        for(ll i = 1; i <= n; i++)
        {
            ll x, y;

            cin >> x >> y >> val[x][y];
        }

        ans = solve(1,1,0);

        cout << ans << "\n";
    }


}



