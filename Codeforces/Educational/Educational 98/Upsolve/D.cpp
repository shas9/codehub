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

ll dp[5005];
ll tag[5005];
ll score[5005];
bool vis[5005];

void test()
{
    ll n, ans;
    cin >> n;

    for(ll i = 1; i <= n; i++) cin >> tag[i];
    for(ll i = 1; i <= n; i++) cin >> score[i];
    for(ll i = 1; i <= n; i++) dp[i] = 0;
    for(ll i = 1; i <= n; i++) vis[i] = 0;

    ans = 0;

    for(ll i = 1; i <= n; i++)
    {
        for(ll j = i + 2; j <= n; j++)
        {
            if(tag[i] != tag[j])
            {
                vis[j] = 1;
                dp[j] = max(dp[j], dp[i] + abs(score[i] - score[j]));
            }
        }

        if(vis[i])
        {
            for(ll j = i + 1; j <= n; j++)
            {
                if(tag[i] != tag[j])
                {
                    vis[j] = 1;
                    dp[j] = max(dp[j], dp[i] + abs(score[i] - score[j]));
                }
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {

    }


}
