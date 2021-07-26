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

struct segtree
{


    ll n;
    vector<ll> tree, lazy;

    void init(ll _n)
    {
        n = _n;
        tree.assign(4 * n,0);
        lazy.assign(4 * n,0);
    }


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

} seg;

vector < pll > v;

bool solve()
{
    bool last = 0;
    seg.init()

    for(ll i = 1; i < v.size(); i++)
    {
        if(last)
        {
            if(v[i].first != v[i - 1].first) return 0;
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;
        v.resize(n + 1);

        for(ll i = 1; i <= n; i++)
        {
            cin >> v[i].first;
            v[i].second = i;
        }

        sort(v.begin(), v.end());

        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }


}


