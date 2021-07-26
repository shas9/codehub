// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %d\n", x)

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

struct segtree
{

    ll n;
    vector < ll > tree;


    void init(ll _n)
    {
        n = _n;
        tree.assign(4 * n,0);
    }

    void treeupdate(ll node, ll b, ll e, ll i, ll val)
    {
        if(i > e || i < b)
        {
            return;
        }

        if(b == i && e == i)
        {
            tree[node] = val;
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        treeupdate(left, b, mid, i, val);
        treeupdate(right, mid + 1, e, i, val);

        tree[node] = (tree[left] + tree[right]);
    }

    void update(ll i, ll val)
    {
        treeupdate(1,1,n,i,val);
    }

    ll treequery(ll node, ll b, ll e, ll i, ll j)
    {
        if(i > e || j < b)
        {
            return 0;
        }

        if(b >= i && e <= j)
        {
            return tree[node];
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        ll p1 = treequery(left, b, mid, i, j);
        ll p2 = treequery(right, mid + 1, e,i, j);

        return (p1 + p2);
    }

    ll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }

} seg;



/// Template: HLD

/* DFS for Heavy-Light Decomposition
 * head[u] = Head of the chain of node u
 * Operations can be performed in [in[head[u]],in[u]] range.
 * As DFS-time is used, [in[u],out[u]] range can be used
   for performing operations on the subtree of node u.
*/

const ll maxn = 30000;
const ll ln = 16;


vector < ll > g[maxn + 10];
ll parent[ln + 2][maxn + 10];
ll depth[maxn + 10];
ll subtree[maxn + 10];
ll head[maxn + 10];
ll intime[maxn + 10];
ll outtime[maxn + 10];
ll cur_pos;

void dfs(ll node, ll par, ll d)
{
    parent[0][node] = par;
    depth[node] = d;
    subtree[node] = 1;

    for(auto &it: g[node])
    {
        if(it != par)
        {
            dfs(it, node, d + 1);

            subtree[node] += subtree[it];

            if(subtree[it] > subtree[g[node].front()])
            {
                swap(it, g[node].front());
            }
        }
    }

    return;
}

void decompose(ll node, ll par)
{
    if(node == 1) head[node] = 1;
    intime[node] = ++cur_pos;

    for(auto it: g[node])
    {
        if(it != par)
        {
            head[it] = (it == g[node].front()? head[node] : it);
            decompose(it, node);
        }
    }

    outtime[node] = cur_pos;
    return;
}

void init(ll n)
{
    for(ll i = 0; i <= n; i++)
    {
        for(ll j = 0; j < ln; j++)
        {
            parent[j][i] = -1;
        }
    }

    cur_pos = 0;

    dfs(1, -1, 0);
    decompose(1, -1);

    for(ll i = 1; i < ln; i++) // LCA - part
    {
        for(ll j = 1; j <= n; j++)
        {
            if(parent[i - 1][j] != -1)
            {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
            }
        }
    }

    return;
}

ll lca(ll u, ll v)
{
    if(depth[u] < depth[v]) swap(u, v);

    ll diff = depth[u] - depth[v];

    for(ll i = 0; i < ln; i++) if(check(diff,i)) u = parent[i][u];

    if(u == v) return u;

    for(ll i = ln - 1; i >= 0; i--)
    {
        if(parent[i][u] != parent[i][v])
        {
            u = parent[i][u];
            v = parent[i][v];
        }
    }

    return parent[0][u];
}

ll query_chain(ll u, ll v)
{
    ll now = -1;
    ll ret = 0;

    while(now != u)
    {
        now = head[v];

        if(depth[now] < depth[u]) now = u;

        ret += seg.query(intime[now], intime[v]);
        v = parent[0][now];
    }

    return ret;
}

ll query(ll u, ll v)
{
    ll xlca = lca(u,v);

    ll ret = query_chain(xlca, u) + query_chain(xlca, v);

    ret -= query_chain(xlca, xlca);

    return ret;
}


/// Template End

ll arr[maxn + 10];
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll ans;

//    freopen("input.txt", "r", stdin);
//
//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        for(ll i = 1; i <= n; i++) g[i].clear();

        for(ll i = 1; i <= n; i++) slld(arr[i]);

        for(ll i = 1; i < n; i++)
        {
            ll u, v;
            slld(u);
            slld(v);
            u++;
            v++;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        init(n);

        slld(m);

        seg.init(maxn);


        for(ll i = 1; i <= n; i++)
        {
            seg.update(intime[i], arr[i]);
        }

        printf("Case %d:\n", cs);

        for(ll i = 1; i <= m; i++)
        {
            ll t, u, v;
            slld(t);
            slld(u);
            slld(v);

            u++;
            v++;

            if(t == 0)
            {
                ans = query(u,v);
                printf("%d\n", ans);
            }
            else
            {
                v--;
                seg.update(intime[u], v);
            }
        }


    }


}

/*

4
10 20 30 40
1 2
2 3
2 4
3
0 3 4
1 2 100
0 3 4


10
5 3 6 2 7 1 4 8 2 8
1 3
1 8
1 2
2 5
2 4
2 6
3 7
7 9
9 10


*/

