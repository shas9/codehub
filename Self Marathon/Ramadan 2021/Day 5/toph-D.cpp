 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

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
        tree[node] += lazy[node] * (r - l + 1);
        if(l != r) lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];
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
    }

    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return 0;
        if(l >= u && r <= v) return tree[node];

        return (treeQuery(2*node, l, mid, u, v) + treeQuery(2*node+1, mid+1, r, u, v));
    }

    ll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }
};

ll idx[500005];

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    while(cin >> n >> m)
    {
        segTree seg(1000000);
        ll now = 1000000;

        for(ll i = 1; i <= n; i++)
        {
            idx[i] = now;
            cin >> in;
            seg.update(idx[i], idx[i], in);
            now--;
        }

        for(ll i = 1; i <= m; i++)
        {
            cin >> in;

            ll val = seg.query(idx[in], idx[in]);

            if(val <= 0)
            {
                cout << "Dead\n";
                continue;
            }

            seg.update(now + 1, idx[in], -1);

            idx[in] = now;
            seg.update(now, now, val);
            now--;
        }

        for(i = 1; i <= n; i++)
        {
            cout << max(0LL, seg.query(idx[i], idx[i])) << " ";
        }

        cout << "\n";
    }


}

