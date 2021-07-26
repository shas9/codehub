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

struct segTree
{
    ll n;
    vector <pll> tree;
    vector <ll> lazy;

    segTree(ll n): n(n), tree(4*n, {0,0}), lazy(4*n, 0) {}

    void init(ll _n)
    {
		n = _n;
		tree.assign(4 * n, {0,0});
		lazy.assign(4 * n, 0);
    }

    void propagate(ll node, ll l, ll r)
    {
        tree[node].first += lazy[node];
        if(l != r) lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];
        lazy[node] = 0;
    }

    void treeUpdate(ll node, ll l, ll r, ll u, ll v, ll val)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return;
        if(l >= u && r <= v)
        {
            lazy[node] += val;
            tree[node].second = l;
            propagate(node, l, r);

            return;
        }

        treeUpdate(2*node, l, mid, u, v, val);
        treeUpdate(2*node+1, mid+1, r, u, v, val);

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return mnlld;
        if(l >= u && r <= v) return tree[node].first;

        return max(treeQuery(2*node, l, mid, u, v), treeQuery(2*node+1, mid+1, r, u, v));
    }

    ll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }

    pll treeQuery1(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return {mnlld,-1};
        if(l >= u && r <= v) return tree[node];

        return max(treeQuery1(2*node, l, mid, u, v), treeQuery1(2*node+1, mid+1, r, u, v));
    }

    ll querypos(ll l, ll r) { return treeQuery1(1, 1, n, l, r).second; }

} seg(1);

ll n, k;

bool solve(ll lft, ll rgt, ll lmx, ll lmn, ll rmx, ll rmn)
{
//	cout << lft << " to " << rgt << " = " << lmx << " " << lmn << " & " << rmx << " " << rmn << "\n";
	if(lft == rgt)
	{
		ll val = seg.query(lft,lft);

		if(lft == 1)
		{
			return (rmx >= val && rmn <= val);
		}

		if(lft == n)
		{
			return (lmx >= val && lmn <= val);
		}

		if(lmn <= val + (k - 1) && val <= lmx && rmn <= val + (k - 1) && val <= rmx) return 1;

		return 0;
	}

	ll mx = seg.query(lft, rgt);
	ll pos = seg.querypos(lft,rgt);

//	cout << mx << " ** " << pos << endl;

	if(lft < pos && pos < rgt)
	{
		if(solve(lft, pos - 1, lmx, lmn, mx + (k - 1), mx - (k - 1)) == 0) return 0;
		if(solve(pos + 1, rgt, mx + (k - 1), mx - (k - 1), rmx, rmn) == 0) return 0;
	}

	if(lft == pos)
	{
		if(solve(lft + 1, rgt, min(lmx, mx) + k - 1, max(lmn,mx) - (k - 1), rmx, rmn) == 0) return 0;
		if(solve(lft, lft, lmx, lmn, mx, mx) == 0) return 0;
	}

	if(rgt == pos)
	{
		if(solve(lft, rgt - 1, lmx, lmn, min(rmx, mx) + (k - 1), max(rmn, mx) - (k - 1)) == 0) return 0;
		if(solve(rgt, rgt, mx, mx, rmx, rmn) == 0) return 0;
	}

	return 1;
}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> k;
		seg.init(n);

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;
			seg.update(i,i,input);
		}

		if(solve(1,n,seg.query(1,1),seg.query(1,1),seg.query(n,n),seg.query(n,n))) cout << "YES\n";
		else cout << "NO\n";
    }


}



