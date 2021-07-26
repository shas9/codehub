 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
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

void test()
{
	ll cnt = 0;
	ll n = (1e5);

	for(ll i = 1; i <= n; i++)
	{
		cnt += (n / i);
	}

	cout << cnt << "\n";
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
    ll query(ll l, ll r, ll v)
    {
        if(l == r)   // completely inside
        {
            return l;  // return value stored in this node
        }

        ll mid = l + r >> 1;
        if(left -> val >= v) return left -> query(l, mid,v);
        else return right -> query(mid+1, r,v - (left -> val));
    }


} *root[100005];

ll val[100005];
vector < ll > g[100005];

ll bs(ll last, ll idx)
{
	ll lo = 0;
	ll hi = g[idx].size() - 1;
	ll ret = -1;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(g[idx][mid] > last)
		{
			ret = g[idx][mid];
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	while(cin >> n)
	{
		root[1] = new node();
		root[1] -> build(1,n);

		for(ll i = 1; i <= n; i++)
		{
			cin >> val[i];

			if(g[val[i]].empty()) root[1] = root[1] -> update(1,n,i,1);

			g[val[i]].push_back(i);
		}

		for(ll i = 1; i <= n; i++)
		{
			root[i + 1] = root[i] -> update(1,n,i,-1);

			ll pos = bs(i, val[i]);

//			cout << i << " " << pos << endl;

			if(pos != -1) root[i + 1] = root[i + 1] ->update(1,n,pos,1);
		}
//
//		cout << root[1] -> val << " ++ " << endl;

//		for(ll i = 1; i <= n; i++) cout << i << " : " << root[i] -> query(1,n,1) << endl;

		for(ll i = 1; i <= n; i++)
		{
			ll now = 1;
			ans = 0;

			while(now <= n)
			{
				ans++;

				if(root[now] -> val <= i) break;

				now = root[now] -> query(1,n,i + 1);

//				cout << now << " == " << endl;
			}

			cout << ans << " ";
		}

		cout << endl;
	}


}


