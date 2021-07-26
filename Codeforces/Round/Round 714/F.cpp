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

struct segtree
{

    ll n;
    vector < ll > tree;

    void init(ll _n)
    {
        n = _n;
        tree.assign(4 * n,0);
    }

    void treeupdate(ll node, ll b, ll e, ll i, ll val)
    {
        if(i > e || i < b)
        {
            return;
        }

        if(b == i && e == i)
        {
            tree[node] = max(tree[node], val);
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        treeupdate(left, b, mid, i, val);
        treeupdate(right, mid + 1, e, i, val);

        tree[node] = max(tree[left], tree[right]);
    }

    void update(ll i, ll val)
    {
        treeupdate(1,1,n,i,val);
    }

    ll treequery(ll node, ll b, ll e, ll i, ll j)
    {
        if(i > e || j < b)
        {
            return 0;
        }

        if(b >= i && e <= j)
        {
            return tree[node];
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        ll p1 = treequery(left, b, mid, i, j);
        ll p2 = treequery(right, mid + 1, e,i, j);

        return max(p1,p2);
    }

    ll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }

} seg;

struct segtree1
{

    ll n;
    vector < ll > tree;


    void init(ll _n)
    {
        n = _n;
        tree.assign(4 * n,mxlld);
    }

    void treeupdate(ll node, ll b, ll e, ll i, ll val)
    {
        if(i > e || i < b)
        {
            return;
        }

        if(b == i && e == i)
        {
            tree[node] = min(tree[node], val);
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        treeupdate(left, b, mid, i, val);
        treeupdate(right, mid + 1, e, i, val);

        tree[node] = min(tree[left], tree[right]);
    }

    void update(ll i, ll val)
    {
        treeupdate(1,1,n,i,val);
    }

    ll treequery(ll node, ll b, ll e, ll i, ll j)
    {
        if(i > e || j < b)
        {
            return mxlld;
        }

        if(b >= i && e <= j)
        {
            return tree[node];
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        ll p1 = treequery(left, b, mid, i, j);
        ll p2 = treequery(right, mid + 1, e,i, j);

        return min(p1,p2);
    }

    ll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }

} seg2;

map < ll, ll > mp1, mp2;
vector < ll > aa, bb;

vector < pll > v1, v2;

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
        mp1.clear();
        mp2.clear();
        v1.clear();
        v2.clear();

        ll sum = 0;

        aa.resize(n);
        bb.resize(n);

        for(auto &it: aa) cin >> it;
        for(auto &it: bb) cin >> it;

        while(n--)
        {
            ll a = aa.back();
            ll b = bb.back();

            aa.pop_back();
            bb.pop_back();

            if(a > b) v1.push_back({a,b});
            else v2.push_back({a,b});

            mp1[a] = 0;
            mp1[b] = 0;

            sum += abs(a-b);
        }

//        bug(1);

        ll cnt = 0;

        for(auto &it: mp1)
        {
            it.second = ++cnt;
            mp2[cnt] = it.first;
        }

//        bug(2);

        seg.init(cnt);
        seg2.init(cnt);

        for(auto it: v2)
        {
            seg.update(mp1[it.first], it.second);
            seg2.update(mp1[it.second], it.first);
        }

//        bug(3);

        ans = 0;

        for(auto it: v1)
        {
            ll ask = seg.query(1,mp1[it.second]);

            ans = max(ans, min(ask, it.first) - it.second);

            ask = seg2.query(mp1[it.first], cnt);

            if(ask > 1e10) continue;

            ans = max(ans, it.first - max(it.second, ask));
        }

//        bug(4);

        seg.init(cnt);

        for(auto it: v1)
        {
            seg.update(mp1[it.second], it.first);
        }

        for(auto it: v2)
        {
            ll ask = seg.query(1, mp1[it.first]);

            if(ask >= it.second) ans = max(ans, it.second - it.first);
        }

        cout << sum - (2 * ans) << "\n";
    }


}

