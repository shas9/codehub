 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

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

};

struct info
{
    ll m, f, w;
};

bool comp(info a, info b)
{
    return a.m < b.m;
}

vector < info > vec;

ll fnd(ll x)
{
    ll lo = 0;
    ll hi = vec.size() - 1;
    ll ret = hi + 1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(vec[mid].m >= x)
        {
            hi = mid - 1;
            ret = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ret + 1;
}
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        vec.resize(n);
        segtree seg;
        seg.init(n);

        for(auto &it: vec) cin >> it.m >> it.f >> it.w;

        sort(vec.begin(), vec.end(), comp);

        for(ll i = n - 1; i >= 0; i--)
        {
            ll idx = fnd(vec[i].m + vec[i].w);
            ll add = 0;

            if(idx <= n) add = seg.query(idx, n);

            add += vec[i].f;

            seg.update(i + 1, add);

//            cout << vec[i].m << " " << add << "\n";
        }

        cout << seg.query(1,n) << "\n";
    }


}


