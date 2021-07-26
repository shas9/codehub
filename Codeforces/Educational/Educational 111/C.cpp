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
            tree[node] = val;
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

        return max(p1, p2);
    }

    ll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }

} mx;

struct segtree2
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
            tree[node] = val;
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

        return min(p1, p2);
    }

    ll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }

} mn;


ll fndchoto(ll x, ll pos)
{
    ll lo = 1;
    ll hi = pos - 1;

    ll ret = 0;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(mn.query(mid, pos - 1) <= x)
        {
//            if(x == 1)
//            {
//                cout << mn.query(mid, pos - 1) << " " << mid << "\n";
//            }
            ret = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ret;
}


ll fndboro(ll x, ll pos)
{
    ll lo = 1;
    ll hi = pos - 1;

    ll ret = 0;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(mx.query(mid, pos - 1) >= x)
        {
            ret = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    fastio;
    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;
        vector < ll > v(n);

        map < ll, ll > mp;

        segtree seg1;
        seg1.init(n);
        segtree seg2;
        seg2.init(n);

        for(auto &it: v) cin >> it, mp[it] = 0;

        ll cnt = 0;

        for(auto &it: mp) it.second = ++cnt;

        for(auto &it: v) it = mp[it];

        v.insert(v.begin(), -1);

        mx.init(n);
        mn.init(n);

        for(ll i = 1; i <= n; i++)
        {
            mx.update(i,v[i]);
            mn.update(i,v[i]);
        }

        ans = 0;

        ll mxx = 0;

        for(ll i = 1; i <= n; i++)
        {
            ll last = max(max(seg1.query(1, v[i]), seg2.query(v[i], n)), mxx);
            mxx = max(mxx, last);

            ll choto = fndchoto(v[i], i);
            ll boro = fndboro(v[i], i);

            seg1.update(v[i], choto);
            seg2.update(v[i], boro);

//            cout << i << " " << last << " " << choto << " " << boro << "\n";

            assert(choto < i);
            assert(boro < i);

            last = (i - last);

            if(i == 1) assert(last >= 1);
            else assert(last >= 2);

            ans += last;
        }

        cout << ans << "\n";

    }


}

