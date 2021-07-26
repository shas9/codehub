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

vector < ll > pdv[100005];
vector < ll > g[100005];

const ll maxn  = 100002;
bool vis[maxn+10];

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 2; i <= maxn; i += 2)
    {
        vis[i] = 1;
        pdv[i].push_back(2);
    }

    for(ll i = 3; i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i; j <= maxn; j += i)
        {
            vis[j] = 1;
            pdv[j].push_back(i);
        }
    }


    return;
}

ll dp[100005][20];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    sieve();
    fastio;
    while(cin >> n >> m)
    {
        for(ll i = 1; i <= 100000; i++) g[i].clear();
        for(ll i = 1; i <= n; i++) for(ll j = 0; j <= 17; j++) dp[i][j] = mxlld;

        for(ll i = 1; i <= n; i++)
        {
            cin >> in;

            for(auto it: pdv[in])
            {
                g[it].push_back(i);

//                cout << i << " = " << it << "\n";
            }
        }

        for(ll i = 1; i <= 100000; i++)
        {
            for(ll j = 0; j + 1 < g[i].size(); j++)
            {
                dp[g[i][j]][0] = min(dp[g[i][j]][0], g[i][j + 1]);
            }
        }

//        for(ll i = 1; i <= 10; i++) cout << i << " " << dp[i][0] << "\n";

//        bug(0);

        ll last = mxlld;

        for(ll i = n; i >= 1; i--)
        {
            last = min(last, dp[i][0]);
            dp[i][0] = last;
        }

        for(ll i = 1; i <= 17; i++)
        {
            for(ll j = 1; j <= n; j++)
            {
                if(dp[j][i - 1] == mxlld) continue;
                dp[j][i] = dp[dp[j][i - 1]][i - 1];

//                if(dp[i][j] != -1) cout << j << " " << i << " " << dp[i][j] << "\n";
            }
        }

//        bug(1);

        for(ll i = 1; i <= m; i++)
        {
            cin >> l >> r;

            ans = 1;

            for(ll i = 17; i >= 0; i--)
            {
                if(dp[l][i] <= r)
                {
                    ans += (1LL << i);
                    l = dp[l][i];
                }
            }

            cout << ans << "\n";
        }


    }


}

