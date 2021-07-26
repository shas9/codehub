#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


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
    vector < bool > flag;

    segTree(ll n): n(n), tree(4*n, 0), lazy(4*n, 0), flag(4*n, 0) {}

    void propagate(ll node, ll l, ll r)
    {
        if(flag[node]) tree[node] = 0;

        tree[node] += lazy[node];

        if(l != r)
        {
            if(flag[node] == 0)lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];
            else
            {
                flag[2*node] = 1;
                flag[2*node + 1] = 1;
                lazy[2*node] = 0;
                lazy[2*node + 1] = 0;
            }
        }


        lazy[node] = 0;

        flag[node] = 0;
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

        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void treeZUpdate(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return;
        if(l >= u && r <= v)
        {
            lazy[node] = 0;
            flag[node] = 1;
            propagate(node, l, r);

            return;
        }

        treeZUpdate(2*node, l, mid, u, v);
        treeZUpdate(2*node+1, mid+1, r, u, v);

        tree[node] = tree[2*node] + tree[2*node+1];
    }


    void update(ll l, ll r, ll val)
    {
        treeUpdate(1, 1, n, l, r, val);
    }

    void Zupdate(ll l, ll r)
    {
        treeZUpdate(1, 1, n, l, r);
    }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return 0;
        if(l >= u && r <= v) return tree[node];

        return treeQuery(2*node, l, mid, u, v) + treeQuery(2*node+1, mid+1, r, u, v);
    }

    ll query(ll l, ll r)
    {
        return treeQuery(1, 1, n, l, r);
    }
};


unordered_map < ll, ll > mp;
set < ll > st;
ll arr[500005];
ll sum[500005];
ll arr2[500005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++) slld(arr[i]), st.insert(arr[i]);

    ll cnt = 0;
    for(set < ll > ::iterator it = st.begin(); it != st.end(); it++)
    {
        mp[*it] = ++cnt;
    }

    segTree tree1(n);
    segTree tree2(n);

    ll dsum = 0;

    for(i = 1; i <= n; i++)
    {
        ll num = mp[arr[i]];

        ll qq1 = tree1.query(num + 1, n);
        ll qq2 = tree2.query(num + 1, n);

        dsum -= qq1 - (arr[i] * qq2);


        sum[i] = dsum;

        tree1.Zupdate(num + 1, n);
        tree2.Zupdate(num + 1, n);

        tree1.update(num, num, arr[i] * (1 + qq2));
        tree2.update(num, num, 1 + qq2);

        dsum += arr[i];
    }

    tree1.Zupdate(1,n);
    tree2.Zupdate(1,n);


    dsum = 0;
    ans = 0;
    ll idx = 0;

    for(i = n; i >= 1; i--)
    {
        ll num = mp[arr[i]];

        ll qq1 = tree1.query(num + 1, n);
        ll qq2 = tree2.query(num + 1, n);

        dsum -= qq1 - (arr[i] * qq2);

        ans = max(ans, sum[i] + dsum + arr[i]);

        if(ans == sum[i] + dsum + arr[i]) idx = i;

        tree1.Zupdate(num + 1, n);
        tree2.Zupdate(num + 1, n);

        tree1.update(num, num, arr[i] * (1 + qq2));
        tree2.update(num, num, 1 + qq2);

        dsum += arr[i];
    }

    arr2[idx] = arr[idx];

    for(i = idx - 1; i >= 1; i--)
    {
        arr2[i] = min(arr2[i + 1], arr[i]);
    }

    for(i = idx + 1; i <= n; i++)
    {
        arr2[i] = min(arr2[i - 1], arr[i]);
    }

//    cout << ans << endl;

    for(i = 1; i <= n; i++)
        printf("%lld ", arr2[i]);

    printf("\n");




}




