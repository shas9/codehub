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


} *roots[100005], *roote[100005];

ll query(node *head1, node *head2, ll l, ll r, ll i, ll j)
{
    if(i > j) return 0;
    if(r < i || l > j) return 0; // out of range
    if(i <= l && r <= j)   // completely inside
    {
        return head1->val - head2->val;  // return value stored in this node
    }
    ll mid = l + r >> 1;

    return query(head1->left, head2->left, l, mid,i,j) + query(head1->right, head2->right,mid+1, r,i,j);
}

struct lecture
{
    ll sa, sb, ea, eb;
} arr[100005];

bool comp(lecture a,lecture b)
{
    if(a.sa != b.sa) return a.sa < b.sa;

    return a.ea < b.ea;
}

/*
int main()
{
    root[0] = new node();
    root[0] -> build(1,n);
    root[1] = root[0] -> update(1,n, idx, v);
    root[0] = root[0] -> update(1,n, idx, v);
}
*/

set < ll > st;
map < ll, ll > mp;
ll n;

ll fnd(ll idx)
{
    ll lo = idx + 1;
    ll hi = n;

    ll ret = idx;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(arr[mid].sa <= arr[idx].ea)
        {
            ret = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i].sa);
        slld(arr[i].ea);
        slld(arr[i].sb);
        slld(arr[i].eb);

        st.insert(arr[i].sa);
        st.insert(arr[i].ea);
        st.insert(arr[i].sb);
        st.insert(arr[i].eb);
    }

    sort(arr + 1, arr + 1 + n, comp);

    ll cnt = 0;

    for(auto it = st.begin(); it != st.end(); it++)
    {
        mp[*it] = ++cnt;
    }

    roots[0] = new node();
    roots[0] -> build(1,cnt);

    roote[0] = new node();
    roote[0] -> build(1,cnt);

    for(i = 1; i <= n; i++)
    {
        arr[i].sa = mp[arr[i].sa];
        arr[i].sb = mp[arr[i].sb];
        arr[i].ea = mp[arr[i].ea];
        arr[i].eb = mp[arr[i].eb];

        roots[i] = roots[i - 1]->update(1,cnt,arr[i].sb,1);
        roote[i] = roote[i - 1]->update(1,cnt,arr[i].eb,1);
    }

    bool ok = 1;

    for(i = 1; i <= n; i++)
    {
        ll inter = fnd(i);

        ll ax = (inter - i);
        ll bx = query(roots[inter], roots[i],1,cnt,1,arr[i].eb) - query(roote[inter],roote[i],1,cnt,1,arr[i].sb - 1);

        if(ax != bx) ok = 0;

        if(!ok) break;

//        if(inter == n) continue;
//
//        inter++;

        ll by = query(roots[n], roots[inter],1,cnt,1,arr[i].eb) - query(roote[n],roote[inter],1,cnt,1,arr[i].sb - 1);

        if(by != 0) ok = 0;

        if(!ok) break;
    }

    if(!ok) cout << "NO" << endl;
    else cout << "YES" << endl;












}



