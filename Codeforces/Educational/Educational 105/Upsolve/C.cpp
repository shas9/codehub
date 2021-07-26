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

struct segTreemin
{
    ll n;
    vector<ll> tree, lazy;

    segTreemin(ll n): n(n), tree(4*n, 0), lazy(4*n, -1) {}

    void propagate(ll node, ll l, ll r)
    {
        if(lazy[node] != -1)
        {
			tree[node] = lazy[node];
			if(l != r) lazy[2*node] = lazy[node], lazy[2*node+1] = lazy[node];
        }
        lazy[node] = -1;
    }

    void treeUpdate(ll node, ll l, ll r, ll u, ll v, ll val)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return;
        if(l >= u && r <= v)
        {
//            cout << tree[node] << " YY " << tree[node - 1] << endl;

//			cout << "!!! " << node << endl;
            lazy[node] = val;
            propagate(node, l, r);

//            cout << tree[node] << " XX " << tree[node - 1] << endl;

            return;
        }

        treeUpdate(2*node, l, mid, u, v, val);
        treeUpdate(2*node+1, mid+1, r, u, v, val);

        tree[node] = min(tree[2*node], tree[2*node+1]);

//        cout << node << " : " << tree[node] << " = " << tree[2 * node] << " " << tree[2 * node + 1] << "\n";
    }
/**
10 6
10 10 10 6 6 5 5 5 3 1
1 3 10
2 2 36
**/
    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }

    ll treeQuery(ll node, ll l, ll r, ll val)
    {
//        cout << tree[node] << " + " << node << " " << l << " ~ " << r << "\n";

		if(tree[node] > val) return n + 1;
        ll mid = (l+r)>>1;


        propagate(node, l, r);

        if(l == r) return l;

//        cout << " ? " << tree[2 * node] << " " << tree[2 * node + 1] << endl;

        if(tree[2 * node] <= val) return treeQuery(2 * node, l, mid, val);

        return treeQuery(2 * node + 1, mid + 1, r, val);
    }

    ll query(ll val) { return treeQuery(1, 1, n, val); }
};

struct segTreesum
{
    ll n;
    vector<ll> tree, lazy;

    segTreesum(ll n): n(n), tree(4*n, 0), lazy(4*n, -1) {}

    void propagate(ll node, ll l, ll r)
    {
		if(lazy[node] != -1)
		{
			tree[node] = lazy[node] * (r - l + 1);
			if(l != r) lazy[2*node] = lazy[node], lazy[2*node+1] = lazy[node];
		}
        lazy[node] = -1;
    }

    void treeUpdate(ll node, ll l, ll r, ll u, ll v, ll val)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return;
        if(l >= u && r <= v)
        {
//			cout << node << " == ";
            lazy[node] = val;
            propagate(node, l, r);
//            cout << tree[node] << endl;

            return;
        }

        treeUpdate(2*node, l, mid, u, v, val);
        treeUpdate(2*node+1, mid+1, r, u, v, val);

        tree[node] = (tree[2*node] + tree[2*node+1]);
    }

    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
		ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return 0;
        if(l >= u && r <= v) return tree[node];

        return (treeQuery(2*node, l, mid, u, v) + treeQuery(2*node+1, mid+1, r, u, v));
    }

    ll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }

    ll treeQuery2(ll node, ll l, ll r, ll val)
    {
		ll mid = (l+r)>>1;

        propagate(node, l, r);

//        cout << node << ": " << l << " ~ " << r << " " << tree[node] << endl;

        if(l == r)
        {
			if(tree[node] <= val) return l;
			return l - 1;
        }

        if(tree[2 * node] >= val) return treeQuery2(2 * node, l, mid, val);

        return treeQuery2(2 * node + 1, mid + 1, r, val - tree[2 * node]);
    }

    ll query2(ll val) { return treeQuery2(1, 1, n, val); }
};

ll arr[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


//	fastio;
    while(cin >> n >> m)
    {
		segTreemin seg1(n);
		segTreesum seg2(n);

		for(ll i = 1; i <= n; i++)
		{
			cin >> arr[i];
			seg1.update(i,i,arr[i]);
			seg2.update(i,i,arr[i]);
		}

		for(ll i = 1; i <= m; i++)
		{
			ll t, x, y;

			cin >> t >> x >> y;

//			for(ll j = 1; j <= n; j++) cout << seg2.query(1,j) << " ";
//			cout << endl;

			if(t == 1)
			{
				ll pos = seg1.query(y);

				if(pos <= x)
				{
//					cout << "() " <<  pos << endl;
					seg1.update(pos, x, y);
					seg2.update(pos, x, y);
				}
			}
			else
			{
				ans = 0;

				while(y)
				{
					ll pos = seg1.query(y);

					pos = max(pos, x);


//					cout << pos << " : ";

					if(pos > n) break;

					ll tot = y;

					if(pos > 1) tot += seg2.query(1,pos - 1);

					ll ret = seg2.query2(tot);

					assert(seg2.query(1,ret) <= tot);

					ans += ret - pos + 1;

					y -= seg2.query(pos,ret);

//					cout << tot << " " << y << " " << ret << endl;

					x = ret + 1;

//					assert(y >= 0);

//					break;

				}

//				bug;

				cout << ans << "\n";
			}
		}
    }


}


