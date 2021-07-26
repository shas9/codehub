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
    vector<ll> tree, lazy;

    segTree(ll n): n(n), tree(4*n, 0), lazy(4*n, 0) {}

    void propagate(ll node, ll l, ll r)
    {
        tree[node] += lazy[node];
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
            propagate(node, l, r);

            return;
        }

        treeUpdate(2*node, l, mid, u, v, val);
        treeUpdate(2*node+1, mid+1, r, u, v, val);

        tree[node] = min(tree[2*node], tree[2*node+1]);
    }

    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return mxlld;
        if(l >= u && r <= v) return tree[node];

        return min(treeQuery(2*node, l, mid, u, v), treeQuery(2*node+1, mid+1, r, u, v));
    }

    ll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }
} odd(200000), even(200000);

ll arr[200005];

bool soln(ll n)
{
	if(odd.query(1,n) >= 0 && even.query(1,n) >= 0 && (odd.query(n,n) == 0 || even.query(n,n) == 0)) return 1;

	return 0;
}

bool solve(ll n)
{
	ll now = 0;

	for(ll i = 1; i <= n; i++)
	{
		now = arr[i] - now;

		if(i & 1)
		{
			odd.update(i,i,now);
			even.update(i,i,1e15);
		}
		else
		{
			even.update(i,i,now);
			odd.update(i,i,1e15);
		}
	}

//	for(ll j = 1; j <= n; j++)
//		{
//			cout << "Initial : " << j << " = ";
//
//			if(j & 1) cout << odd.query(j,j) << "\n";
//			else cout << even.query(j,j) << "\n";
//		}
//

	if(soln(n)) return 1;

	for(ll i = 1; i < n; i++)
	{
		ll diff = arr[i + 1] - arr[i];

		if(i & 1)
		{
			odd.update(i,i,diff);
			even.update(i + 1, n, - 2 * diff);
			odd.update(i + 1, n, + 2 * diff);
		}
		else
		{
			even.update(i,i,diff);
			even.update(i + 1, n, 2 * diff);
			odd.update(i + 1, n, - 2 * diff);
		}

//		for(ll j = 1; j <= n; j++)
//		{
//			cout << i << ": " << j << " = ";
//
//			if(j & 1) cout << odd.query(j,j) << "\n";
//			else cout << even.query(j,j) << "\n";
//		}

		if(soln(n)) return 1;

		if(i & 1)
		{
			odd.update(i,i,-diff);
			even.update(i + 1, n, 2 * diff);
			odd.update(i + 1, n, - 2 * diff);
		}
		else
		{
			even.update(i,i,-diff);
			even.update(i + 1, n, - 2 * diff);
			odd.update(i + 1, n, 2 * diff);
		}
	}

	return 0;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


	fastio;
    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n;

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		for(ll i = 1; i <= n; i++)
		{
			odd.update(i,i,-odd.query(i,i));
			even.update(i,i,-even.query(i,i));
		}

		if(solve(n)) cout << "YES\n";
		else cout << "NO\n";
    }


}


