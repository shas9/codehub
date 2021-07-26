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

bool vis[200005];
ll par[200005];
ll sub[200005];
vector < ll > g[200005];

void dfs(ll node, ll p)
{
    par[node] = p;
    sub[node] = 1;

    for(auto it: g[node])
    {
        if(it != p)
        {
            dfs(it,node);

            sub[node] += sub[it];
        }
    }

    return;
}

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

        for(ll i = 0; i <= n; i++)
        {
            g[i].clear();
            vis[i] = 0;
            par[i] = -1;
            sub[i] = 0;
        }

        for(ll i = 1; i < n; i++)
        {
            ll u, v;
            cin >> u >> v;

            g[u].pb(v);
            g[v].pb(u);
        }

        dfs(0,-1);

        ll mex = n * (n - 1) / 2;

        ll ans0 = 0;

        for(auto it: g[0])
        {
            ans0 += (sub[it] * (sub[it] - 1)) / 2;
        }

        bool on = 1;

        mex -= ans0;

        cout << ans0 << " ";

        l = r = 0;
        vis[0] = 1;

        for(ll i =  1; i < n; i++)
        {
            if(on == 0 || vis[i])
            {
                cout << 0 << " ";
                continue;
            }

            ll node = i;

            ll last = node;

            while(vis[node] == 0)
            {
                vis[node] = 1;
                last = node;
                node = par[node];
            }

            if(node == l)
            {
                 l = i;
                 if(node == 0) sub[0] -= sub[last];
            }
            else if(node == r)
            {
                r = i;
                if(node == 0) sub[0] -= sub[last];
            }
            else
            {
                on = 0;
                cout << mex << " ";
                continue;
            }

            ll newmex = sub[l] * sub[r];

//            cout << l << " " << r << "\n";

            cout << mex - newmex << " ";

            mex = newmex;
        }

        if(on == 0) cout << 0 << "\n";
        else cout << mex << "\n";

    }


}

