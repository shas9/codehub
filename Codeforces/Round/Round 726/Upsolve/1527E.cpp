 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

#define mxlld 1e10
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

    void init(ll _n)
    {
        n = _n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void propagate(ll node, ll l, ll r)
    {
        tree[node] += lazy[node];
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

        tree[node] = min(tree[2*node], tree[2*node+1]);
    }

    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return mxlld;
        if(l >= u && r <= v) return tree[node];

        return min(treeQuery(2*node, l, mid, u, v), treeQuery(2*node+1, mid+1, r, u, v));
    }

    ll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }
} seg[2];


ll mp[40000];
vector < ll > v;

void solve(ll n, ll k)
{
    memset(mp,0,sizeof mp);

    seg[k % 2].init(n);

    for(ll i = 1; i < k; i++) seg[k % 2].update(i,i,mxlld);

    for(ll i = k; i <= n; i++)
    {
        if(mp[v[i]])
        {
            seg[(k - 1) % 2].update(1, mp[v[i]] - 1, i - mp[v[i]]);
        }

        seg[k % 2].update(i,i,seg[(k - 1) % 2].query(1, i - 1));

        mp[v[i]] = i;
    }

//    for(ll i = 1; i <= n; i++) cout << seg[k].query(i,i) << " ";
//    cout << "\n";
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    while(cin >> n >> k)
    {
        v.resize(n + 1);

        for(ll i = 1; i <= n; i++) cin >> v[i];

        memset(mp,0,sizeof mp);
        ll add = 0;

        seg[1].init(n);

        for(ll i = 1; i <= n; i++)
        {
            if(mp[v[i]])
            {
                add += i - mp[v[i]];
            }

            mp[v[i]] = i;

            seg[1].update(i,i,add);

        }

        for(ll i = 2; i <= k; i++)
        {
            solve(n,i);
        }

        cout << seg[k % 2].query(n,n) << "\n";
    }

}
