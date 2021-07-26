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

} seg, seg2;

bool solve()
{
    ll n;
    cin >> n;

    vector < ll > v(n);

    map < ll, ll > mp;

    for(auto &it: v) cin >> it, mp[it] = 0;

    seg.init(n);
    seg2.init(n);

    ll cnt = 0;

    for(auto &it: mp) it.second = ++cnt;

    for(auto &it: v) it = mp[it];

    for(auto it: v) seg2.update(it,it,1);

    vector < string > ss(n + 1);

    for(ll i = v.size() - 1; i >= 0; i--)
    {
        seg2.update(v[i],v[i], -1);

        ll bigger = seg2.query(v[i] + 1, n);

        ll flipped = seg.query(v[i], v[i]);

        if((bigger + flipped) & 1) ss[v[i]] += 'L';
        else ss[v[i]] += 'R';

        seg.update(v[i] + 1, n, 1);
    }

    for(ll i = 1; i <= n; i++)
    {
        ll cntl = 0;

        stack < ll > st;

        for(ll j = 0; j < ss[i].size(); j++)
        {
            if(ss[i][j] == 'L')
            {
                if(st.empty())
                {
                    st.push(j);
                    continue;
                }

                ll x = st.top();

                if((j - x) & 1)
                {
                    st.pop();
                }
                else
                {
                    st.push(x);
                }
            }
        }

        if(!st.empty()) return 0;
    }

    return 1;

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
        if(solve()) cout << "YES\n";
        else cout << "NO\n";

    }


}
