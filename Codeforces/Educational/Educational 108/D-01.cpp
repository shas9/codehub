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

ll a[5005];
ll b[5005];

ll lft[5005];
ll rgt[5005];

ll dp[5005][5005];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
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

        memset(dp,0, sizeof dp);

        for(ll i = n; i >= 1; i--)
        {
            for(ll j = i; j <= n; j++)
            {
                if(i == j)
                {
                    dp[i][j] = a[i] * b[i];
                }
                else if(j - i == 1)
                {
                    dp[i][j] = a[i] * b[j] + b[i] * a[j];
                }
                else
                {
                    dp[i][j] = a[i] * b[j] + b[i] * a[j] + dp[i + 1][j - 1];
                }

                ans = max(ans, lft[i - 1] + rgt[j + 1] + dp[i][j]);
            }
        }

//        for(ll i = 1; i <= n; i++)
//        {
//            for(ll j = i; j <= n; j++)
//            {
//                ll sum = 0;
//
//                for(ll k = i, l = j; k <= j; k++, l--)
//                {
//                    sum += a[k] * b[l];
//                }
//
//                if(sum != dp[i][j])
//                {
//                    cout << i << " " << j << "\n";
//                    assert(0);
//                }
//            }
//        }

        cout << ans << "\n";

    }


}

