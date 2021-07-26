// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

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

    segTree(ll n): n(n), tree(4 * n, 0), lazy(4*n, 0) {}

    void propagate(ll node, ll l, ll r)
    {
        if(l != r) lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node], lazy[node] = 0;
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
    }

    void update(ll l, ll r, ll val)
    {
        treeUpdate(1, 1, n, l, r, val);
    }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        if(l == r) return lazy[node];
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(u <= mid) return treeQuery(2*node, l, mid, u, v);

        return treeQuery(2*node+1, mid+1, r, u, v);
    }

    ll query(ll l, ll r)
    {
        return treeQuery(1, 1, n, l, r);
    }
};

bool solve()
{
    ll n;
    cin >> n;
    segTree seg(n);

    vector < ll > vec(n);

    for(auto &it: vec) cin >> it;

    sort(vec.begin(), vec.end());

    for(ll i = 0; i < n; i++)
    {
        seg.update(i + 1, i + 1, vec[i]);
    }

    for(ll i = 1; i <= n; i++)
    {
        ll now = seg.query(i,i);

        if(now == 0) continue;

        ll idx = (n - now + 1);

        if(idx <= i) return 0;

        seg.update(idx,n,-1);

        ll val = seg.query(idx,idx);

        ll idx1 = -1;
        ll lo = i + 1;
        ll hi = idx - 1;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if(seg.query(mid,mid) > val)
            {
                idx1 = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        if(idx1 == -1) continue;

        ll idx2 = idx;
        lo = idx + 1;
        hi = n;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if(seg.query(mid,mid) <= val)
            {
                idx2 = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        ll cnt1 = (idx - idx1);
        ll cnt2 = (idx2 - idx + 1);

        seg.update(idx1, idx1 + min(cnt1, cnt2) - 1, -1);
        seg.update(idx2 - min(cnt1, cnt2) + 1, idx2, 1);
    }

    return 1;


}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        if(solve()) cout << "Y\n";
        else cout << "N\n";
    }


}
