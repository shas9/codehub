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

vector < ll > v;

struct segtree
{

    ll n;
    vector < ll > tree1, tree2;


    void init(ll _n)
    {
        n = _n;
        tree1.assign(4 * n,0);
        tree2.assign(4 * n,0);
    }

    void treeupdate(ll node, ll b, ll e, ll i, ll val)
    {
        if(i > e || i < b)
        {
            return;
        }

        if(b == i && e == i)
        {
            tree1[node] = val;
            tree2[node] = val;
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        treeupdate(left, b, mid, i, val);
        treeupdate(right, mid + 1, e, i, val);

        tree1[node] = min(tree1[left], tree1[right]);
        tree2[node] = __gcd(tree2[left], tree2[right]);
    }

    void update(ll i, ll val)
    {
        treeupdate(1,1,n,i,val);
    }

    pll treequery(ll node, ll b, ll e, ll i, ll j)
    {
        if(i > e || j < b)
        {
            return {mxlld, 0};
        }

        if(b >= i && e <= j)
        {
            return {tree1[node], tree2[node]};
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        pll p1 = treequery(left, b, mid, i, j);
        pll p2 = treequery(right, mid + 1, e,i, j);

        return {min(p1.first, p2.first), __gcd(p1.second, p2.second)};
    }

    pll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }

} seg;

ll par[200005];

ll fnd(ll node)
{
    if(par[node] == node) return node;

    return par[node] = fnd(par[node]);
}

set < ll > st;

ll lftdsu(ll x, ll pos)
{
    ll lo = 0;
    ll hi = pos;
    ll ret = -1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(fnd(mid) == x)
        {
            hi = mid - 1;
        }
        else
        {
            ret = mid;
            lo = mid + 1;
        }
    }

    return ret;
}

ll rgtdsu(ll x, ll pos, ll n)
{
    ll lo = pos;
    ll hi = n - 1;
    ll ret = -1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(fnd(mid) == x)
        {
            lo = mid + 1;
        }
        else
        {
            ret = mid;
            hi = mid - 1;
        }
    }

    return ret;
}

ll solveright(ll u, ll x, ll y)
{
    ll lo = x;
    ll hi = y;
    ll ret = lo - 1;
    ll pu = fnd(u);

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        pll ask = seg.query(u + 1, mid + 1);

        if(ask.first == ask.second)
        {
            ret = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    ll ans = 0;

    for(ll i = x; i <= ret; i++)
    {
        ll pv = fnd(i);

        if(pv == pu) break;

        par[pv] = pu;
        ans += v[u];
    }

    return ans;
}

ll solveleft(ll u, ll x, ll y)
{
    ll lo = x;
    ll hi = y;
    ll ret = hi + 1;
    ll pu = fnd(u);

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        pll ask = seg.query(mid + 1, u + 1);

        if(ask.first == ask.second)
        {
            ret = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    ll ans = 0;

    for(ll i = y; i >= ret; i--)
    {
        ll pv = fnd(i);

        if(pv == pu) break;

        par[pv] = pu;
        ans += v[u];
    }

    return ans;
}

ll solve(ll n, ll p)
{
    vector < pll > mn;

    for(ll i = 0; i < n; i++)
    {
        par[i] = i;
        mn.push_back({v[i],i});
    }

    sort(mn.begin(), mn.end());

    ll ret = 0;

    st.clear();

//    bug(1);

    for(auto it: mn)
    {
        if(it.first >= p) break;

        ll u = it.second;
        ll pu = fnd(u);

        auto jt = st.upper_bound(u);

        ll lft = lftdsu(pu, u);
        ll rgt = rgtdsu(pu, u, n);

        if(rgt != -1)
        {
            ll x = n;
            if(jt != st.end()) x = *jt;

            ret += solveright(u, rgt, x - 1);
        }

        if(lft != -1)
        {
            ll x = -1;
            if(jt != st.begin()) jt--, x = *jt;

            ret += solveleft(u, x + 1, lft);
        }

        st.insert(u);
    }

//    bug(2);

    st.clear();

    for(ll i = 0; i < n; i++)
    {
        ll pi = fnd(i);
//        cout << i << " = " << pi << endl;
        st.insert(pi);
    }

    ret += (p * (st.size() - 1));

    return ret;


}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> m;

        v.resize(n);

        for(auto &it: v)
        {
            cin >> it;
        }

        seg.init(n);

        for(ll i = 0; i < n; i++)
        {
            seg.update(i + 1, v[i]);
        }

        ans = solve(n,m);

        cout << ans << "\n";
    }


}

