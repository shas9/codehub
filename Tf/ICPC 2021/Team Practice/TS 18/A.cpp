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

ll arr[400005];

/*
2 7
9 6

Q 1 2

Q 1 1

Q 2 2
A 1 2 7

Q 1 2

Q 1 1

Q 2 2

*/

struct segTree
{
    ll n;
    vector<ll> tree1, tree2;

    segTree(ll n): n(n), tree1(4*n, 0), tree2(4*n, 0) {}

    void build(ll node, ll l, ll r)
    {
        if(l == r)
        {
            tree1[node] = arr[l];
            tree2[node] = arr[l];

            return;
        }

        ll mid = (l+r)>>1;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        tree1[node] = max(tree1[2*node], tree1[2*node+1]);
        tree2[node] = (tree2[2*node] | tree2[2*node+1]);
    }


    void treeUpdate(ll node, ll l, ll r, ll u, ll v, ll val)
    {
        ll mid = (l+r)>>1;

        if(l > v || r < u) return;
        if(l >= u && r <= v)
        {
            val &= tree2[node];
            tree1[node] = val;
            tree2[node] = val;

            return;
        }

        treeUpdate(2*node, l, mid, u, v, val);
        treeUpdate(2*node+1, mid+1, r, u, v, val);

        tree1[node] = max(tree1[2*node], tree1[2*node+1]);
        tree2[node] = (tree2[2*node] | tree2[2*node+1]);
    }

    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }

    void treeUpdate2(ll node, ll l, ll r, ll u, ll v, ll val)
    {
        ll mid = (l+r)>>1;

        if(l > v || r < u) return;
        if(l == r)
        {
            tree1[node] = val;
            tree2[node] = val;
            return;
        }

        treeUpdate2(2*node, l, mid, u, v, val);
        treeUpdate2(2*node+1, mid+1, r, u, v, val);

        tree1[node] = max(tree1[2*node], tree1[2*node+1]);
        tree2[node] = (tree2[2*node] | tree2[2*node+1]);
    }

    void update2(ll l, ll r, ll val) { treeUpdate2(1, 1, n, l, r, val); }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        if(l > v || r < u) return mnlld;
        if(l >= u && r <= v) return tree1[node];

        return max(treeQuery(2*node, l, mid, u, v), treeQuery(2*node+1, mid+1, r, u, v));
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

//    fastio;
    while(cin >> n >> m)
    {
        segTree seg(n);

        for(ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        seg.build(1,1,n);

        for(ll i = 1; i <= m; i++)
        {
            string s;
            cin >> s;

            if(s.front() == 'A')
            {
                cin >> l >> r >> k;

                seg.update(l,r,k);
            }
            else if(s.front() == 'U')
            {
                cin >> r >> k;

                seg.update2(r,r,k);
            }
            else
            {
                cin >> l >> r;
                cout << seg.query(l,r) << "\n";
            }
        }
    }

}





