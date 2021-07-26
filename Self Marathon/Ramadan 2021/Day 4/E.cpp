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

const ll mod = 998244353;

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

vector < string > grid;
ll dp[300005];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    dp[0] = 0;

    for(ll i = 2; i <= 3e5 + 2; i++)
    {
        ll add = power(power(2,i, mod), mod - 2, mod);

        if(!(i & 1)) dp[i] = (dp[i - 1] + add) % mod;
        else dp[i] = (dp[i - 1] - add + mod + mod) % mod;
    }

    fastio;

    while(cin >> n >> m)
    {
        grid.clear();

        for(ll i = 0; i < n; i++)
        {
            grid.push_back("");
            cin >> grid.back();
        }

        ans = 0;
        ll white = 0;

        for(ll i = 0; i < n; i++)
        {
            ll csum = 0;

            for(ll j = 0; j < m; j++)
            {
                if(grid[i][j] == '*') csum = 0;
                else csum++, white++;

                ans = (ans + dp[csum]) % mod;
            }
        }

        for(ll i = 0; i < m; i++)
        {
            ll csum = 0;

            for(ll j = 0; j < n; j++)
            {
                if(grid[j][i] == '*') csum = 0;
                else csum++;

                ans = (ans + dp[csum]) % mod;
            }
        }

        ans = (ans * power(2,white, mod)) % mod;

        cout << ans << "\n";
    }


}

