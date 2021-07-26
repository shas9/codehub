// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x
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

struct segTree1
{
    ll n;
    vector<ll> tree, lazy;
    vector<bool>mark;

    segTree1(ll n): n(n), tree(4*n, 0), lazy(4*n, 0), mark(4*n,0) {}

    ll add(ll l, ll r)
    {
        ll ret = (r * (r + 1)) / 2;
        ret -= (l * (l - 1)) / 2;

        return ret;
    }

    void propagate(ll node, ll l, ll r)
    {
        if(mark[node]) tree[node] = 0;

        tree[node] += lazy[node] * add(l,r);

        if(l != r)
        {
            if(mark[node])
            {
                lazy[2*node] = lazy[2*node+1] = 0;
                mark[2*node] = mark[2*node+1] = 1;
            }

            lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];
        }

        mark[node] = 0;
        lazy[node] = 0;
    }

    void treeUpdate(ll node, ll l, ll r, ll u, ll v, ll val)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return;
        if(l >= u && r <= v)
        {
            lazy[node] += val;

            propagate(node, l, r);

            return;
        }

        treeUpdate(2*node, l, mid, u, v, val);
        treeUpdate(2*node+1, mid+1, r, u, v, val);

        tree[node] = (tree[2*node] + tree[2*node+1]);

//        cout << " +++ " << node << " " << tree[node] << "\n";
    }

    void update(ll l, ll r, ll val)
    {
        treeUpdate(1, 1, n, l, r, val);
    }

    void treeclear(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return;
        if(l >= u && r <= v)
        {
            mark[node] = 1;
            propagate(node, l, r);

            return;
        }

        treeclear(2*node, l, mid, u, v);
        treeclear(2*node+1, mid+1, r, u, v);

        tree[node] = (tree[2*node] + tree[2*node+1]);
    }

    void clear(ll l, ll r)
    {
        treeclear(1, 1, n, l, r);
    }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
//        cout << "----  " << node << " " << tree[node] << "\n";
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return 0;
        if(l >= u && r <= v)
        {
//            cout << node << " " << tree[node] << "\n";
            return tree[node];
        }

        return (treeQuery(2*node, l, mid, u, v) + treeQuery(2*node+1, mid+1, r, u, v));
    }

    ll query(ll l, ll r)
    {
        return treeQuery(1, 1, n, l, r);
    }
};

struct segTree2
{
    ll n;
    vector<ll> tree, lazy;
    vector<bool>mark;

    segTree2(ll n): n(n), tree(4*n, 0), lazy(4*n, 0), mark(4*n,0) {}

    void propagate(ll node, ll l, ll r)
    {
        if(mark[node]) tree[node] = 0;

        tree[node] += lazy[node] * (r - l + 1);

        if(l != r)
        {
            if(mark[node])
            {
                lazy[2*node] = lazy[2*node+1] = 0;
                mark[2*node] = mark[2*node+1] = 1;
            }

            lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];
        }

        mark[node] = 0;
        lazy[node] = 0;
    }

    void treeUpdate(ll node, ll l, ll r, ll u, ll v, ll val)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return;
        if(l >= u && r <= v)
        {
            lazy[node] += val;

            propagate(node, l, r);

            return;
        }

        treeUpdate(2*node, l, mid, u, v, val);
        treeUpdate(2*node+1, mid+1, r, u, v, val);

        tree[node] = (tree[2*node] + tree[2*node+1]);

//        cout << " +++ " << node << " " << tree[node] << "\n";
    }

    void update(ll l, ll r, ll val)
    {
        treeUpdate(1, 1, n, l, r, val);
    }

    void treeclear(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return;
        if(l >= u && r <= v)
        {
            mark[node] = 1;
            propagate(node, l, r);

            return;
        }

        treeclear(2*node, l, mid, u, v);
        treeclear(2*node+1, mid+1, r, u, v);

        tree[node] = (tree[2*node] + tree[2*node+1]);
    }

    void clear(ll l, ll r)
    {
        treeclear(1, 1, n, l, r);
    }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
//        cout << "----  " << node << " " << tree[node] << "\n";
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return 0;
        if(l >= u && r <= v)
        {
//            cout << node << " " << tree[node] << "\n";
            return tree[node];
        }

        return (treeQuery(2*node, l, mid, u, v) + treeQuery(2*node+1, mid+1, r, u, v));
    }

    ll query(ll l, ll r)
    {
        return treeQuery(1, 1, n, l, r);
    }
};

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    fastio;
    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;

        segTree1 seg1(250000);
        segTree2 seg2(250000);

        cout << "Case " << cs <<":\n";

        for(ll i = 1; i <= n; i++)
        {
            char c;
            cin >> c >> l >> r;

            if(c == 'A')
            {
                seg2.update(l,r,1 - l);
                seg1.update(l,r,1);
            }
            else if(c == 'B')
            {
                seg2.update(l,r,r + 1);
                seg1.update(l,r,-1);
            }
            else if(c == 'C')
            {
                cin >> m;
                seg2.clear(l,r);
                seg2.update(l,r,m);
                seg1.clear(l,r);
            }
            else if(c == 'S')
            {
                ans = seg1.query(l,r) + seg2.query(l,r);
                cout << ans << "\n";
            }
        }
    }


}


