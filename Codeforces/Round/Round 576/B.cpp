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


struct segTree
{
    ll n;
    vector<ll> tree, lazy;

    segTree(ll n): n(n), tree(4*n, 0), lazy(4*n, 0) {}

    void propagate(ll node, ll l, ll r)
    {
        tree[node] = max(tree[node], lazy[node]);
        if(l != r)
        {
            lazy[2 * node] = max(lazy[2 * node], lazy[node]);
            lazy[2 * node + 1] = max(lazy[2 * node + 1], lazy[node]);
        }

        lazy[node] = 0;
    }

    void treeUpdate(ll node, ll l, ll r, ll u, ll v, ll val)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(tree[node] >= val) return;

        if(l > v || r < u) return;
        if(l >= u && r <= v)
        {
            lazy[node] = val;
            propagate(node, l, r);

            return;
        }

        treeUpdate(2*node, l, mid, u, v, val);
        treeUpdate(2*node+1, mid+1, r, u, v, val);

        tree[node] = min(tree[2*node], tree[2*node+1]);
    }

    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }

     void treeUpdate2(ll node, ll l, ll r, ll u, ll v, ll val)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return;

        if(l == r)
        {
            tree[node] = val;
            lazy[node] = 0;

            return;
        }

        treeUpdate2(2*node, l, mid, u, v, val);
        treeUpdate2(2*node+1, mid+1, r, u, v, val);

        tree[node] = min(tree[2*node], tree[2*node+1]);
    }

    void update2(ll l, ll r, ll val) { treeUpdate2(1, 1, n, l, r, val); }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return 1e10;
        if(l >= u && r <= v) return tree[node];

        return min(treeQuery(2*node, l, mid, u, v), treeQuery(2*node+1, mid+1, r, u, v));
    }

    ll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }
};


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    while(cin >> n)
    {
        segTree seg(n);

        for(ll i = 1; i <= n; i++)
        {
            cin >> in;
            seg.update2(i,i,in);
        }

        cin >> m;

        for(ll i = 1; i <= m; i++)
        {
            ll type;
            cin >> type;

            if(type == 2)
            {
                ll x;
                cin >> x;

                seg.update(1,n,x);
            }
            else
            {
                ll p, x;
                cin >> p >> x;

                seg.update2(p,p,x);
            }
        }

        for(ll i = 1; i <= n; i++) cout << seg.query(i,i) << " ";

        cout << "\n";
    }


}


