struct segTree
{
    ll n;
    vector<ll> tree;

    segTree(ll n): n(n), tree(4*n, 0) {}

    void treeUpdate(ll node, ll l, ll r, ll u, ll val)
    {
        ll mid = (l+r)>>1;

        if(l > u || r < u) return;
        if(l == u && r == u)
        {
            tree[node] = val;
            return;
        }

        treeUpdate(2*node, l, mid, u,  val);
        treeUpdate(2*node+1, mid+1, r, u, val);

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    void update(ll idx, ll val) { treeUpdate(1, 1, n, idx, val); }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        if(l > v || r < u) return 0;
        if(l >= u && r <= v) return tree[node];

        return max(treeQuery(2*node, l, mid, u, v), treeQuery(2*node+1, mid+1, r, u, v));
    }

    ll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }
};
