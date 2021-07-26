// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long
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
            tree[node] = val;
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        treeupdate(left, b, mid, i, val);
        treeupdate(right, mid + 1, e, i, val);

        tree[node] = (tree[left] + tree[right]);
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

        return (p1 + p2);
    }

    ll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }

} seg;

const ll maxn  = 200002;
vector < ll > primes;
bool vis[maxn+10];

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
            for(ll j = i * i; j <= maxn; j += i)
            {
                vis[j] = 1;
            }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
            primes.push_back(i);
    }
}

set < ll > st[200005];

void process(ll x, ll idx)
{
    for(auto it: primes)
    {
        if(it * it > x) break;

        if(x % it == 0)
        {
            while(x % it == 0) x /= it;
            st[it].insert(idx);
        }
    }

    if(x > 1)
    {
        st[x].insert(idx);
    }

    return;
}

void solve(ll l, ll r, ll g)
{
    for(auto it: primes)
    {
        if(it * it > g) break;

        ll cnt = 0;

        while(g % it == 0) g /= it, cnt++;

        if(cnt)
        {
            vector < ll > vec;
            for(set < ll > :: iterator jt = st[it].lower_bound(l); jt != st[it].end(); jt++)
            {
                ll idx = *jt;
                if(idx > r) break;
                ll val = seg.query(idx,idx);

                for(ll i = 1; i <= cnt; i++)
                {
                    if(val % it) break;
                    val /= it;
                }

                if(val % it) vec.push_back(idx);
                seg.update(idx, val);
            }

            for(auto jt: vec)
            {
                st[it].erase(jt);
            }
        }
    }

    if(g > 1)
    {
        vector < ll > vec;
        ll cnt = 1;
        for(set < ll > :: iterator jt = st[g].lower_bound(l); jt != st[g].end(); jt++)
        {
            ll idx = *jt;
            if(idx > r) break;
            ll val = seg.query(idx,idx);

            for(ll i = 1; i <= cnt; i++)
            {
                if(val % g) break;
                val /= g;
            }

            if(val % g) vec.push_back(idx);
            seg.update(idx, val);
        }

        for(auto jt: vec)
        {
            st[g].erase(jt);
        }
    }

    return;
}


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    sieve();

    while(cin >> n >> m)
    {
        for(ll i = 0; i <= 2e5; i++) st[i].clear();

        seg.init(n);

        for(ll i = 1; i <= n; i++)
        {
            cin >> in;
            seg.update(i,in);

            process(in, i);
        }

        for(ll i = 1; i <= m; i++)
        {
            ll t, g;
            cin >> t >> l >> r;

            if(t == 1)
            {
                cout << seg.query(l,r) << "\n";
            }
            else
            {
                cin >> g;
                solve(l,r,g);
            }
        }
    }


}

