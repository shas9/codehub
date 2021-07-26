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

vector < ll > g[100005];

const ll K = 19;
const ll N = 100005;

ll anc[N][K];
ll depth[N];

void setup(ll u, ll par) { // setup(x,0); where x is the root
    depth[u] = depth[par]+1;

    memset(anc[u],0,sizeof anc[u]);

    anc[u][0] = par;

    for (ll k=1; k<K; k++) anc[u][k] = anc[anc[u][k-1]][k-1];

    for (ll v: g[u]) {
        if (v == par)   continue;
        setup(v, u);
    }
}

ll lca(ll u, ll v) {

    if (depth[u] > depth[v])    swap(u, v);

    for (ll k=K-1; k>=0; k--)
        if (depth[u] + (1<<k) <= depth[v])  v = anc[v][k];

    if (u == v) return u;

    for (ll k=K-1; k>=0; k--)
        if (anc[u][k] != anc[v][k])
            u = anc[u][k], v = anc[v][k];

    return anc[u][0];
}

ll getanc(ll u, ll d) {

    for (ll k=0; k<K; k++)
        if (d & (1<<k))
            u = anc[u][k];

    return u;
}

ll dist(ll u, ll v) {

    ll x = lca(u, v);

    return depth[u] + depth[v] - 2*depth[x];
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        for(ll i = 1; i <= n; i++) g[i].clear();
        memset(anc,0, sizeof anc);
        memset(depth, 0, sizeof depth);

        for(ll i = 1; i < n; i++)
        {
            ll u, v;
            cin >> u >> v;

            g[u].pb(v);
            g[v].pb(u);
        }

        setup(1,0);

        for(ll i = 1; i <= m; i++)
        {
            ll u, v;
            cin >> u >> v;

            ll d = dist(u,v);

            if(d & 1) cout << "Road\n";
            else cout << "Town\n";
        }

    }


}


