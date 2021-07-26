#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

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

vector < pll > vec;
ll arr[200005];
bool comp(pll a, pll b)
{
	if(a.first == b.first) return a.second < b.second;

	return a.first > b.first;
}

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
    ll query(ll l, ll r, ll k)
    {
		if(l == r) return r;

		ll mid = l + r >> 1;

		if(left -> val >= k) return left->query(l,mid,k);

		return right ->query(mid + 1, r, k - (left->val));
    }


} *root[200005];

ll kthsmallest(ll l, ll r, ll head, ll k)
{
	return root[head] ->query(l,r,k);
}

//int main()
//{
//    root[0] = new node();
//    root[0] -> build(1,n);
//    root[1] = root[0] -> update(1,n, idx, v);
//    root[0] = root[0] -> update(1,n, idx, v);
//}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i <= n; i++)
    {
		slld(arr[i]);

		vec.push_back({arr[i], i});
    }

    sort(vec.begin(),vec.end(),comp);

    root[0] = new node();
    root[0] ->build(1,n);

    for(i = 0; i < n; i++)
    {
		root[i + 1] = root[i] -> update(1,n,vec[i].second,1);
    }

    slld(m);

    for(i = 1; i <= m; i++)
    {
		ll pos;
		slld(k);
		slld(pos);

		ans = kthsmallest(1,n,k,pos);

		printf("%lld\n", arr[ans]);
    }
}



