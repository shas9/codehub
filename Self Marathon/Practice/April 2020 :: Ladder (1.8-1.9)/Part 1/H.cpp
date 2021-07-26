#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

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

        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return 0;
        if(l >= u && r <= v) return tree[node];

        return treeQuery(2*node, l, mid, u, v) + treeQuery(2*node+1, mid+1, r, u, v);
    }

    ll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }
};


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        segTree tree(n + 5);

        ll sz = 1;

        for(i = 1; i <= n; i++)
        {
            ll t;
            ll a;
            ll x;

            slld(t);

            if(t == 1)
            {
                slld(a);
                slld(x);

                assert(a <= sz);

                tree.update(1,a,x);
            }
            else if(t == 2)
            {
                slld(a);

                sz++;

                tree.update(sz,sz,a);
            }
            else if(t == 3)
            {
                if(sz == 1) continue;

                x = tree.query(sz,sz);

                tree.update(sz,sz,-x);

                sz--;
            }

//            for(j = 1; j <= sz; j++)
//            {
//                cout << tree.query(j,j) << " ~ ";
//            }
//
//            cout << endl;
//
//            for(j = 1; j <= 10; j++)
//            {
//                cout << tree.tree[j] << " + ";
//            }
//
//            cout << endl;
//
//
//            cout << tree.query(1,sz) << " " << sz << endl;

            double av = (tree.query(1,sz)) / (sz * 1.0);

            printf("%.7f\n", av);
        }
    }


}


