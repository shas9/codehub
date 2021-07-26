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

ll par[20][300005];
ll a[300005];
ll c[300005];

void update(ll node)
{
    for(ll i = 1; i <= 19; i++)
    {
        if(par[i - 1][node] != -1)
        {
            par[i][node] = par[i - 1][par[i - 1][node]];
        }
    }

    return;
}

pll solve(ll node, ll tot)
{
    ll x = node;

    if(tot == 0 || a[node] == 0) return {0,0};

    for(ll i = 19; i >= 0; i--)
    {
        if(par[i][x] != -1)
        {
            if(a[par[i][x]])
            {
                x = par[i][x];
            }
        }
    }

    ll mn = min(tot, a[x]);
    tot -= mn;
    a[x] -= mn;

//    cout << x << " " << mn << "\n";

    pll ret = solve(node, tot);

    ret.first += mn;
    ret.second += mn * c[x];

    return ret;

}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    while(cin >> n >> a[0] >> c[0])
    {
        memset(par,-1,sizeof par);

        for(ll i = 1; i <= n; i++)
        {
            ll t;
            cin >> t;

            if(t == 1)
            {
                cin >> par[0][i] >> a[i] >> c[i];

                update(i);
            }
            else
            {
                ll v, w;
                cin >> v >> w;

                pll ans = solve(v,w);

                cout << ans.first << " " << ans.second << endl;
            }
        }
    }


}

