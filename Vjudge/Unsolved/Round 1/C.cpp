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

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }

    void treeUpdate(ll node, ll l, ll r, ll x)
    {
        ll mid = (l+r)>>1;

        propagate(node, x, x);

        if(l > x || r < x) return;

        if(l >= x && r <= x)
        {
            lazy[node] = 0;
            tree[node] = 0;

            return;
        }

        treeUpdate(2*node, l, mid, x);
        treeUpdate(2*node+1, mid+1, r, x);

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    void update1(ll x) { treeUpdate(1, 1, n, x); }


    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return 0;
        if(l >= u && r <= v) return tree[node];

        return max(treeQuery(2*node, l, mid, u, v), treeQuery(2*node+1, mid+1, r, u, v));
    }

    ll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }
};

ll arr[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		segTree seg2(n), seg3(n), seg5(n);

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		cin >> m;

		for(ll i = 1; i <= m; i++)
		{
			ll t;

			cin >> t;

			if(t == 2)
			{
				cin >> input;
				cin >> arr[input];

				seg2.update1(input);
				seg5.update1(input);
				seg3.update1(input);
			}
			else
			{
				cin >> l >> r >> k;

				if(k == 3) seg3.update(l,r,1);
				if(k == 2) seg2.update(l,r,1);
				if(k == 5) seg5.update(l,r,1);
			}
		}


		for(ll i = 1; i <= n; i++)
		{
			ll cnt2 = seg2.query(i,i);
			ll cnt3 = seg3.query(i,i);
			ll cnt5 = seg5.query(i,i);

			while(cnt2-- && (arr[i] % 2 == 0)) arr[i] /= 2;
			while(cnt3-- && (arr[i] % 3 == 0)) arr[i] /= 3;
			while(cnt5-- && (arr[i] % 5 == 0)) arr[i] /= 5;

			cout << arr[i] << " ";
		}

		cout << "\n";
    }


}


