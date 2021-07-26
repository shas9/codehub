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

ll a[400005];
ll b[400005];
ll c[400005];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        for(ll i = 1; i <= n; i++) cin >> a[i];
        for(ll i = 1; i <= n; i++) cin >> b[i];

        vector < bool > vis;

        vis.assign(n + 1, 0);

        for(ll i = 1; i <= n; i++)
        {
            c[a[i]] = b[i];
        }

        ans = 1;

        ll mod = 1e9 + 7;

        for(ll i = 1; i <= n; i++)
        {
            if(vis[i]) continue;

            ans = (ans * 2) % mod;

            ll now = i;

            while(vis[now] == 0)
            {
                vis[now] = 1;
                now = c[now];
            }
        }

        cout << ans << "\n";
    }


}

