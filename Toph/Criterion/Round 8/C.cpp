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

void brute()
{
	ll n, m;

	cin >> n;
	ll arr[100];

	for(ll i = 1; i <= n; i++) arr[i] = rand() % 15 + 1;
	for(ll i = 1; i <= n; i++) cout << arr[i] << " ";
	cout << "\n";

	cin >> m;

	for(ll i = 1; i <= m; i++)
	{
		ll l, r;

		l = rand() % n + 1;
		r = rand() % n + 1;

		if(l > r) swap(l,r);

		ll sum = 0;
		ll mnn = mxlld;
		ll mxx = mnlld;

		vector < ll > v;

		for(ll j = l; j <= r; j++) sum += arr[j], mnn = min(mnn, arr[j]), mxx = max(mxx, arr[j]), v.push_back(arr[j]);

		sort(v.begin(),v.end());

		ll e1 = v[v.size() / 2];
		ll e2 = v[(v.size() / 2) - 1];

		ll mn = mxlld;
		ll ans = -1;


		for(ll j = mnn; j <= mxx; j++)
		{
			ll d = 0;

			for(ll k = l; k <= r; k++)
			{
				d += abs(j - arr[k]);
			}

			mn = min(mn, d);
		}

		bool on = 0;
		for(ll j = mnn; j <= mxx; j++)
		{
			ll d = 0;

			for(ll k = l; k <= r; k++)
			{
				d += abs(j - arr[k]);
			}

			if(d == mn)
			{
				cout << l  << " " << r << " " << e1 << " " << j << "\n";
			}
		}
	}
}

const ll lim = 100005;

ll arr[lim];
vector < ll > tree[4 * lim];
vector < ll > treesum[4 * lim];

void merge_sort(ll node, ll a, ll b) {
	if (a == b) {
		tree[node].pb(arr[a]);
		treesum[node].pb(arr[a]);
		return;
	}
	ll mid = (a + b) / 2 , left, right;
	left = node * 2 ; right = left + 1;
	merge_sort( left, a, mid);
	merge_sort( right, mid + 1, b);

	merge( tree[left].begin() , tree[left].end() , tree[right].begin(), tree[right].end(), back_inserter(tree[node]));

	ll sum = 0;

	for(auto it: tree[node])
	{
		sum += it;
		treesum[node].push_back(sum);
	}

	assert(treesum[node].size() == tree[node].size());
}

ll up( ll valu, ll node )
{

	auto it = upper_bound(tree[node].begin(), tree[node].end(), valu);

	if(it == tree[node].begin()) return 0;

	it--;

	ll idx = it - tree[node].begin();

	return idx + 1;
}


ll query(ll node, ll a, ll b, ll i, ll j, ll val) {
	if ( a > j || b < i ) return 0;

	if ( i <= a && b <= j )
	{
		if ( tree[node].size() ) return up(val, node);

		return 0;
	}
	ll r1 , r2;
	ll left, right, mid;
	left = node * 2 ;  right = left + 1;
	mid = (a + b) / 2;
	r1 = query( left , a, mid, i , j , val );
	r2 = query( right , mid + 1 , b, i, j, val);
	return r1 + r2;

}

ll solve(ll val, ll node)
{
//	bug;

	ll ret = 0;
	auto it = lower_bound(tree[node].begin(), tree[node].end(), val);

	if(it != tree[node].begin())
	{
		it--;
		ll idx = it - tree[node].begin();

		ret += (val * (idx + 1)) - treesum[node][idx];
	}

//	bug;

	it = upper_bound(tree[node].begin(), tree[node].end(), val);

	if(it != tree[node].end())
	{
//		bug;
		ll idx = it - tree[node].begin();
//		bug;
		ll cnt = tree[node].size() - idx;
//		bug;
		ll sum = treesum[node].back();


//		bug;

		if(idx != 0)
		{
			sum -= treesum[node][idx - 1];
		}

//		bug;

		ret += sum - (val * cnt);
	}

//	bug;

	return ret;
}

ll query2(ll node, ll a, ll b, ll i, ll j, ll val) {

	if ( a > j || b < i ) return 0;

	if ( i <= a && b <= j )
	{
		if ( tree[node].size() ) return solve(val, node);

		return 0;
	}

//	cout << a << " " << b << endl;
	ll r1 , r2;
	ll left, right, mid;
	left = node * 2 ;  right = left + 1;
	mid = (a + b) / 2;
	r1 = query2( left , a, mid, i , j , val );
	r2 = query2( right , mid + 1 , b, i, j, val);
	return r1 + r2;

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


} *root[100005];

map < ll, ll > mp1, mp2;
ll sarr[100005];

ll n;

ll qq(ll l, ll r, ll i, ll j, ll k)
{
//    cout << l << " " << r << endl;
    if(l == r) return l;

    ll mid = (l + r) >> 1;

    ll sum = root[j]->query(1,n,l,mid) - root[i - 1]->query(1,n,l,mid);

    if(sum >= k)
    {
        return qq(l,mid,i,j,k);
    }
    else
    {
        return qq(mid + 1, r, i, j, k - sum);
    }
}

ll srch(ll l, ll r, ll n)
{
	ll pos = (r - l + 2) / 2;

	ll lo = 1;
	ll hi = 1e10;
	ll ret = lo;

//	cout << pos << ": " << endl;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		ll x = query(1,1,n,l,r,mid);

//		cout << mid << " " << x << "\n";

		if(x >= pos)
		{
			ret = mid;
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
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	brute();

    slld(n);
    slld(m);

    root[0] = new node();
    root[0]->build(1,n);

    for(i = 1; i <= n; i++) root[0] = root[0] -> update(1,n,i,0);

    for(ll i = 1; i <= n; i++) slld(arr[i]), sarr[i] = arr[i];

    sort(sarr + 1, sarr + 1 + n);

    ll cnt = 0;

    for(i = 1; i <= n; i++)
    {
        mp1[sarr[i]] = ++cnt;
        mp2[cnt] = sarr[i];
    }

    for(i = 1; i <= n; i++)
    {
        root[i] = root[i - 1] ->update(1,n,mp1[arr[i]],1);
    }

    merge_sort(1,1,n);

    for(ll i = 1; i <= m; i++)
    {
		slld(l);
		slld(r);

		ll middle = qq(1,n,l,r,(r - l + 2) / 2);
		ans = query2(1,1,n,l,r,mp2[middle]);

		cout << ans << "\n";

    }


}



