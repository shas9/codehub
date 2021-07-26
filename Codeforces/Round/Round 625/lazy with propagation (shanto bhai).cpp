
ll tree[mx * 4];
ll lazy[mx * 4];

void propagate(ll node, ll i, ll j)
{
    ll mid = (i + j) / 2;
    ll lft = node * 2;
    ll rgt = lft + 1;

    lazy[lft] += lazy[node];
    lazy[rgt] += lazy[node];

    ll lft_l = i;
    ll lft_r = mid;

    ll rgt_l = mid + 1;
    ll rgt_r = j;

    tree[lft] += (lft_r - lft_l + 1) * lazy[node];
    tree[rgt] += (rgt_r - rgt_l + 1) * lazy[node];

    lazy[node] = 0;
}

void update(ll node, ll L, ll R, ll l, ll r, ll val)
{
    if(r < L || R < l) return;

    if(l <= L && R <= r)
    {
        lazy[node] += val;
        tree[node] += (R - L + 1) * val;
    }

    propagate(node,L,R);

    ll mid = (L + R) / 2;

    update(node * 2, L, mid, l, r, val);
    update((node * 2) + 1, mid +1, R, l, r, val);

    tree[node] = tree[node * 2] + tree[(node * 2) + 1];
}

ll query(ll node, ll L, ll R,  ll l, ll r)
{
    if(r < L || R < l) return 0;

    if(l <= L && R <= r)
    {
        return tree[node];
    }

    ll mid = (l + r) / 2;
    ll x = query(node * 2, L, mid, l, r);
    ll y = query((node * 2) + 1, mid + 1, R, l, r);

    return x + y;
}
