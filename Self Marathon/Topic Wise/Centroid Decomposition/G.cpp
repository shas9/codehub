// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld 1e10
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

const ll mx = 100005;

ll cenpar[mx];
ll sz[mx];
bool done[mx];
ll dist[mx];
ll n, k, ans;

vector < ll > g[mx];

void dfs(ll node, ll par)
{
    sz[node] = 1;

    for(auto it: g[node])
    {
        if(it != par && done[it] == false)
        {
            dfs(it,node);
            sz[node] += sz[it];
        }
    }
}

void calc(ll node, ll par, ll d = 1)
{
    if(d <= k)
    {
        ans += dist[k - d];
    }

    for(auto it: g[node])
    {
        if(it != par && done[it] == false)
            calc(it,node, d + 1);
    }
}

void update(ll node, ll par, ll d = 1)
{
    if(d <= k) dist[d]++;

    for(auto it: g[node])
    {
        if(it != par && done[it] == false)
        {
            update(it,node,d + 1);
        }
    }
}

ll decompose(ll cen)
{
    dfs(cen,-1);

    ll target = sz[cen] / 2;
    ll p = -1;
    bool ok = false;

    while(!ok)
    {
        ok = true;

        for(auto it: g[cen])
        {
            if(it != p && done[it] == false && sz[it] > target)
            {
                ok = false;
                p = cen;
                cen = it;
                break;
            }
        }
    }

    done[cen] = true;

    for(ll i = 0; i <= k; i++) dist[i] = 0;
    dist[0] = 1;

    for(auto it: g[cen])
    {
        if(done[it] == false)
        {
            calc(it,cen);
            update(it,cen);
        }
    }

    for(auto it: g[cen])
    {
        if(done[it] == false)
        {
            cenpar[decompose(it)] = cen;
        }
    }

    return cen;
}

ll par[19][mx];
ll depth[mx];
ll pwr[20];

void dfs0(ll src,ll p,ll level)
{
    depth[src]=level;
    par[0][src]=p;
    for(ll i=0; i<g[src].size(); i++)
    {
        ll adj=g[src][i];
        if(adj!=p)
        {
            dfs0(adj,src,level+1);
        }
    }
}
void preL()
{

    for(ll i=1; i<=17; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            if(par[i-1][j]==-1)continue;
            par[i][j]=par[i-1][par[i-1][j]];                       ///i means 2^i th parent of j th node par[i][j] means 2^i th parent of jth node
        }
    }
}
ll lca(ll u,ll v)
{
    if(depth[u]>depth[v])
    {
        swap(u,v);
    }
    ll diff=depth[v]-depth[u];
    for(ll i=0; i<=17; i++)
    {
        if(check(diff,i)==1)
        {
            v=par[i][v];
        }
    }
    if(u==v)
    {
        return u;
    }
    for(ll i=17; i>=0; i--)
    {
        if(par[i][u]!=par[i][v])
        {
            u=par[i][u];
            v=par[i][v];
        }
    }
    return par[0][u];
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll m;

    slld(n);
    slld(m);

    for(ll i = 1; i < n; i++)
    {
        ll u, v;

        slld(u);
        slld(v);

        g[u].pb(v);
        g[v].pb(u);
    }

    ll root = decompose(1);

    for(ll i = 1; i <= n; i++) dist[i] = mxlld;

    dfs0(1,-1,0);
    preL();

    ll v = 1;

    while(1)
    {
        ll dd = depth[1] + depth[v] - 2 * depth[lca(1,v)];

//        cout << 1 << " " << v << " " << lca(1,v) << " " << dd << endl;

        dist[v] = min(dist[v], dd);

        if(v == root) break;

        v = cenpar[v];
    }

    for(ll i = 1; i <= m; i++)
    {
        ll t;
        slld(t);

        ll u, v;
        slld(u);
        v = u;

        if(t == 1)
        {
            while(1)
            {
                ll dd = depth[u] + depth[v] - 2 * depth[lca(u,v)];


//				cout << u << " " << v << " " << lca(u,v) << " " << dd << endl;

                dist[v] = min(dist[v], dd);

                if(v == root) break;

                v = cenpar[v];
            }
        }
        else
        {
            ans = mxlld;

            while(1)
            {
                ll dd = depth[u] + depth[v] - 2 * depth[lca(u,v)];

//				cout << u << " " << v << " " << lca(u,v) << " " << dd << endl;

                ans = min(ans, dd + dist[v]);

                if(v == root) break;

                v = cenpar[v];
            }

            printf("%lld\n", ans);
        }

//        for(ll j = 1; j <= n; j++) cout << j << ": " << dist[j] << endl;
    }



}



