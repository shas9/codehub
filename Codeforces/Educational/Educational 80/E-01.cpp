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

struct node
{

    node *left, *right;
    ll val;

    node(ll a = 0, node *b = NULL, node *c = NULL) :
        val(a),  left(b), right(c) {} // ** Constructor

    void build(ll l, ll r)    // We are not  initializing values for now.
    {
        if(l == r) return; // We reached leaf node, No need more links
        left = new node(); // Create new node for Left child
        right = new node();// We are creating nodes only when necessary!
        ll mid = l + r >> 1;
        left -> build(l, mid);
        right -> build(mid+1, r);
    }

    node *update(ll l, ll r, ll idx, ll v)
    {
        if(r < idx || l > idx) return this; // Out of range, use this node.
        if(l == r)    // Leaf Node, create new node and return that.
        {
            node *ret = new node(val, left, right);
            ret -> val += v;
            return ret;
            // we first cloned our current node, then added v to the value.
        }
        ll mid = l + r >> 1;
        node *ret = new node(val); //Create a new node, as idx in in [l, r]
        ret -> left = left -> update(l, mid, idx, v);
        ret -> right = right -> update(mid+1, r, idx, v);
        // Note that 'ret -> left' is new node's left child,
        // But 'left' is current old node's left child.
        // So we call to update idx in left child of old node.
        // And use it's return node as new node's left child. Same for right.
        ret -> val = ret -> left -> val + ret -> right -> val; // Update value.
        return ret; // Return the new node to parent.
    }

    // [l, r] node range, [i, j] query range
    ll query(ll l, ll r, ll i, ll j)
    {
        if(r < i || l > j) return 0; // out of range
        if(i <= l && r <= j)   // completely inside
        {
            return val;  // return value stored in this node
        }
        ll mid = l + r >> 1;
        return left -> query(l, mid,i,j) + right -> query(mid+1, r,i,j);
    }


} *root[1200006];

ll arr[600005];
ll lst[300005];
ll mx[300005];
ll mn[300005];
ll rt[600005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++)
    {
        arr[i + m] = i;

        mn[i] = i;
        mx[i] = -1;
    }

    for(i = 1, j = 0; i <= m; i++, j++)
    {
        slld(arr[m - j]);

        mn[arr[m - j]] =1;
    }

    root[0] = new node();
    root[0] -> build(1,n);

    ll t = 1;

    for(i = 1; i <= n + m; i++)
    {

    }

}



